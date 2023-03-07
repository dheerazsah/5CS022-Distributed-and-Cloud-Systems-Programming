#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)
{ int i, c;
  int size,rank;
  int ball = 0;
  MPI_Init(NULL,NULL);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  int sender , receiver;
  int parcel = 1;
  if(size != 3){
  printf("The program needs to be operated on 3 processes"); }
  else{
if(rank ==0){
sender = size-1;}
  else{
  sender = rank-1;}
  if (rank == size -1){
  receiver = 0;}
  else{
  receiver = rank +1;}
  if (rank == 0){
  MPI_Send(&parcel ,1,MPI_INT,(rank+1),0,MPI_COMM_WORLD);
  MPI_Recv(&parcel,1,MPI_INT,(rank-1),0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  printf("Process 0 received parcel %d \n",parcel);
  }
  else{
  MPI_Recv(&parcel,1,MPI_INT,(rank-1),0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  printf("Process %d received parcel %d\n",rank,parcel);
  parcel++;
  MPI_Send(&parcel,1,MPI_INT,receiver,0,MPI_COMM_WORLD);
  } }
  MPI_Finalize();
  return 0;
  }
