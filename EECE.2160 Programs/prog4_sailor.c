/*Richard Kumahia
EECE.2160
3/2/2020
This assignment, which introduces the use of loops, solves the following problem:
given a starting location in a city, how long does it take a "drunken sailor"
who randomly chooses his direction at each intersection to reach the city's border?
We will read input values to set up the problem parameters,
run several trials to determine an average number of steps for the sailor to reach the border,
and output the results.*/
#include <stdio.h>
#include <stdlib.h>     // Necessary for random number functions
int main() {
    int cityM, cityN;//the city size in number of blocks in the X and Y planes, respectively
    int sailorX, sailorY;//A starting position for the sailor, input as a pair of integers (X,Y)
    int numTrials;//number of trials
    char junk;//junk character for allowing new inputs in scanf
    int output = 1;//variable used to confirm whether to move on from loop or not, used for multiple loops
    //loop that keeps going if M,N inputs don't match the specified range
    while (output == 1) {
        printf("City size in X, Y  (# blocks >= 2 and <= 10): ");//prompt for input
        int valSize = scanf(" %d %d", &cityM, &cityN);//scans input and determines how many were read correctly
        //conditional statement that determines whether to restart the loop or not based on the value of ValSize
        if (valSize < 2) {
            printf("Could not read input\n");
            do {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
        else {
            //determines if M and N values are too large or too small and prints error statement accordingly
            if (cityM < 2 || cityM > 10) {
                printf("# X blocks must be >= 2 and <= 10\n");
            }
            if (cityN < 2 || cityN > 10) {
                printf("# Y blocks must be >= 2 and <= 10\n");
            }
            else if (cityM > 1 && cityM < 11 && cityN > 1 && cityN < 11) {
                output = 0; //loop exit is now allowed
            }
        }
    }
    output = 1;//makes output = 1 again for next loop
    //loop that keeps going if X,Y inputs don't match the specified range
    while (output == 1) {
        printf("\nStarting position (X Y): "); //prompt
        int valStart = scanf(" %d %d", &sailorX, &sailorY); //scans input and determines how many were read correctly
        //conditional statement that determines whether to restart the loop or not based on the value of ValStart
        if (valStart < 2) {
            printf("Could not read input\n");
            do {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
        else {
            //determines if X and Y values are too large or too small and prints error statement accordingly
            if (sailorX < 1 || sailorX >(cityM - 1)) {
                printf("Starting X position must satisfy (1 <= X <= %d)\n", cityM - 1);
            }
            if (sailorY < 1 || sailorY >(cityN - 1)) {
                printf("Starting Y position must satisfy (1 <= Y <= %d)\n", cityN - 1);
            }
            else if (sailorX >= 1 && sailorX <= (cityM - 1) && sailorY >= 1 && sailorY <= (cityN - 1)) {
                output = 0;
            }
        }
    }
    output = 1;
    while (output == 1) {
        printf("\nNumber of trials:"); //Prompt
        int valTrial = scanf(" %d", &numTrials); //Scan
        //Checks for correct input type
        if (valTrial < 1) {
            printf("Could not read input\n");
            do {
                scanf("%c", &junk);
            } while (junk != '\n');
        }
        else {
            //error check to make sure numTrials fits range
            if (numTrials > 0 && numTrials < 11) {
                output = 0;
            }
            else {
                printf("Number of trials must be > 0 and <= 10\n");
            }
        }
    }
    unsigned dir;     // Determines direction to move (N, S, E, W)
    int xOrig = sailorX, yOrig = sailorY; //original sailor position
    int stepSum = 0; //sum of the steps in every trial
    //For loop designed to keep looping (numTrials) times
    for (int i = 0; i < numTrials; i++) {
        printf("Trial # %d Start: %d %d\n", i + 1, sailorX, sailorY);
        int steps = 0; //number of steps per trial
        while (cityM > sailorX && cityN > sailorY && sailorX > 0 && sailorY > 0) { //checks if sailor is still within city borders
        /* Generate a random number to choose your direction */
            dir = rand() % 4;
            //switch statement changes the position of the sailor based on the random value of dir
            switch (dir) {
            case 0:
                sailorX--;
                printf("West: %d %d\n", sailorX, sailorY);
                break;
            case 1:
                sailorX++;
                printf("East: %d %d\n", sailorX, sailorY);
                break;
            case 2:
                sailorY++;
                printf("North: %d %d\n", sailorX, sailorY);
                break;
            case 3:
                sailorY--;
                printf("South: %d %d\n", sailorX, sailorY);
                break;
            }
            steps++; //increments number of steps with each complete loop in the while loop
        }
        stepSum += steps; //adds onto stepSum after steps is fully calculated per trial
        //resets X and Y to their original values before the start of the trial
        sailorX = xOrig;
        sailorY = yOrig;
        printf("Trial #%d total steps = %d\n", i + 1, steps);
    }
    switch (numTrials) {
        //prints the average steps over all trials (takes account for singular vs plural)
    case 1:
        printf("Average # of steps over %d trial: %.2lf\n", numTrials, (double)stepSum / numTrials);
        break;
    default:
        printf("Average # of steps over %d trials: %.2lf\n", numTrials, (double)stepSum / numTrials);
        break;
    }
    return 0;
}
