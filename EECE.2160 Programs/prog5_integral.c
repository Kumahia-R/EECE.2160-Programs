/**********************************************
    EECE.2160: ECE Application Programming
    UMass Lowell
    M. Geiger
    Main program for integration assignment
    Tests ability to write and use functions
***********************************************/
/*
Richard Kumahia
3/24/20
EECE.2160: ECE Application Programming
In this program, we will design functions that allow us to approximate the integral of a function, f(x), using the trapezoidal rule.
*/
#include <stdio.h>
#include "prog5_functions.h"

int main() {
    double low, hi; //low and high points of interval
    int numTraps; //number af Trapezoids used in the integration
    int cont; //determines whether to continue integrating
    char another; //character that is either 'Y', 'y','N' or'n' that determines if the code should continue integrating
    int valCorrect; //determines if the scanF functions had valid inputs
    int askAgain; //flag integer for if there's an error when asking the user if they want to continue integrating
    do { //loop that's loops the entire code until the user inputs 'N' or 'n'
        do { //loop that keeps asking for the endpoints until the inputs are valid
            printf("Enter endpoints of interval to be integrated (low hi): ");
            valCorrect = scanf("%lf %lf", &low, &hi);
            /*if-else statements to determine that both inputs are valid for the code.
            sets askAgain to 1 if one of the errors occurs*/
            if (valCorrect != 2) { //checks if low and hi are both doubles
                printf("Error: Improperly formatted input\n");
                badInput(); //clears line when there's an error
                askAgain = 1;
            }
            else if (hi < low) { //checks if low is greater than high
                printf("Error: low must be < hi\n");
                badInput();
                askAgain = 1;
            }
            else {
                askAgain = 0;
            }
        } while (askAgain == 1);
        do { //loop that keeps asking for the number of Trapezoids used until the input is valid
            printf("\nEnter number of trapezoids to be used: ");
            valCorrect = scanf("%d", &numTraps);
            /*if-else statements to determine that the input is valid for the code.
            sets askAgain to 1 if one of the errors occurs*/
            if (valCorrect != 1) { //checks if the input is an int
                printf("Error: Improperly formatted input\n");
                badInput();
                askAgain = 1;
            }
            else if (numTraps < 1) { //checks if the input is greater than 1
                printf("Error: numT must be >= 1 \n");
                badInput();
                askAgain = 1;
            }
            else {
                askAgain = 0;
            }
        } while (askAgain == 1);
        printf("\nUsing %d trapezoids, integral between %lf and %lf is %lf", numTraps, low, hi, integrate(low, hi, numTraps));
        do {
            printf("\nEvaluate another interval (Y/N)?");
            scanf(" %c", &another); //reads user input
            //if else statements determining what to do based on the user's input
            if (another == 'Y' || another == 'y') {
                askAgain = 0;
                cont = 1;
            }
            else if (another == 'N' || another == 'n') {
                askAgain = 0;
                cont = 0;
            }
            else { //assumes the input character wasn't one of the requested characters
                askAgain = 1;
            }
            if (askAgain == 1) {
                badInput();
                printf("Error: must enter Y or N");
            }
        } while (askAgain == 1);
    } while (cont == 1);
}