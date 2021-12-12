#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_barrier_t pb;

void *spi(void *arg)
{
    printf("SPI initialisation started..\n");
    sleep(2);
    pthread_barrier_wait(&pb);
    printf("SPI Initialised\n");
}

void *uart(void *arg)
{
    printf("UART initialisation started..\n");
    sleep(3);
    pthread_barrier_wait(&pb);
    printf("UART Initialised\n");
}

void *ethernet(void *arg)
{
    printf("Ethernet initialisation started..\n");
    sleep(6);
    pthread_barrier_wait(&pb);
    printf("Ethernet Initialised\n");
}

void *i2c(void *arg)
{
    printf("I2C initialisation started..\n");
    sleep(2);
    pthread_barrier_wait(&pb);
    printf("I2C Initialised\n");
}

int main(int argc, int argv[])
{
    pthread_t _spi,_uart,_ethernet,_i2c;

    pthread_barrier_init(&pb,NULL,4);

    pthread_create(&_spi,NULL,spi,NULL);
    pthread_create(&_uart,NULL,uart,NULL);
    pthread_create(&_ethernet,NULL,ethernet,NULL);
    pthread_create(&_i2c,NULL,i2c,NULL);
    
    pthread_join(_spi,NULL);
    pthread_join(_uart,NULL);
    pthread_join(_ethernet,NULL);
    pthread_join(_i2c,NULL);

}