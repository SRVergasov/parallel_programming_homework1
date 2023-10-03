#include <stdio.h>
#include <omp.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int range_start, range_end;

    printf("Enter the range start: ");
    scanf("%d", &range_start);
    printf("Enter the range end: ");
    scanf("%d", &range_end);

    printf("Prime numbers in the range [%d, %d]:\n", range_start, range_end);

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int chunk_size = (range_end - range_start + 1) / num_threads;

        int start = range_start + thread_id * chunk_size;
        int end = (thread_id == num_threads - 1) ? range_end : start + chunk_size - 1;

        for (int num = start; num <= end; num++) {
            if (is_prime(num)) {
#pragma omp critical
                {
                    printf("%d ", num);
                }
            }
        }
    }

    printf("\n");

    return 0;
}
