#include <iostream>
#include <omp.h>

#define ARRAY_SIZE 100

int main() {
    int arr[ARRAY_SIZE];

    // Заполнение массива случайными значениями
#pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    int max_value = 0;

    // Поиск максимального числового значения, кратного 7
#pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] % 7 == 0) {
#pragma omp critical
            {
                if (arr[i] > max_value) {
                    max_value = arr[i];
                }
            }
        }
    }

    printf("Max value divisible by 7: %d\n", max_value);

    return 0;
}