/*
NAME: Kiptui Kipyator 
REG NO: PA106/G/28740/25
Date: 3rd November 2025
*/

#include <stdio.h>

int main() {
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };
    
    // Printing elements
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n"); // move to next row
    }
    
    return 0;
}