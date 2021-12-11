#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t mutexCount;
pthread_mutexattr_t mutexattr;

void _inc()
{
    pthread_mutex_lock(&mutexCount);
    count++;
    printf("Count = %d\n",count);
    pthread_mutex_unlock(&mutexCount);
}

void _dec()
{
    pthread_mutex_lock(&mutexCount);
    count--;
    printf("Count = %d\n",count);
    pthread_mutex_unlock(&mutexCount);
}

void *inc(void *arg)
{
    while(1)
    {
        printf("Inc before lock\n");
        pthread_mutex_lock(&mutexCount);
        count++;
        _inc();
        pthread_mutex_unlock(&mutexCount);
        printf("Inc after Unlock\n");
    }
}

void *dec(void *arg)
{
    while(1)
    {
        printf("Dec before lock\n");
        pthread_mutex_lock(&mutexCount);
        count--;
        _dec();
        pthread_mutex_unlock(&mutexCount);
        printf("Dec after Unlock\n");
    }
}

int main(int argc, const char *argv[])
{
    pthread_t incCount,decCount;
    
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexCount,&mutexattr);
    
    pthread_create(&incCount,NULL,inc,NULL);
    pthread_create(&decCount,NULL,dec,NULL);
    
    pthread_join(incCount,NULL);
    pthread_join(decCount,NULL);

    pthread_mutex_destroy(&mutexCount);
}   