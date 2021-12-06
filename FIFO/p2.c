#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, const char *argv[])
{
    char *fifo="file", *buff;
    int fd;

    mkfifo(fifo,S_IRWXG);
    fd=open(fifo,O_RDONLY);   

    if(fd==-1)
    {
        perror("\nError: \n");
        return 0;
    }
    else
    {
        read(fd,buff,4);
        printf("\nRead = %s\n",buff);
    }    
}