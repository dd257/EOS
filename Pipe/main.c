#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, const char *argv[])
{
    char buf[10]={};
    int fd[2];
    pid_t id;

    pipe(fd);
    id=fork();

    if(id==-1)
    {
        perror("/nError: \n");
        return 0;
    }
    else if(id==0)
    {
        printf("\nChild reading...");
        read(fd[0],buf,10);
        printf("\nChild read: %s\n",buf);
    }
    else
    {
        printf("\nParent sending...");
        write(fd[1],"Data sent",10);
        printf("\nParent sent: Data sent\n");
    }
}