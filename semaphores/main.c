#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t semCount;

void _inc()
{
//    sem_wait(&semCount);
    count++;
    printf("Count = %d\n",count);
  //  sem_post(&semCount);
}

void _dec()
{
    //sem_wait(&semCount);
    count--;
    printf("Count = %d\n",count);
    //sem_post(&semCount);
}

void *inc(void *arg)
{
    while(1)
    {
        printf("Inc before lock\n");
        sem_wait(&semCount);
        count++;
        _inc();
        sem_post(&semCount);
        printf("Inc after Unlock\n");
    }
}

void *dec(void *arg)
{
    while(1)
    {
        printf("Dec before lock\n");
        sem_wait(&semCount);
        count--;
        _dec();
        sem_post(&semCount);
        printf("Dec after Unlock\n");
    }
}

int main(int argc, const char *argv[])
{
    pthread_t incCount,decCount;
    
    sem_init(&semCount,0,1);
    
    pthread_create(&incCount,NULL,inc,NULL);
    pthread_create(&decCount,NULL,dec,NULL);
    
    pthread_join(incCount,NULL);
    pthread_join(decCount,NULL);

    sem_destroy(&semCount);
}   
