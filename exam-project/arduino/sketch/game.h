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

int menu_prompt();

/*
This function starts a sequence prompting the
player if they wanna continue playing. Then it
waits for a "y" or "n" string input from the serial monitor
and returns true if input was y, false if n.
*/
bool continue_prompt();

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __GAME_H__
