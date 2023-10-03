#include <iostream>
#include <omp.h>

int main() {
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int p = 2; // Base of the number system

    int decimal = 0;

#pragma omp parallel for reduction(+:decimal)
    for (int i = 0; i < 30; i++) {
        decimal = decimal * p + a[i];
    }

    printf("The decimal representation is: %d\n", decimal);

    return 0;
}
