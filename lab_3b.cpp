#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int steps = 1000000;
    double step = 1.0 / steps, local = 0, total = 0;
    for (int i = rank; i < steps; i += size) {
        double x = (i + 0.5) * step;
        local += 4.0 / (1.0 + x * x);
    }
    MPI_Reduce(&local, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) cout << "Pi = " << step * total << endl;
    MPI_Finalize();
    return 0;
}
