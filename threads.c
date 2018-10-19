#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int totalSum = 0;
void threadCal(int num)
{
	int localSum = 0;
 
	for (int j=num ; j<num+100 ; j++)
	{
		localSum = localSum + j;
	}
	totalSum = totalSum + localSum;
}

void main()
{
	pthread_t t1;
	int start = 1;

	for (int i=0 ; i<10 ; i++)
	{
		pthread_create(&t1,NULL,threadCal,start);
		pthread_join(t1,NULL);
		start = start + 100;
	}
	printf("Total Sum : %d\n", totalSum);
}