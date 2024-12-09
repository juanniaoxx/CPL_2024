#include <stdio.h>

int main(void) {

    int first, second, thired;
    printf("Enter phone number [(xxx) xxx-xxxx]:");
    scanf("(%d) %d-%d", &first, &second, &thired);
    printf("You entered %d.%d.%d\n", first, second, thired);
    return 0;
}