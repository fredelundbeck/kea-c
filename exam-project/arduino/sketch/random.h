#ifndef __RANDOM_H__
#define __RANDOM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
Returns a psuedo random number between min and max argument. (inclusive in both ends)
min ≤ x ≤ max == [min, max]
*/
int get_random_int(int min, int max);

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __RANDOM_H__
