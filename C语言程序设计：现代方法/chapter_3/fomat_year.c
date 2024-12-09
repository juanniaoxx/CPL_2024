#include <stdio.h>

/* input mm/dd/yy output yy/mm/dd */
int main(void) {

    int year, month, day;
    
    printf("Enter a date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("\n");
    printf("You entered the date %d%02d%02d\n", year, month, day); //自动补充0
    return 0;
}