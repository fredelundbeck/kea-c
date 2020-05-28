#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

String get_string_from_serial();

int get_int();

/*
Enters a loop until a number input is read from the serial. 
If that number input is in the given range (inclusive), it 
will return that number. Otherwise it will keep looping until such
a number has been read.

range: min ≤ x ≤ max == [min, max]

@param min: the lowest value in the range.
@param max: the highest value in the range.
@param err_msg: the message to be displayed if the captured value
does not lie in the range.
*/
int get_int_range_force(int min, int max, char* err_msg);

/*
Enters a loop until a HIGH (0x1) digital input is 
detected/read from given pin.

@param pin: The pin on the arduino the function will be reading from.
@param delay_ms: The delay in milliseconds each loop iteration.
*/
void wait_for_btn_push(uint8_t pin, unsigned long delay_ms);

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __UTILS_H__
