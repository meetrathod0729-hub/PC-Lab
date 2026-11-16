#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;

int main(int argc,char** argv)
{
    MPI_Init(&argc,&argv);
    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(size<2)
    {
        if(rank==0)
        {
            cout<<"Run with atleat 2 processors: \n";
        }
        MPI_Finalize();
        return 0;
    }
    int right=(rank+1)%size;
    int left=(rank-1+size)%size;
    if(rank==0)
    {
        token=100;
        
    }
}