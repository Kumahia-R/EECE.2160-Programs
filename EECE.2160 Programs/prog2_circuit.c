#include <stdio.h>
/*
Richard Kumahia
EECE.2160 Section 202
1/29/20
This assignment will give yus some experience working with C input
(using scanf()) and output (using printf()), as well as arithmetic operations with variables.
We will do some very basic circuit analysis, reading the values of a voltage source
and three resistors, and calculating the voltage across and current through each of the resistors
using three different circuit configurations.
*/
int main() {
    double Vsource; /* Voltage of the voltage source in Volts*/
    double R1; /* Resistance of Resistor 1 in Ohms */
    double R2; /* Resistance of Resistor 2 in Ohms */
    double R3; /* Resistance of Resistor 3 in Ohms */
    //Input
    printf("Enter voltage source value (V): ");
    scanf("%lf", &Vsource);
    printf("\nEnter three resistance values (ohms): ");
    scanf("%lf %lf %lf", &R1, &R2, &R3);
    // Series circuit output 
    printf("SERIES CIRCUIT\n");
    double seriesCurrent = Vsource / (R1 + R2 + R3); /* Calculates current of Series Circuit */
    printf("Current through circuit: %lf A\n", seriesCurrent);
    // Calculates the voltages of each resistor using Ohm's Law
    double voltR1 = seriesCurrent * R1; /* Voltage of Resistor 1 */
    double voltR2 = seriesCurrent * R2; /* Voltage of Resistor 2 */
    double voltR3 = seriesCurrent * R3; /* Voltage of Resistor 3 */
    printf("Voltage across R1: %lf V\n", voltR1);
    printf("Voltage across R2: %lf V\n", voltR2);
    printf("Voltage across R3: %lf V\n\n", voltR3);
    // Parallel circuit output
    printf("PARALLEL CIRCUIT\n");
    double voltParallel = Vsource; /* Voltage of all parallel elements */
    printf("Voltage across each resistor: %lf V\n", voltParallel);
    // calculates the current through each resistor using Ohm's Law
    double ampR1 = Vsource / R1; /* Current through Resistor 1 in Amps */
    double ampR2 = Vsource / R2; /* Current through Resistor 2 in Amps */
    double ampR3 = Vsource / R3; /* Current through Resistor 3 in Amps */
    printf("Current through R1: %lf A\n", ampR1);
    printf("Current through R2: %lf A \n", ampR2);
    printf("Current through R3: %lf A\n\n", ampR3);
    // Series Parallel circuit output
    printf("R2 & R3 IN PARALLEL\n");
    double R2_3 = (R2 * R3) / (R2 + R3); /* Calculates the equivalent resistance of R2 and R3 */
    double Ampsource = Vsource / (R1 + R2_3); /* Calculates the source current using Ohm's Law with the source voltage and total resistance */
    voltR1 = Ampsource * R1; /* Ohm's Law */
    printf("Voltage across R1: %lf V\n", voltR1);
    printf("Current through R1: %lf A\n", Ampsource);
    ampR2 = Ampsource * (R3 / (R2 + R3)); /* Calculates current through R2 using current division rule */
    voltR2 = ampR2 * R2; /* Ohm's Law*/
    printf("Voltage across R2: %lf V\n", voltR2);
    printf("Current through R2: %lf A\n", ampR2);
    ampR3 = Ampsource - ampR2; /* calculates value of R3 using KCL */
    voltR3 = ampR3 * R3; /* Ohm's Law */
    printf("Voltage across R3: %lf V\n", voltR3);
    printf("Current through R3: %lf A\n", ampR3);
}