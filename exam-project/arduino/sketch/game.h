#ifndef __GAME_H__
#define __GAME_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
This function starts a sequence of events
regarding welcoming the player. First it
prompts a welcome screen, then it asks for
input to setup the game with.
*/
void start_prompt();

/*
This function starts the menu sequence. 
First it prompts the menu options and then
it forces a valid number input (choice) from player.

Returns the valid number input.
*/
int menu_prompt();

/*
This function starts a sequence prompting the
player if they wanna continue playing. Then it
waits for a "y" or "n" string input from the serial monitor
and returns true if input was y, false if n.
*/
bool continue_prompt();

/*
This function starts the main game loop.
*/
void start_game_loop(bool button_mode);

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __GAME_H__
