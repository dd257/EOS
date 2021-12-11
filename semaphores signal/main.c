#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b;
sem_t s1,s2;

void *read(void *arg)
{
    while(1)
    {
       sem_wait(&s1);
       scanf("%d",&a);
       scanf("%d",&b); 
       sem_post(&s2);
    }
}

void *write(void *arg)
{
    while(1)
    {
        sem_wait(&s2);
        printf("prod: %d * %d = %d\n",a,b,a*b);
        sem_post(&s1);
    }
}

int main(int argc, const char *argv[])
{
    pthread_t readCount,writeCount;
    
    sem_init(&s1,0,1);
    sem_init(&s2,0,1);
    
    pthread_create(&readCount,NULL,read,NULL);
    pthread_create(&writeCount,NULL,write,NULL);
    
    pthread_join(readCount,NULL);
    pthread_join(writeCount,NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);
}   
