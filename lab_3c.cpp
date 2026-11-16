#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 4) {
        if (rank == 0) cout << "Run with 4 processes\n";
        MPI_Finalize();
        return 0;
    }
    char letters[4] = {'V', 'J', 'T', 'I'}, received;
    MPI_Scatter(letters, 1, MPI_CHAR, &received, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    cout << "Rank " << rank << " got " << received << endl;
    MPI_Finalize();
    return 0;
}
