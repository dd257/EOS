#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, const char *argv[])
{
    int fd=open("file",O_WRONLY);

    if(fd==-1)
    {
        perror("Error: ");
        return(0);
    }
    else
    {
        write(fd,"Writing to file",15);
        close(fd);
    }
}