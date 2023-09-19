#include <iostream>
#include <omp.h>

int main() {
    int a = 10;
    int b = 5;

    printf("Values of variables before entering the parallel domain: a = %d, b = %d\n", a, b);

    // Первая параллельная область
    #pragma omp parallel num_threads(2) private(a) firstprivate(b) default(none)
    {
        int thread_num = omp_get_thread_num();
        a += thread_num;
        b += thread_num;

        printf("Values of variables inside the parallel region (first region, thread number %d): a = %d, b = %d\n", thread_num, a, b);
    }

    printf("\"Values of variables after exiting the parallel region (first region): a = %d, b = %d\n", a, b);

    // Вторая параллельная область
    #pragma omp parallel num_threads(4) shared(a) private(b) default(none)
    {
        int thread_num = omp_get_thread_num();
        a -= thread_num;
        b -= thread_num;

        printf("Values of variables inside the parallel region (second region, thread number %d): a = %d, b = %d\n", thread_num, a, b);
    }

    printf("Values of variables after exiting the parallel region (second region): a = %d, b = %d\n", a, b);

    return 0;
}