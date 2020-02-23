#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
	pthread_mutex_t input_lock[5];
	int int_val[5];
	float float_val[5];
}input;

void *add_thread();

int main(int argc, char** argv) 
{
	int i;
	input input1;
	input* ptr;
	pthread_t thr[5];
	ptr=&input1;
	for(i=0;i<5;i++)
	{
		input1.int_val[i]=i+1;
		input1.float_val[i]=i+1;
		pthread_mutex_init(&input1.input_lock[i],NULL);
	}
	pthread_setconcurrency(4);
	for(i=0;i<5;i++)
	{
		pthread_create(&thr[i],NULL,add_thread,(void *)ptr);
	}
	pthread_join(thr[4],NULL);
	for(i=0;i<5;i++)
	{
		printf("int %d = %d\n",i,input1.int_val[i]);
		printf("float %d = %f\n",i,input1.float_val[i]);
	}
	system("pause");
	return 0;
}
