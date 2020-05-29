#include <Arduino.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"
#include "ardsetup.h"
#include "slotmachine.h"
#include "session.h"

#define MAX_AUTO_SPINS 100
#define SPIN_LENGTH_MS 1000

session_t *session;
slotmachine_t *slotmachine;

void start_prompt()
{   
    //Prompt the welcome screen.
    Serial.println(":: 𝗢𝗡𝗘 𝗔𝗥𝗠𝗘𝗗 𝗕𝗔𝗡𝗗𝗜𝗧 (𝗔𝗥𝗗𝗨𝗜𝗡𝗢 𝗘𝗗𝗜𝗧𝗜𝗢𝗡) 🍒🍒🍒 ::\n\
Version 1.0.0\n\n\
Press [button] to continue...\n");
    
    //Wait for button push before continuing.
    wait_for_btn_push(BTN_PIN, 50);

    //Display the menu prompt and get operation code
    int menu_op = menu_prompt();

    //If user choose exit_op return now
    if (menu_op == 3)
    {
        Serial.println("[✔] Goodbye!");
        return;
    }
    
    //Ask the user how many USD they wanna convert to credits.
    Serial.println("\n[❓] How many USD do you wanna convert to credits?");

    //Force integer input from serial
    uint16_t usd = get_int_range_force(1, 200, 
    "[✖] Whoops, you need to input an integer value between [1, 200]");

    //Prompt the USD to credit conversion
    Serial.print("[✔] ");
    Serial.print(usd);
    Serial.print("$ is ");
    Serial.print(usd * STD_USD_CRED_CNV);
    Serial.print(" credits, enjoy!\n");

    //Initialize session & slotmachine
    session = create_session(usd * STD_USD_CRED_CNV);
    slotmachine = create_default_slotmachine();

    //Start the game 
    start_game_loop(menu_op == 1 ? true : false);
}

int menu_prompt()
{   
    //Display menu text
    Serial.println("░▒▓█ 𝗚𝗔𝗠𝗘 𝗠𝗘𝗡𝗨 █▓▒░\n\
[𝟭] Play with button mode\n\
[𝟮] Play with auto spin\n\
[𝟯] Exit\n");

    //Get menu operation and return it
    return get_int_range_force(1, 3, "[✖] You need to choose one of the options!");
}


bool continue_prompt()
{

}

void start_game_loop(bool button_mode)
{
     unsigned short current_win_streak = 0;
     unsigned short current_loss_streak = 0;

    //While user has enough credits to keep spinning
    while (session->credits >= slotmachine->config.spin_credit_price)
    {
        //Increment session spins total
        session->spins_total += 1;

        //If user chose button mode
        if (button_mode)
        {
            //Prompt user to press button
            Serial.println("[🍒] Press button to spin wheels!");

            //Wait for button click before continuing
            wait_for_btn_push(BTN_PIN, 50);
            delay(100);
        }

        //For each wheel in slotmachine
        for (size_t i = 0; i < MAX_WHEELS; i++)
        {
            //Spin wheel
            spin_wheel(slotmachine->wheels[i]);
        }

        /*
        Check for any winnings.
        Iterate through the slotmachine combinations backwards so that
        we stop at the first and most valuable combination hit.
        */
        bool hit = false;
        for (unsigned char i = slotmachine->rules_size; i > 0; i--)
        {
            /*
            Check if each wheel's current symbol is equal to rules[i] symbols or if the symbol is -1 (wildcard) 
            Kinda hacky to look at but gets the job done. With more time we could probably implement a better solution.
            */
            if ((slotmachine->wheels[0]->current_symbol == slotmachine->rules[i].symbols[0] || slotmachine->rules[i].symbols[0] == -1) &&
                (slotmachine->wheels[1]->current_symbol == slotmachine->rules[i].symbols[1] || slotmachine->rules[i].symbols[1] == -1) &&
                (slotmachine->wheels[2]->current_symbol == slotmachine->rules[i].symbols[2] || slotmachine->rules[i].symbols[2] == -1))
            {
                //Set hit bool to true
                hit = true;

                //Increment credits by the winning amount & break out of loop
                session->credits += slotmachine->rules[i].price;
                
                //Reset loss streak & increment winning streak
                current_loss_streak = 0;
                current_win_streak += 1;

                //Check if current win streak is longer than session win streak
                if (current_win_streak > session->longest_win_streak)
                {
                    //Then assign session win streak to current win streak
                    session->longest_win_streak = current_win_streak;
                }
                
            }
            
        }
        //Check if hit is still false
        if (!hit)
        {
            //Increment current loss streak & reset current win streak
            current_loss_streak += 1;
            current_win_streak = 0;

            //Check if current loss streak is longer than session loss streak
            if (current_loss_streak > session->longest_loss_streak)
            {
                //Update session loss streak
                session->longest_loss_streak = current_loss_streak;
            }
        }
        
        
        
        //Decrement credits by spin price
        session->credits -= slotmachine->config.spin_credit_price;

        //If session total spins has reached MAX_AUTO_SPIN
        if (session->spins_total % MAX_AUTO_SPINS == 0)
        {
            Serial.print("[❓] You have spinned ");
            Serial.print(MAX_AUTO_SPINS);
            Serial.println(" times. Continue? y/n");
            break;
        }        
    }
}

