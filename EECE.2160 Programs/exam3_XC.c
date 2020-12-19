/*
 * EECE.2160: ECE Application Programming
 * Exam 3 Problems
 *
 * Space to complete extra credit function
 */

 // Looks at 3x3 array to see if it's a valid Sudoku solution
// Returns 1 if valid, 0 otherwise
unsigned isSudokuSoln(unsigned soln[9][9]) {
    // COMPLETE FUNCTION WITH VALID CODE
    int numExists[9] = { 0 };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            numExists[soln[i][j] - 1]++;
        }
        for (int j = 0; j < 9; j++) {
            if ((numExists[j]) != 1) {
                return 0;
            }
            else {
                numExists[j] = 0;
            }
        }
    }
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            numExists[soln[i][j] - 1]++;
        }
        for (int i = 0; i < 9; i++) {
            if ((numExists[i]) != 1) {
                return 0;
            }
            else {
                numExists[i] = 0;
            }
        }
    }
    for (int i = 1; i < 8; i += 3) {
        for (int j = 1; j < 8; j += 3) {
            if (soln[i][j] == soln[i][j - 1] || soln[i][j] == soln[i][j + 1]) {
                return 0;
            }
            if (soln[i][j] == soln[i - 1][j] || soln[i][j] == soln[i - 1][j + 1] || soln[i][j] == soln[i - 1][j - 1]) {
                return 0;
            }
            if(soln[i][j] == soln[i + 1][j + 1] || soln[i][j] == soln[i + 1][j - 1] || soln[i][j] == soln[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}