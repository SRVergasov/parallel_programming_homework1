#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ROWS = 6;
    int COLS = 8;
    int d[ROWS][COLS];


    // Initialize array with random values
#pragma omp parallel for
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            d[i][j] = rand() % 100;
        }
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;

#pragma omp parallel for
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
#pragma omp critical
            {
                if (d[i][j] < min_val) {
                    min_val = d[i][j];
                }

                if (d[i][j] > max_val) {
                    max_val = d[i][j];
                }
            }
        }
    }

    printf("Minimum value: %d\n", min_val);
    printf("Maximum value: %d\n", max_val);

    return 0;
}
