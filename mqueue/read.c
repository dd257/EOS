#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t mq;
struct mq_attr mq_attr;

int main(int argc, int *argv[])
{
    char buff[128];
    int mq_p;

    mq_attr.mq_flags=0;
    mq_attr.mq_maxmsg=3;
    mq_attr.mq_msgsize=128;
    mq_attr.mq_curmsgs=0;

    mq=mq_open("/mq",O_RDONLY|O_CREAT,S_IWUSR|S_IRUSR,&mq_attr);
    
    if(mq==-1)
    {
        perror("Error: ");
        return 0;
    }
    else
    {
        mq_receive(mq,buff,128,&mq_p);

        printf("\nRead: %s\nMessage priority: %d\n",buff,mq_p);
        
        mq_close(mq);
    }
}
