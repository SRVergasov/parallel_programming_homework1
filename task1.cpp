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

/*
При запуске этой программы с 8 потоками, вывод может быть разным для разных запусков. Причина в том, что порядок выполнения потоков не определен и может меняться при каждом запуске программы. Таким образом, порядок, в котором потоки выводят свои идентификаторы и "Hello World", может меняться каждый раз.

Однако, каждый поток будет выводить свой идентификатор и общее количество потоков, что гарантированно.
*/
