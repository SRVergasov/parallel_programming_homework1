#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        std::cout << "Error: Program requires at least 2 processes" << std::endl;
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        // Генерация случайных чисел для массива a
        std::srand(std::time(0));
        int a[10];
        for (int i = 0; i < 10; i++) {
            a[i] = std::rand() % 100;
        }

        // Пересылка массива a первому процессу
        MPI_Send(a, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        // Получение массива a от нулевого процесса
        int a[10];
        MPI_Recv(a, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Печать принятого массива
        std::cout << "Received array: ";
        for (int i = 0; i < 10; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}