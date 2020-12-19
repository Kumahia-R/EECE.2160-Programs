/*
 * EECE.2160: ECE Application Programming
 * Exam 4 Problems
 *
 * Program to test your solutions to the
 *   required string function
 */

#include "exam4_string_fns.h"

#include <stdio.h>

int main() {
	char s1[100] = "exam";
	char s2[100] = "ple";
	char s3[100] = "string";

	printf("Initially:\n");
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("s3 = %s\n", s3);

	insertSubString(s1, s2, 4);
	insertSubString(s2, "sam", 0);
	insertSubString(s2, " ", 6);
	insertSubString(s2, s3, 7);
	insertSubString(s3, "etch", 3);

	printf("\nAfter insertSubString calls:\n");
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("s3 = %s\n", s3);

	return 0;
}