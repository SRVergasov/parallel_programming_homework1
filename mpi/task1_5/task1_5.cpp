#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int number = rank * 10;

    if (rank == 0) {
        int* recv_buffer = new int[size];

        for (int i = 1; i < size; i++) {
            MPI_Recv(&recv_buffer[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        std::cout << "Received numbers: ";
        for (int i = 1; i < size; i++) {
            std::cout << recv_buffer[i] << " ";
        }
        std::cout << std::endl;

        delete[] recv_buffer;
    } else {
        MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}