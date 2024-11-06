#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
sem_t full,empty,mutex;
int in=0,out=0;

void *producer(void *arg)
{
    for(int i=0;i<NUM_ITEMS;i++)
    {
        int item=rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        
        buffer[in]=item;
        printf("Produced:%d\n",item); //removed \n
        in=(in+1)%BUFFER_SIZE;
        
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg)
{
    for(int i=0;i<NUM_ITEMS;i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        
        int item=buffer[out];
        printf("Consumed:%d\n",item);  //removed \n
        out=(out+1)%BUFFER_SIZE;
        
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t prod,cons;
    
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&mutex,0,1);
    
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);
    
    pthread_join(prod,NULL);
    pthread_join(cons,NULL);
    
    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&mutex);
    
    return 0;
}

