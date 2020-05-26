#ifndef __SLOTMACHINE_H__
#define __SLOTMACHINE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct slotmachine
{
    int age;
    int max;
} slotmachine_t;

slotmachine_t* create_slotmachine();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __SLOTMACHINE_H__
