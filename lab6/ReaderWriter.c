#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
sem_t mutex,wrte;
int readcount=0;

void *reader();
void *writer();

void *writer()
{
	sem_wait(&wrte);			//decrease writer so that no other must be able to read.
	printf("Writer is writing into the file \n");
	sem_post(&wrte);			//increase writer so that other witers may access.
}
void *reader()
{
	sem_wait(&mutex); 			//decrease the reader semaphore count because reading is about to happen
	readcount++;
	if(readcount>0)
		sem_wait(&wrte);
	sem_post(&mutex); 			//reading has happend. hence increase reader semaphore
	printf("Reader %d is reading the file\n",readcount);
	sem_wait(&mutex);
	readcount--;
	if(readcount==0)
		sem_post(&wrte);		//if its the last reader exiting, signal the writer to enter.
	sem_post(&mutex);			//when readcount is updating, you should allow only one process to have access to it.	
}
int main(int argc, const char * argv[])
{
	sem_init(&mutex,0,1);
    sem_init(&wrte,0,1);		//initializing the semaphores to 1
	pthread_t rdr[5], wtr[5];
	int count=2;
	int i;
	for(i=0;i<=5;i++)
  	{
    	pthread_create(&wtr[i],NULL,writer,NULL);
    	pthread_create(&rdr[i],NULL,reader,NULL);
  	}
  	for(i=0;i<=5;i++)
  	{
    	pthread_join(wtr[i],NULL);
    	pthread_join(rdr[i],NULL);
  	}
}

