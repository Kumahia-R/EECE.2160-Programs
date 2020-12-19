#include <stdio.h>
/*
Richard Kumahia
EECE.2160 Section 202
2/10/20
In this assignment, we will work with C conditional statements to implement a simple Boolean calculator program.
This program will also introduce us to Boolean operators, which we will explore in much more detail later this semester.
*/
int main() {
    unsigned boolA, boolB; /*initializes the operands*/
    char boolOperate; /*initializes the boolean operator*/
    unsigned boolSol; /*initializes the solution*/
    printf("Enter Boolean expression: ");
    // Checks if all input variables were read correctly and prints an error message if not
    int valCorrect = scanf("%u %c %u", &boolA, &boolOperate, &boolB);
    if (valCorrect != 3) {
        printf("Error: %d values entered correctly", valCorrect);
    }
    else {
        // Checks if the operands are greater than 1 and prints an error message if they are
        if (boolA > 1) {
            printf("Error: first input (%u) requires > 1 bit ", boolA);
        }
        if (boolB > 1) {
            printf("Error: second input (%u) requires > 1 bit ", boolB);
        }
        // prints the entire operation based on the value of boolOperate
        if (boolOperate == '&') {
            boolSol = boolA & boolB;
            printf("%u %c %u = %u", boolA, boolOperate, boolB, boolSol);
        }
        else if (boolOperate == '|') {
            boolSol = boolA | boolB;
            printf("%u %c %u = %u", boolA, boolOperate, boolB, boolSol);
        }
        else if (boolOperate == '^') {
            boolSol = boolA ^ boolB;
            printf("%u %c %u = %u", boolA, boolOperate, boolB, boolSol);
        }
        //Assumes the operator isn't valid after the previous if-else statements so a statement is printed to show that
        else {
            printf("Error: invalid operator %c ", boolOperate);
        }
    }
}