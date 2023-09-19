#include <iostream>
#include <omp.h>

int main() {
    int numThreads = 3;
    #pragma omp parallel if(numThreads > 1) num_threads(numThreads) default(none)
    {
        printf("Parallel region 1: Thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }

    numThreads = 1;
    #pragma omp parallel if(numThreads > 1) num_threads(numThreads) default(none)
    {
        printf("Parallel region 2: Thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}