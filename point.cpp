
#include <bits/stdc++.h>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int data = 100;

    if(rank == 0)
    {
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        cout << "Process 0 sent " << data << endl;
    }
    else if(rank == 1)
    {
        MPI_Recv(&data, 1, MPI_INT, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 1 received " << data << endl;
    }

    MPI_Finalize();
    return 0;
}
