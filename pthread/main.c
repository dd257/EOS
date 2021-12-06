#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *greet(void *arg)
{
    printf("\npthread: %s",arg);
}

int main(int argc, const char *argv[])
{
    pthread_t id;
    printf("\nBefore Thread\n");
    pthread_create(&id, NULL, greet, "Hello");
    pthread_join(id, NULL);
    pthread_create(&id, NULL, greet, "Goodbye");
    pthread_join(id, NULL);
    printf("\nAfter Thread\n");
}
