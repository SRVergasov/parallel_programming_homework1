#include <stdio.h>
#include <omp.h>

int main() {
    int a[12], b[12], c[12];
    int num_threads1 = 3;
    int num_threads2 = 4;

#pragma omp parallel num_threads(num_threads1)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Parallel region 1: Thread %d of %d\n", tid, num_threads);

#pragma omp for schedule(static, 4)
            for (int i = 0; i < 12; i++) {
                a[i] = i;
                b[i] = i * 2;
            }
        }

#pragma omp parallel num_threads(num_threads2)
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Parallel region 2: Thread %d of %d\n", tid, num_threads);

#pragma omp for schedule(dynamic, 3)
        for (int i = 0; i < 12; i++) {
            c[i] = a[i] + b[i];
        }
    }

    printf("Array c: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
