#include <stdio.h>

int main(void) {

    int item_number, year, month, day;
    double unit_price;
    
    //format input

    printf("Enter item number:");
    scanf("%d", &item_number);
    printf("\n");
    
    printf("Enter unit price:");
    scanf("%lf", &unit_price);
    printf("\n");

    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("\n");

    
    //format output
    printf("Item\tUnit\t\tPurchase\n");
    printf("    \tPrice\t\tDate    \n");
    printf("%-4d\t$%6.2lf\t\t%02d/%02d/%d\n", 
            item_number, unit_price, month, day, year);

    return 0;
}