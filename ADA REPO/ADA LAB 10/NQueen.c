#include <stdio.h>
#include <stdlib.h>  // For abs() function

int x[20], count = 1;

void queens(int k, int n);
int place(int k, int j);

int main() {
    int n;

    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);

    queens(0, n);  // Starting from row 0
    return 0;
}

void queens(int k, int n) {
    int j;
    for (j = 0; j < n; j++) {  // 0-based index
        if (place(k, j)) {
            x[k] = j;  // Place the queen

            if (k == n - 1) {  // If all queens are placed
                printf("\nSolution %d:\n", count++);
                for (int i = 0; i < n; i++) {
                    // Display the board, where `x[i]` is the column of the queen in row i
                    for (int j = 0; j < n; j++) {
                        if (x[i] == j) {
                            printf(" Q ");  // Queen is placed here
                        } else {
                            printf(" * ");  // Empty space
                        }
                    }
                    printf("\n");
                }
            } else {
                queens(k + 1, n);  // Recursively place queens in the next row
            }
        }
    }
}

int place(int k, int j) {
    for (int i = 0; i < k; i++) {
        // Check if the queen is placed in the same column or diagonal
        if (x[i] == j || abs(x[i] - j) == abs(i - k)) {
            return 0;  // Conflict found, return false
        }
    }
    return 1;  // No conflict, return true
}
\
