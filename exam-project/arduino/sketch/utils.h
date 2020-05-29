#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

String get_string_from_serial();

bool get_yes_no_answer_force(char *err_msg);

/*
Enters a loop until a serial input has been captured.
Returns the parsed serial input. If input is not an integer
0 will be returned.
*/
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
int get_int_range_force(int min, int max, char *err_msg);

/*
Enters a loop until a HIGH (0x1) digital input is 
detected/read from given pin.

@param pin: The pin on the arduino the function will be reading from.
@param delay_ms: The delay in milliseconds each loop iteration.
*/
void wait_for_btn_push(uint8_t pin, unsigned long delay_ms);

/*
Turns on the red led.
*/
void led_red_on();

/*
Turns on the yellow led.
*/
void led_ylw_on();

/*
Turns on the green led.
*/
void led_grn_on();

/*
Turns off the red led.
*/
void led_red_off();

/*
Turns off the yellow led.
*/
void led_ylw_off();

/*
Turns off the green led.
*/
void led_grn_off();

#ifdef __cplusplus
} //extern "C"
#endif

#endif // __UTILS_H__
