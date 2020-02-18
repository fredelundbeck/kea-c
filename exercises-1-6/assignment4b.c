/*
Make a new program and use at this time a ”do-while loop”
*/

#include <stdio.h>

int main()
{
    char months_names[12][3] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
                                 
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int i = 0;
    do
    {
        printf("%.3s: %d\n",months_names[i], days_in_month[i]);
        i++;
    }
    while (i < sizeof(days_in_month) / sizeof(int));
  
    return 0;
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