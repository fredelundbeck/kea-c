#include <Arduino.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"
#include "ardsetup.h"
#include "slotmachine.h"
#include "session.h"

#define SPIN_LENGTH_MS 1000

session_t *session;
slotmachine_t *slotmachine;

bool start_prompt()
{   
    //Prompt the welcome screen.
    Serial.println(F(":: 𝗢𝗡𝗘 𝗔𝗥𝗠𝗘𝗗 𝗕𝗔𝗡𝗗𝗜𝗧 (𝗔𝗥𝗗𝗨𝗜𝗡𝗢 𝗘𝗗𝗜𝗧𝗜𝗢𝗡) 🍒🍒🍒 ::\n\
Version 1.0.0\n\n\
Press [button] to continue...\n"));
    
    //Wait for button push before continuing.
    wait_for_btn_push(BTN_PIN, 50);

    //Display the menu prompt and get operation code
    int menu_op = menu_prompt();

    //If user choose exit_op return now
    if (menu_op == 3)
    {
        Serial.println(F("[✔] Goodbye!"));
        return;
    }
    
    //Ask the user how many USD they wanna convert to credits.
    Serial.println(F("\n[❓] How many USD do you wanna convert to credits?"));

    //Force integer input from serial
    uint16_t usd = get_int_range_force(1, 200, 
    "[✖] Whoops, you need to input an integer value between [1, 200]");

    //Prompt the USD to credit conversion
    Serial.print(F("[✔] "));
    Serial.print(usd);
    Serial.print(F("$ is "));
    Serial.print(usd * STD_USD_CRED_CNV);
    Serial.print(F(" credits, enjoy!\n\n"));

    //Initialize session & slotmachine
    session = create_session(usd * STD_USD_CRED_CNV);
    slotmachine = create_default_slotmachine();

    //If button mode has been chosen return true
    return menu_op == 1 ? true : false;
}

int menu_prompt()
{   
    //Display menu text
    Serial.println(F("░▒▓█ 𝗚𝗔𝗠𝗘 𝗠𝗘𝗡𝗨 █▓▒░\n\
[𝟭] Play with button mode\n\
[𝟮] Play with auto spin\n\
[𝟯] Exit\n"));

    //Get menu operation and return it
    return get_int_range_force(1, 3, "[✖] You need to choose one of the options!");
}

void spin_loop(bool button_mode)
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
            Serial.println(F("[🍒] Press button to spin wheels!\n"));

            //Wait for button click before continuing
            wait_for_btn_push(BTN_PIN, 50);
        }
        //Simulate slotmachine delay
        delay(100);

        //For each wheel in slotmachine
        for (size_t i = 0; i < MAX_WHEELS; i++)
        {
            //Spin wheel
            spin_wheel(slotmachine->wheels[i]);

            //Simulate with time delay
            delay(200);
            Serial.print(get_symbol_name(slotmachine->wheels[i]->current_symbol));
            Serial.print(F(" "));
        }

        //Print two newlines after spins
        Serial.println(F("\n"));

        /*
        Check for any winnings.
        Iterate through the slotmachine combinations backwards so that
        we stop at the first and most valuable combination hit.
        */
        bool hit = false;
        for (short i = slotmachine->rules_size - 1; i >= 0; i--)
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

                //Check if biggest win yet. If it is then update session
                if (session->biggest_win < slotmachine->rules[i].price)
                {
                    session->biggest_win = slotmachine->rules[i].price;
                }
                
                
                //Reset loss streak & increment winning streak
                current_loss_streak = 0;
                current_win_streak += 1;

                //Check if current win streak is longer than session win streak
                if (current_win_streak > session->longest_win_streak)
                {
                    //Then assign session win streak to current win streak
                    session->longest_win_streak = current_win_streak;
                }

                //Prompt player about the winning
                Serial.print(F("[💲] You won "));
                Serial.print(slotmachine->rules[i].price);
                Serial.print(F(" credits.\n\n"));

                //If mode is auto spin give the player a chance to read winnings
                if (!button_mode)
                {
                    delay(1500);
                }
                break;
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
    }

    //Prompt player that the game has ended and show session statistics
    Serial.println(F("[🍒] You're out of credits! Here's your session statistics:\n"));

    delay(1000);

    Serial.print(F(":: 𝗚𝗔𝗠𝗘 𝗦𝗘𝗦𝗦𝗜𝗢𝗡 𝗦𝗧𝗔𝗧𝗜𝗦𝗧𝗜𝗖𝗦 ::\n"));

    //Total spins
    Serial.print(F("Total spins:\t\t\t"));
    Serial.print(session->spins_total);
    Serial.println();

    //Longest win streak
    Serial.print(F("Longest win streak:\t\t"));
    Serial.print(session->longest_win_streak);
    Serial.println();

    //Longest loss streak
    Serial.print(F("Longest loss streak:\t"));
    Serial.print(session->longest_loss_streak);
    Serial.println();

    //Biggest winning
    Serial.print(F("Biggest winning:\t\t"));
    Serial.print(session->biggest_win);
    Serial.print(F(" credits\n"));

    //Grapes bonus hits
    Serial.print(F("Triple grapes hits:\t\t"));
    Serial.print(session->grapes_bonus_hits);
    Serial.println();

    delay(1000);
}

bool continue_prompt()
{
    //Ask player if they want to continue game
    Serial.println(F("\n[❓] Do you wanna continue playing? y/n"));

    //Retrieve a yes/no answer from player
    bool answer = get_yes_no_answer_force("[✖] You need to answer y/n");

    //If answer was yes
    if (answer == true)
    {
        //Ask player how much money they wanna put in
        Serial.println(F("\n[❓] How many USD do you wanna convert to credits?\n"));

        //Force integer input from serial
        uint16_t usd = get_int_range_force(1, 200, 
        "[✖] Whoops, you need to input an integer value between [1, 200]");

        //Reset game session for next spin loop
        session->credits = usd * STD_USD_CRED_CNV;
        session->spins_total = 0;
        session->biggest_win = 0;
        session->longest_win_streak = 0;
        session->longest_loss_streak = 0;
        session->grapes_bonus_hits = 0;

        return true;
    }

    Serial.println(F("[🍒] Thanks for playing!"));

    //Else return false
    return false;
}

