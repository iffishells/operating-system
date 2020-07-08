#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_RUNS  10000000

void handler(void *ptr);

int counter;

int main()
{
	int ticks=clock();
	printf("%f\n", (float)ticks / CLOCKS_PER_SEC);

	int i[2];

	pthread_t thread_a;
	pthread_t thread_b;

	i[0]=0;
	i[1]=1;

	pthread_create (&thread_a, NULL,(void *) &handler,(void * ) &i[0]);
	pthread_create (&thread_b ,NULL,(void *) &handler,(void * ) &i[1]);
	//	int ticks=clock();
	printf("%f\n", (float)ticks / CLOCKS_PER_SEC);


	pthread_join(thread_a,NULL);
	pthread_join(thread_b,NULL);

	printf("----------------------------------------\n" );
	printf(" final counter value : %d\n", counter );
	printf("Error:                 %d\n", (NUM_RUNS*2-counter) );
	//int ticks=clock();
	printf("%f\n", (float)ticks / CLOCKS_PER_SEC);

	exit(0);


}

void handler(void *ptr)
{
	int iter = 0;
	int thread_num;
	thread_num = * ((int *)ptr);
	printf(" Starting thread : %d\n", thread_num);


	while(iter <NUM_RUNS)
	{
		counter++;
		//printf(" counter :  %d\n",counter);
		iter +=1;
	}


	printf(" Thread %d , counter = %d \n",thread_num ,counter );
	pthread_exit(0);



}
	//What should be the value of the counter variable at the end?
		//The value of the counter should be 20000000

	// What is the value you get?
//			is 13140527

//		How large is the error and how much does it vary on different runs?
//		our error is 6863004 


//		How much user time (rougly) does the program take to run on your system?

		// less then minute