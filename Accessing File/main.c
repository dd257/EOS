#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argv, const char *argc[])
{
    char *s=(char*)calloc(1,sizeof(char));
    int c=1;
    int fd = open("hello",O_RDWR);
    if(fd==-1)
    {
        perror("Error: ");
    }
    else
    {
        //printf("\nFile Opened\n");
        while(c)
            c=read(fd,s,1);

        write(fd,"HELLO",5);
        printf("\nText added at end of file\n");
    }
    printf("\nfd = %d\n",fd);

    close(fd);
}

