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

