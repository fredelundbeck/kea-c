/*

PLEASE READ BEFORE RUNNING THIS ON YOUR ARDUINO!

Here's some prerequisites to run this on your arduino as intended:

HARDWARE PREREQUISITES:

1. An Arduino UNO. We do not recommend trying this on anything else than 
the UNO, as we haven't yet tested the program on other microcontrollers.

2. Make sure you have a breadboard with a button circuit connected to
your arduino uno (as it is required in order to play), it should be 
connected with a jumper wire to pin 13.

Full details of the circuit schematics can be found in the .pdf file
in the doc folder.

SOFTWARE PREREQUISITES:

You should only use this program through the serial monitor provided
by the arduino IDE and not other terminals that support serial connections
like PuTTY etc.

Your arduino IDE serial monitor should also have the following settings:

Autoscroll:     ON
Show timestamp: OFF
Input:          No line ending
Baud:           9600


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

