#include "game.h"
#include "utils.h"

void setup()
{
  //Setup bit rate 
  Serial.begin(9600);
  
  // display_start_prompt();
  start_game_prompt(); 
}

void loop()
{
  delay(500);
}

void start_game_prompt() 
{
  Serial.println(":: ONE ARMED BANDIT (ARDUINO EDITION) ::");
  Serial.println("Version 1.0.0\n\n");

  Serial.println("Press button to continue...");

  wait_for_btn_push(9, 50);

  //Ask the user how many USD they wanna convert to credits.
  Serial.println("\n\nHow many USD do you wanna convert to credits?");

  //Get int from serial monitor.
  int usd = get_int_from_serial(); 

  Serial.print("You answer was ");
  Serial.print(usd);
  Serial.println(" $");
}

