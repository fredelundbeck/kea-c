#include <stdlib.h>
#include <stdint.h>
#include "session.h"

session_t *create_session(unsigned short credits)
{   
    /* 
    Allocate dynamic memory for the session struct.
    */
    session_t *session = malloc(sizeof(session_t));

    //Check if we're out of memory
    if (session == NULL)
    {
        return NULL;
    }

    //Assign variables
    session->credits = credits;
    session->spins_total = 0;
    session->biggest_win = 0;
    session->longest_win_streak = 0;
    session->longest_loss_streak = 0;
    session->grapes_bonus_hits = 0;
    
    return session;
}