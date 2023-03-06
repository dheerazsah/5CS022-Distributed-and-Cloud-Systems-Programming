#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
int i, c;
int size, rank;
int nstart=1, nfinish=10000;
MPI_Init(NULL, NULL);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

printf("Prime numbers between %d and %d are :\n",
nstart, nfinish);
for(i=nstart; i<=nfinish; i++)
{
for(c=2; c<=i-1; c++)
{
if ( i%c==0 )
break;
}
if ( c==i )
printf("%s : %d\n",argv[0], i);
}
MPI_Finalize();
return 0;
}

