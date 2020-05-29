#ifndef __SESSION_H__
#define __SESSION_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct session
{
    unsigned short credits;
    unsigned short spins_total;
    unsigned char biggest_win;
    unsigned short longest_win_streak;
    unsigned short longest_loss_streak;
    unsigned char grapes_bonus_hits;
} session_t;

session_t *create_session(unsigned short credits);

#ifdef __cplusplus
} //extern C
#endif

#endif // __SESSION_H__
