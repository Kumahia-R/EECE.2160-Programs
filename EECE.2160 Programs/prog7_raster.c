/* 
* Richard Kumahia 5/1/20
* EECE.2160 ECE Application Programming
* Implements simple raster scan graphics program--
*    will print box and grid, line by line
* Tests use of 2-D arrays, nested loops, strings
*/

#include <stdio.h>
#include <string.h>
#include "prog7_functions.h"

int main() {
	char myGrid[NRows][NCols];
	resetGrid(myGrid);		// Initialize grid to clear state	
	/****** EECE.2160 PROGRAM **********
		ADD ADDITIONAL VARIABLES HERE
	********************************/
	int originX, originY, widthX, heightY;
	int exit = 0;
	char userCommand[50];
	/******* EECE.2160 PROGRAM **********
		LOOP TO REPEATEDLY PROMPT FOR AND EXECUTE INPUT COMMANDS
	*********************************/
	while (exit == 0) {
		/***** EECE.2160 PROGRAM **********
		PROMPT FOR AND READ INPUT COMMAND
		*******************************/
		printf("Enter command: ");
		scanf("%s", userCommand);
		/***** EECE.2160 PROGRAM **********
		"print" COMMAND ENTERED--PRINT CURRENT STATE OF GRID
		*******************************/
		if (strcmp(userCommand, "print") == 0) {
			printGrid(myGrid);
		}
		/***** EECE.2160 PROGRAM ***********
		"add" COMMAND ENTERED--PROMPT FOR ORIGIN
		COORDINATES (X,Y), WIDTH, AND HEIGHT, THEN
		ADD BOX TO GRID
		**********************************/
		else if (strcmp(userCommand, "add") == 0) {
			printf("Enter X and Y coordinates for origin: ");
			scanf("%d %d", &originX, &originY);
			printf("Enter width and height: ");
			scanf("%d %d", &widthX, &heightY);
			addBox(myGrid, originX, originY, widthX, heightY);
		}
		/***** EECE.2160 PROGRAM ***********
		"reset" COMMAND ENTERED--RESET GRID TO HAVE NO BOXES
		*********************************/
		else if (strcmp(userCommand, "reset") == 0) {
			resetGrid(myGrid);
		}
		/***** EECE.2160 PROGRAM ***********
		"exit" COMMAND ENTERED--END PROGRAM
		**********************************/
		else if (strcmp(userCommand, "exit") == 0) {
			exit = 1;
		}
		/***** EECE.2160 PROGRAM ***********
		NO MATCHING COMMAND--PRINT ERROR
		*********************************/
		else {
			printf("Invalid command %s\n", userCommand);
		}
	}
	/***** EECE.2160 PROGRAM **********
	END LOOP
	********************************/
}