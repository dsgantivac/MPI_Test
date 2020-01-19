/*
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv ) {
	int rank, size;
	MPI_Init( &argc, &argv );
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("kio padre world from process %d of %d\n", rank, size );
	MPI_Finalize( );
return 0;
}
*/

//mpicc mpi_gather-test.c -o mpi_gather-test -lm
//
 
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <math.h>
#define MSG_LENGTH 10
#define MAXTASKS 32
int main (int argc, char **argv)
{
    int i, tag=0, tasks, iam, root=0, buff2send, buff2recv[MAXTASKS], namelen;
    double x;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &tasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    buff2send = iam;
    if (iam == 0) {
        MPI_Gather((void *)&buff2send, 1, MPI_INT, buff2recv, 1, MPI_INT, root, MPI_COMM_WORLD);
        for(i=0; i < tasks; i++)
            printf(" %i ", buff2recv[i]);
     } else {
        MPI_Comm_rank(MPI_COMM_WORLD, &iam);
        MPI_Gather((void *)&buff2send, 1, MPI_INT, buff2recv, 1, MPI_INT, root, MPI_COMM_WORLD);
        MPI_Comm_rank(MPI_COMM_WORLD, &iam);
    }
       MPI_Finalize();
}


