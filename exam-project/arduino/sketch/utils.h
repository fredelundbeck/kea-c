#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

String get_string_from_serial();

int get_int_from_serial();

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
