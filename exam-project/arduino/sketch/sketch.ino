/*

PLEASE READ BEFORE RUNNING THIS ON YOUR ARDUINO!

Here's some prerequisites to run this on your arduino as intended:

Make sure you have a breadboard with a button circuit connected to
your arduino (as it is required in order to play), it should be connected with 
a jumper wire to pin 13.

Full details of the circuit schematics can be found in the .pdf file
in the doc folder.

*/

#include "game.h"
#include "utils.h"
#include "ardsetup.h"

void setup()
{
  //Setup baud & pins
  setup_arduino();

  //Start the main prompt & return game mode
  bool mode = start_prompt();

  //Enter main game loop
  while (true)
  {
    //Start spin loop
    spin_loop(mode);

    //If player doesn't want to continue
    if (!continue_prompt())
    {
      //Break out of main game loop
      break;
    }
  }
}

void loop()
{

}

