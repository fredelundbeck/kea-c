#ifndef __SESSION_H__
#define __SESSION_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct session
{
    int credits;
    int spins_total;
    int longest_win_streak;
    int longest_loss_streak;
    int plum_bonusses_hit;
} session_t;

session_t* create_session(int credits);

#ifdef __cplusplus
} //extern C
#endif

#endif // __SESSION_H__
