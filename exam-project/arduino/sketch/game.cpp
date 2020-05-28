#include <Arduino.h>
#include <stdlib.h>
#include "game.h"
#include "utils.h"
#include "ardsetup.h"
#include "slotmachine.h"
#include "session.h"

#define SPIN_LENGTH_MS 1000;

session_t* session;
slotmachine_t* slotmachine;

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
    session = create_session(usd);
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
    //While user has enough credits to keep spinning
    while (session->credits >= slotmachine->config.spin_credit_price)
    {
        //If user chose button mode
        if (button_mode)
        {
            //Wait for button click before continuing
            wait_for_btn_push(BTN_PIN, 50);
        }

        //For each wheel in slotmachine
        for (size_t i = 0; i < MAX_WHEELS; i++)
        {
            //Spin wheel
            spin_wheel(slotmachine->wheels[i]);
        }
        

        //Decrement credits by spin price
        session->credits -= slotmachine->config.spin_credit_price;
    }
    
}

