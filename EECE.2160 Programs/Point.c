/* Richard Kumahia
EECE.2160
5/7/20
This assignment focuses on the use of structures.
We will model a group of rectangles as a collection of their vertices,
using structures to represent each of those points as well as the rectangles as a whole.
In doing so, we will gain familiarity with the typical file organization used when defining structures,
as well as the syntax required to work with structures nested inside one another.
*/

#include "Point.h"
#include <stdio.h>
#include <math.h>

// Print coordinates as (x.xx, y.yy)
void printPoint(Point* p) {
	printf("(%.2lf, %.2lf)", p->x, p->y);
}

// Read input coordinates
void readPoint(Point* p) {
	scanf("%lf %lf", &p->x, &p->y);
}