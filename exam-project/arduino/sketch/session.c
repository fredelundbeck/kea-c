#include <stdlib.h>
#include "session.h"

session_t* create_session(int credits)
{   
    /* 
    Allocate dynamic memory for the session struct.
    */
    session_t* session = malloc(sizeof(session_t));

    //Check if we're out of memory
    if (session == NULL)
    {
        return NULL;
    }

    //Assign variables
    session->credits = credits;
    session->spins_total = 0;
    session->longest_win_streak = 0;
    session->longest_loss_streak = 0;
    session->plum_bonusses_hit = 0;
    
    return session;
}