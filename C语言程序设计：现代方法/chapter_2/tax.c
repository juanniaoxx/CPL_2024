#include <stdio.h>

int main(void) {
    double money = 0.0;
    
    printf("Enter an amount:");
    scanf("%lf", &money);
    printf("\n");
    printf("With tax added: $%.2lf\n", money * 1.05);

    return 0;
}