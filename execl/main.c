#include<stdio.h>
#include<unistd.h>

int main(int argc, int argv[])
{
    char cmd[100];

    while(cmd!=" ")
    {
        printf("/nEnter command (e.g: /bin/ls) or space to exit: ");
        scanf("%s",cmd);

        printf("/nBefore execl");
        execl(cmd,cmd,NULL);
        printf("After exec"); //Does not print
    }
}