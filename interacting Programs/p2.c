#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, const char *argv[])
{
    int fd=open("file",O_RDONLY);
    char c[50];

    if(fd==-1)
    {
        perror("Error: ");
        return(0);
    }
    else
    {
        read(fd,c,100);
        printf("\nText in File: %s\n",c);
        close(fd);
    }
}