#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, const char *argv[])
{
    char *fifo="file";
    int fd;

    mkfifo(fifo,S_IRWXG);
    fd=open(fifo,O_WRONLY);   

    if(fd==-1)
    {
        perror("\nError: \n");
        return 0;
    }
    else
        write(fd,"Data",4);
}