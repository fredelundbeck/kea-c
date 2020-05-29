#ifndef __SESSION_H__
#define __SESSION_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct session
{
    unsigned int credits;
    unsigned int spins_total;
    unsigned short longest_win_streak;
    unsigned short longest_loss_streak;
    unsigned char plum_bonusses_hit;
} session_t;

session_t *create_session(int credits);

#ifdef __cplusplus
} //extern C
#endif

#endif // __SESSION_H__
