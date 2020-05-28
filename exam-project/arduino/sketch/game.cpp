#include <Arduino.h>
#include "game.h"
#include "utils.h"

void start_prompt()
{   
    //Prompt the welcome screen.
    Serial.println(":: ONE ARMED BANDIT (ARDUINO EDITION) 🍒🍒🍒 ::\n\
Version 1.0.0\n\n\
Press [button] to continue...\n");
    
    //Wait for button push before continuing.
    wait_for_btn_push(9, 50);

    //Ask the user how many USD they wanna convert to credits.
    Serial.println("\n\nHow many USD do you wanna convert to credits?");

    //Get int from serial monitor.
    int usd = get_int_from_serial(); 

    Serial.print("You answer was ");
    Serial.print(usd);
    Serial.println(" $");

    
}


bool continue_prompt()
{

}

