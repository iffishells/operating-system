

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
void* thread1()
	{
		for (int c=0 ; c<10 ; c++)
		{
			printf("Hello\n" );
		}
	}

void* thread2()
	{
		for (int c=0 ; c<10 ; c++)
		{
			printf("world\n" );
		}
	}

int main()
{
	int status;

	pthread_t tid1 , tid2; //,tid3 ,tid4;

	pthread_create( &tid1 ,NULL ,thread1 ,NULL);
	pthread_create(&tid2,NULL,thread2 , NULL);



	//pthread_create( &tid3 ,NULL ,thread1 ,NULL);
	//pthread_create(&tid4,NULL,thread2 , NULL);


	pthread_join(tid1,NULL);
	pthread_join(tid2 , NULL);

	//pthread_join(tid3,NULL);
	//pthread_join(tid4 , NULL);
	int ticks=clock();
	printf("%f\n", (float)ticks / CLOCKS_PER_SEC);



	return 0;
}