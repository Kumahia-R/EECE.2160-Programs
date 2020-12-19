/* Richard Kumahia
EECE.2160
5/7/20
This assignment focuses on the use of structures.
We will model a group of rectangles as a collection of their vertices,
using structures to represent each of those points as well as the rectangles as a whole.
In doing so, we will gain familiarity with the typical file organization used when defining structures,
as well as the syntax required to work with structures nested inside one another.
*/

#include "Rectangle.h"		// Implicitly includes Point.h
#include <stdio.h>

// Print contents of rectangle
// Prints vertices in appropriate relative positions:
//   vert[1]   vert[2]
//   vert[0]   vert[3]
void printRectangle(Rectangle* r) {
   //prints each point by calling the printPoint() function for each vertex in the necessary order
	printPoint(&r->vert[1]);
	printf("    ");
	printPoint(&r->vert[2]);
	printf("\n");
	printPoint(&r->vert[0]);
	printf("    ");
	printPoint(&r->vert[3]);
	printf("\n\n");
}

// Print list of n Rectangles
void printList(Rectangle list[], int n) {
   //for loop using the printRectangle() function for each Rectangle in the list
	for (int i = 0; i < n; i++) {
		printRectangle(&list[i]);
	}
}

// Returns area of rectangle
double area(Rectangle* r) {
	double height = (r->vert[1].y) - (r->vert[0].y); //calculates the height of the rectangle
	double base = (r->vert[3].x) - (r->vert[0].x); //calculates the base of the rectangle
	return (base * height); //returns the area = base*height
}

// Returns perimeter of rectangle
double perimeter(Rectangle* r) {
	double height = (r->vert[1].y) - (r->vert[0].y);
	double base = (r->vert[3].x) - (r->vert[0].x);
	return (2 * height) + (2 * base); //returns the perimeter after calculating the base and height
}

// Returns 1 if two rectangles overlap; 0 otherwise
int overlap(Rectangle* r1, Rectangle* r2) {
	if (r1->vert[1].y >= r2->vert[1].y && r1->vert[0].y <= r2->vert[1].y) { //checks if the upper edge of r2 is within the height of r1  
		if (r1->vert[3].x >= r2->vert[0].x && r1->vert[0].x <= r2->vert[0].x) { //checks if the left edge of r2 is within the base of r1
			return 1;
		}
		else if (r1->vert[3].x >= r2->vert[3].x && r1->vert[0].x <= r2->vert[3].x) { // checks if the right edge of r2 is within the base of r1
			return 1;
		}
	}
	else if (r1->vert[1].y >= r2->vert[0].y && r1->vert[0].y <= r2->vert[0].y) { //checks if the lower edge of r2 is within the height of r1 
		if (r1->vert[3].x >= r2->vert[0].x && r1->vert[0].x <= r2->vert[0].x) {
			return 1;
		}
		else if (r1->vert[3].x >= r2->vert[3].x && r1->vert[0].x <= r2->vert[3].x) {
			return 1;
		}
	}
	if (r2->vert[1].y >= r1->vert[1].y && r2->vert[0].y <= r1->vert[1].y) { //checks if the upper edge of r2 is within the height of r1  
		if (r2->vert[3].x >= r1->vert[0].x && r2->vert[0].x <= r1->vert[0].x) { //checks if the left edge of r2 is within the base of r1
			return 1;
		}
		else if (r2->vert[3].x >= r1->vert[3].x && r2->vert[0].x <= r1->vert[3].x) { // checks if the right edge of r2 is within the base of r1
			return 1;
		}
	}
	else if (r2->vert[1].y >= r1->vert[0].y && r2->vert[0].y <= r1->vert[0].y) { //checks if the lower edge of r2 is within the height of r1 
		if (r2->vert[3].x >= r1->vert[0].x && r2->vert[0].x <= r1->vert[0].x) {
			return 1;
		}
		else if (r2->vert[3].x >= r1->vert[3].x && r2->vert[0].x <= r1->vert[3].x) {
			return 1;
		}
	}
	else { //assumes rectangles dont overlap and returns 0
		return 0;
	}
}