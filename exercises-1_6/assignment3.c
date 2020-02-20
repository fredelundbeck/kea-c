/*
Assignment text: 
There are other input metodes, try them.
    gets(), getchar().
    char character;
    char name[20];
    gets(name);
    character = getchar();
*/

#include <stdio.h>

int main(void)
{
    char msg[256];
    char c;

    c = getchar();
    gets(msg);

    printf("Character: %c, String: %s", c, msg);
    return 0;
}

/*
Input:
cTest

Output:
Character: c, String: Test
*/