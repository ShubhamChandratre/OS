#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_READS 3
#define NUM_READERS 3
#define NUM_WRITES 3

sem_t rw_mutex;
sem_t mutex;
int read_count=0;
int shared_data=0;

void *reader(void *arg)
{
    for(int i=0;i<NUM_READS;i++)
    {
        sem_wait(&mutex);
        read_count++;
        if(read_count==1){
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);
        
        printf("Reader %ld Reads:%d\n",(long)arg,shared_data);
        sleep(1);
        
        sem_wait(&mutex);
        read_count--;
        if(read_count==0){
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);
        sleep(1);
    }
    return NULL;
    
}

void *writer(void *arg)
{
    for(int i=0;i<NUM_WRITES;i++)
    {
        sem_wait(&rw_mutex);
        shared_data=rand()%100;
        printf("Writer writes:%d\n",shared_data);
        sleep(1);
        
        sem_post(&rw_mutex);
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t r_threads[NUM_READERS];
    pthread_t w_thread;
    
    sem_init(&rw_mutex,0,1);
    sem_init(&mutex,0,1);
    
    for(long i=0;i<NUM_READERS;i++){
        pthread_create(&r_threads[i],NULL,reader,(void *)i);
    }
    pthread_create(&w_thread,NULL,writer,NULL);
    
    for(int i=0;i<NUM_READS;i++){
        pthread_join(r_threads[i],NULL);
    }
    pthread_join(w_thread,NULL);
    
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    
    return 0;

}







