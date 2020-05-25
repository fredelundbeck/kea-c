#ifndef __SLOTMACHINE_H__
#define __SLOTMACHINE_H__

typedef enum symbol 
{
    APPLE,
    BAR
    BELL,
    CHERRY,
    GRAPE,
    LEMON,
    ORANGE,
    PLUM,
};

typedef struct slotmachine
{
    wheel_t wheels[3];
} slotmachine_t;

typedef struct wheel
{
    /* data */
} wheel_t;


#endif // __SLOTMACHINE_H__