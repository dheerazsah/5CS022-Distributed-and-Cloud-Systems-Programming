#include <stdio.h>
#include <mpi.h>
int main(void){
	int sum;
	int size;
	int rank;
	int tag =0;
	int ball = 0;
	MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (size != 2){
    	printf("Needs two process!\n");
    	MPI_Finalize();
    	return 0;
    }
    while(1){
    	if(rank ==0){
    		MPI_Send(&ball, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    		MPI_Recv(&ball, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    		printf("Process 0 received ball of %d\n", ball);
    		if(ball == 10){
    			break;
    		}
    	}
    	else{
    		MPI_Recv(&ball, 1,MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    		printf("Process 1 received ball of %d\n", ball);
    		ball++;
    		MPI_Send(&ball, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    		if(ball == 10){
    			break;
    		}
    	}  }
    MPI_Finalize();
    return 0;
}