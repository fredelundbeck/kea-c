/*
Assignment text:
Try to make a program where you enter data from the keyboard with the command scanf().
*/

#include <stdio.h>

int main(void)
{
    char input[255];

    // 255 -> tells scanf to only accept 255 characters.  
    // [0-9a-zA-Z ] -> tells scanf to only accept characters that match this regex.
    scanf("%255[0-9a-zA-Z ]", input);

    printf("%s", input);
    return 0;
}

/*
Input: 
Hello, World

Output: 
Hello, World
*/