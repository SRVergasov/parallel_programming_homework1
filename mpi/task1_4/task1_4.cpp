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

        // Пересылка массива a процессам с номерами от 1 до size-1
        for (int i = 1; i < size; i++) {
            MPI_Send(a, 10, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        // Определение размера принимаемого сообщения
        MPI_Status status;
        int count;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);

        // Выделение памяти под приемный буфер
        int* recv_buffer = new int[count];

        // Прием массива от процесса с номером 0
        MPI_Recv(recv_buffer, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Печать принятого массива
        std::cout << "Process " << rank << " received array: ";
        for (int i = 0; i < count; i++) {
            std::cout << recv_buffer[i] << " ";
        }
        std::cout << std::endl;

        // Освобождение памяти
        delete[] recv_buffer;
    }

    MPI_Finalize();
    return 0;
}