/*
Assignment text:
Make a program where you input a character;
If the character is an “a” or “A” the program will printout “Apple”;
If the character is an “b” or “B” the program will printout “Banana”;
If the character is an “c” or “C” the program will printout “Cherry”;
If the character is an “d” or “D” the program will printout “Date”;
If the character is an “e” or “E” the program will printout “Elderberry”;
Otherwise the program will answer “I don’t know any fruit with a ” the entered letter.
Use if-else.
*/

#include <stdio.h>
#include <ctype.h>

void print_fruit(char c);

int main(void)
{

    print_fruit('A');
    print_fruit('X');

    return 0;
}

void print_fruit(char c)
{
    if (toupper(c) == 'A')
    {
        printf("Apple\n");
    }
    else if (toupper(c) == 'B')
    {
        printf("Banana\n");
    }
    else if (toupper(c) == 'C')
    {
        printf("Cherry\n");
    }
    else if (toupper(c) == 'D')
    {
        printf("Date\n");
    }
    else if (toupper(c) == 'E')
    {
        printf("Elderberry\n");
    }
    else
    {
        printf("I don't know any fruit with a %c\n", c);
    }
}

/*
Output:
Apple
I don't know any fruit with a X
*/