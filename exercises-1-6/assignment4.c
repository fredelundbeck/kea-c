/*
int dage[] ={31,28,31,30,31,30,31,31,30,31,30,31}
Make a program with a ”for loop” to make the printout.
Month nr. 1 contains 31 days
Month nr. 2 contains 28 days and so on.
*/

#include <stdio.h>

int main()
{
    char months_names[12][3] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
                                 
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < sizeof(days_in_month) / sizeof(int); i++)
    {
        printf("%.3s: %d\n",months_names[i], days_in_month[i]);
    }
    
}

/*
Output:

Jan: 31
Feb: 28
Mar: 31
Apr: 30
May: 31
Jun: 30
Jul: 31
Aug: 31
Sep: 30
Oct: 31
Nov: 30
Dec: 31

*/