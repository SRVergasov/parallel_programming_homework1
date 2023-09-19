#include <iostream>
#include <omp.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min_a, max_b;

    #pragma omp parallel num_threads(2) shared(min_a, max_b, a, b) default(none)
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            // Main thread computes min of array a
            min_a = a[0];
            for (int i = 1; i < 10; i++) {
                if (a[i] < min_a) {
                    min_a = a[i];
                }
            }
        } else if (thread_id == 1) {
            // Thread with ID 1 computes max of array b
            max_b = b[0];
            for (int i = 1; i < 10; i++) {
                if (b[i] > max_b) {
                    max_b = b[i];
                }
            }
        }
    }

    printf("Minimum value of array a is: %d\n", min_a);
    printf("Maximum value of array b is: %d\n", max_b);

    return 0;
}