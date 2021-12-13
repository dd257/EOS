#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int *count;
int num;

int main(int argc, const char* argv[])
{
    int shm;

    shm = shm_open("/shm",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    ftruncate(shm,sizeof(int));
    count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm,0);

    while(1)
    {
        scanf("%d",&num);
        *count=num;
    }    
}