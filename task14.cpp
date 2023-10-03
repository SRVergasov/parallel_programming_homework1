#include <stdio.h>
#include <omp.h>

int main() {
    int num = 210;
    int square = 0;

#pragma omp parallel for reduction(+:square)
    for (int i = 0; i < num; i++) {
        if (i % 2 != 0) {
            square += i;
        }
    }

    printf("The square of %d is %d\n", num, square);

    return 0;
}
