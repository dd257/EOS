#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>

int *count;
int num;
sem_t *s1,*s2;

int main(int argc, const char* argv[])
{
    int shm;

    shm = shm_open("/shm",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    ftruncate(shm,sizeof(int));
    count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm,0);
    s1 = (sem_t *)mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,shm,0);
    s2 = (sem_t *)mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED,shm,0);
    
    sem_init(s1,0,1);
    sem_init(s2,0,1);

    while(1)
    {
        sem_wait(s1);
        printf("p1: %d, %d\n",*s1,*s2);
        scanf("%d",&num);
        *count=num;
        sem_post(s2);
    }    

    sem_destroy(s1);
    sem_destroy(s2);
}