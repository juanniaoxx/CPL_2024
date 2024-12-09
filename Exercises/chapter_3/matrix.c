#include <stdio.h>

int main(void) {

    printf("Enter the numbers from 1 to 16 in any order:");
    int matrix[4][4];
    int Row_sums[4] = {0, 0, 0, 0};
    int Column_sums[4] = {0, 0, 0, 0};
    int Diagonal_sums[2] = {0, 0};
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            scanf("%d",&matrix[i][j]);
            Row_sums[i] += matrix[i][j];
        }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++)
            Column_sums[j] += matrix[i][j];
    }

    Diagonal_sums[0] = matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3];
    Diagonal_sums[1] = matrix[3][0] + matrix[2][1] + matrix[1][2] + matrix[0][3];

    printf("Row sums:");
    for (int i = 0;i < 4; i++) printf("%d ", Row_sums[i]);
    printf("\n");
    printf("Column sums:");
    for (int i = 0;i < 4; i++) printf("%d ", Column_sums[i]);
    printf("\n");
    printf("Diagonal sums:");
    for (int i = 0;i < 2; i++) printf("%d ", Diagonal_sums[i]);
    printf("\n");
    return 0;
}