#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size, token;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size < 2) {
        if (rank == 0) cout << "Run with at least 2 processes\n";
        MPI_Finalize();
        return 0;
    }
    int right = (rank + 1) % size;
    int left = (rank - 1 + size) % size;
    if (rank == 0) {
        token = 100;
        MPI_Send(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
        MPI_Recv(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Final token = " << token << endl;
    } else {
        MPI_Recv(&token, 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        token += 10;
        MPI_Send(&token, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
