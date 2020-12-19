/**** REPLACE THIS COMMENT WITH APPROPRIATE HEADER COMMENT ****/

#include <stdio.h>
#include <ctype.h>
#include "prog6_functions.h"

int main() {
    int histogram[26] = { 0 };
    int freqLetter = 0;
    char userIn = ' ';
    while (userIn != 'Q' && userIn != 'q') {
        printf("Enter command (C, R, P or Q): ");
        scanf(" %c", &userIn);
        switch (userIn) {
            case 'C': case 'c':
                for (int i = 0; i < 26; i++) {
                    histogram[i] = 0;
                }
                freqLetter = 0;
                break;
            case 'R': case 'r':
                ReadText(histogram, &freqLetter);
                break;
            case 'P': case 'p':
                DrawHist(histogram, freqLetter);
                break;
            case 'Q': case 'q':
                break;
            default:
                printf("Invalid command %c\n", userIn);
        }
    }

    /* COMPLETE FUNCTION WITH APPROPRIATE CODE */

    return 0;
}
