#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
    const int numThreads = 8;

    #pragma omp parallel num_threads(numThreads) default(none)
    {
        printf("%d; %d; Hello World\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}