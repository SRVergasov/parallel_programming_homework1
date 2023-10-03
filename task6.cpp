#include <iostream>
#include <omp.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    double mean_a = 0.0;
    double mean_b = 0.0;

#pragma omp parallel for reduction(+:mean_a, mean_b)
    for (int i = 0; i < 10; i++) {
        mean_a += a[i];
        mean_b += b[i];
    }

    mean_a /= 10;
    mean_b /= 10;

    printf("Mean of array a: %.2lf\n", mean_a);
    printf("Mean of array b: %.2lf\n", mean_b);

    if (mean_a < mean_b) {
        printf("Mean of array a is smaller than mean of array b.\n");
    } else if (mean_a > mean_b) {
        printf("Mean of array a is greater than mean of array b.\n");
    } else {
        printf("Mean of array a is equal to mean of array b.\n");
    }

    return 0;
}