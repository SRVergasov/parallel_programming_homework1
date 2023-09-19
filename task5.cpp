#include <iostream>
#include <omp.h>

int main() {
    int d[6][8];
    int i, j;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int count = 0;

    // Initialize array with random values
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            d[i][j] = rand() % 100;
        }
    }

    #pragma omp parallel sections shared(i, j, d, sum, count, min, max) default(none)
    {
        #pragma omp section
        {
            int localSum = 0;
        #pragma omp parallel for reduction(+:localSum) shared(j, d) default(none)
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 8; j++) {
                    localSum += d[i][j];
                }
            }
            sum = localSum / (6 * 8);
            printf("Thread %d - Average: %d\n", omp_get_thread_num(), sum);
        }

        #pragma omp section
        {
            int localMin = min;
            int localMax = max;
            #pragma omp parallel for reduction(min:localMin) reduction(max:localMax) shared(j, d) default(none)
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 8; j++) {
                    if (d[i][j] < localMin) {
                        localMin = d[i][j];
                    }
                    if (d[i][j] > localMax) {
                        localMax = d[i][j];
                    }
                }
            }
            min = localMin;
            max = localMax;
            printf("Thread %d - Min: %d, Max: %d\n", omp_get_thread_num(), min, max);
        }

        #pragma omp section
        {
            int localCount = 0;
        #pragma omp parallel for reduction(+:localCount) shared(j, d) default(none)
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 8; j++) {
                    if (d[i][j] % 3 == 0) {
                        localCount++;
                    }
                }
            }
            count = localCount;
            printf("Thread %d - Count: %d\n", omp_get_thread_num(), count);
        }
    }

    return 0;
}