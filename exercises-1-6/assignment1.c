/*
Assignment text:
Try to make a program.

You buy 41112 Lego blocks with a price of kr. 11,48 without moms.
Make an invoice, where all the numbers are nice lined up under each other.
Number.
Price each without moms.
Total cost without moms.
Moms.
Total price all inclusive (moms is a tax of 25%).
*/

#include <stdio.h>

const int LEGO_BLOCKS_AMOUNT = 41112;
const float COST_PER_BLOCK = 11.48f;
const float VAT_PERCENT = 1.25f;

int main(void)
{
    //yikes
    printf("\nLEGO INVOICE\n\n"
           "QTY\tDESCRIPTION\t\tUNIT PRICE\tAMOUNT\n"
           "---------------------------------------------------------\n"
           "1\tNormal lego brick\t%.2f$\t\t%d\n\n"
           "\t\t\t\tSub total\t%.2f\n"
           "\t\t\t\tTax percent\t25%%\n"
           "\t\t\t\tTOTAL\t\t$%.2f\n",
           COST_PER_BLOCK, 
           LEGO_BLOCKS_AMOUNT, 
           (LEGO_BLOCKS_AMOUNT * COST_PER_BLOCK),
           (LEGO_BLOCKS_AMOUNT * COST_PER_BLOCK * VAT_PERCENT));

    return 0;
}

/*
Outputs:

LEGO INVOICE

QTY     DESCRIPTION             UNIT PRICE      AMOUNT
---------------------------------------------------------
1       Normal lego brick       11.48$          41112

                                Sub total       471965.75
                                Tax percent     25%
                                TOTAL           $589957.19
*/
