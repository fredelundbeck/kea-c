#include "utils.h"

void setup()
{
  //Setup bit rate 
  Serial.begin(9600);

  start_game_prompt();
}

void loop()
{
  delay(500);
}

void start_game_prompt() 
{
  //Ask the user how many USD they wanna convert to credits.
  Serial.println("How many USD do you wanna convert to credits?");

  //Get int from serial monitor.
  int usd = get_int_from_serial(); 

  Serial.print("You answer was ");
  Serial.print(usd);
  Serial.println(" $");

}

