#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
  int size, rank;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank ==0){
    for (int i = 0; i < size; i){
        int x = 20;
        MPI_Send(&x, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
    } else {
      int number;
      MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("Process %d received %d\n", rank, number); 
  }
  MPI_Finalize(); 
  return 0;
}
