//  prog7_functions.c

#include <stdio.h>
#include "prog7_functions.h"

// Reset grid to original settings
void resetGrid(char grid[][NCols]) {
	int i;
	int j;
	// sets every coordinate to either a '+', '-', '|' or ' ' depending on the location
	for (i = NRows-1; i >= 0; i--) {
		for (j = 0; j < NCols; j++) {
			if (i % 5 == 0 && j % 5 == 0) {
				grid[i][j] = '+';
			}
			else if (i % 5 == 0) {
				grid[i][j] = '-';
			}
			else if (j % 5 == 0) {
				grid[i][j] = '|';
			}
			else {
				grid[i][j] = ' ';
			}
		}
	}
}

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height) {
	int i = 0;
	int j = 0;
	//changes necessary coordinates to '*' based on the input variables
	for (i = 0; i < width; i++) {
		//checks if the proposed coordinates are out of bounds
		if (i + x < NCols && i + x >= 0) {
			for (j = 0; j < height; j++) {
				if (j + y < NRows && j + y >= 0) {
					grid[y+j][x+i] = '*';
				}
			}
		}
	}
}

// Print current grid contents
void printGrid(char grid[][NCols]) {
	int i = 0;
	int j = 0;
	for (i = NRows; i >= 0; i--) {
		for (j = 0; j < NCols; j++) {
			//boolean statements check if the function should print a label for the axes or a part of the grid
			if (i - 1 >= 0) {
				printf("%c", grid[i - 1][j]);
			}
			if (j == NCols - 1 && (i-1) % 5 == 0) {
				printf("%d", i-1);
			}
			if (i == 0 && j % 5 == 0) {
				printf("%d   ", j);
			}
		}
		printf("\n");
	}
}