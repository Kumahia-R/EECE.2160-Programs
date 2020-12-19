/**********************************************
    EECE.2160: ECE Application Programming
    UMass Lowell
    M. Geiger
    Function source file for integration assignment
    Tests ability to write and use functions
 ***********************************************/
 /*
 Richard Kumahia
 3/24/20
 EECE.2160: ECE Application Programming
 In this program, we will design functions that allow us to approximate the integral of a function, f(x), using the trapezoidal rule.
 */
#include <stdio.h>
#include <math.h>
#include "prog5_functions.h"

 // Calculate integral of f(x) over interval min to max, using n trapezoids
double integrate(double min, double max, int n) {
    double ySum = 0; //sum of all the y values in the integral
    double functionX = min; //value of x for the function
    double deltaX = (max - min) / n; //value of delta x based on the given formula
    for (int i = 0; i <= n; i++) { //for loop that goes through n number of trapezoids
        if (i == 0 || i == n) { //adds the y values of the endpoints
            ySum += f(functionX);
        }
        else {
            ySum += 2 * f(functionX); //adds the y values for every other point multiplied by two (because trapezoid formula)
        }
        functionX += deltaX; //increments the x value of the function by deltaX
    }
    double integral = (0.5 * deltaX * ySum); //calculates the integral based on the formula given
    return integral;
}

// f(x) as defined in the program specification
double f(double x) {
    return sin(x) + (x * x) / 10;
}

// Used to clear line if input formatting error occurs
void badInput() {
    char junk;
    do {
        scanf("%c", &junk);
    } while (junk != '\n');
}