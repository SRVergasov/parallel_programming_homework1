#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define SIZE 30

int main() {
    int a[SIZE];

    // Initialize array with random values
    std::srand(std::time(nullptr));
    for (int i = 0; i < SIZE; ++i) {
        a[i] = std::rand() % 100;
    }

    // Calculate number of elements divisible by 9
    int count = 0;
#pragma omp parallel for
    for (int i = 0; i < SIZE; ++i) {
        if (a[i] % 9 == 0) {
#pragma omp atomic
            ++count;
        }
    }

    // Print the result
    printf("Number of elements divisible by 9: %d\n", count);

    return 0;
}