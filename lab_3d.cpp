#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 6) {
        if (rank == 0) cout << "Run with 6 processes\n";
        MPI_Finalize();
        return 0;
    }
    int values[6] = {12, 45, 89, 23, 67, 34};
    int local, maximum;
    MPI_Scatter(values, 1, MPI_INT, &local, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local, &maximum, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if (rank == 0) cout << "Maximum = " << maximum << endl;
    MPI_Finalize();
    return 0;
}
