#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

sem_t mayProduce, mayConsume;
pthread_t prod[BUFFER_SIZE], cons[BUFFER_SIZE];
pthread_mutex_t mutex;
int np, nc;
int counter;
int buffer[BUFFER_SIZE];

void initialize();
void *producer();
void *consumer();

int main() {
    initialize();
    printf("\nEnter No. of Producers : ");
    scanf("%d", &np);
    printf("\nEnter No. of Consumers : ");
    scanf("%d", &nc);

    int i;
    for(i=0; i<np; i++)
        pthread_create(&prod[i], NULL, producer, NULL);
    for(i=0; i<nc; i++)
        pthread_create(&cons[i], NULL, consumer, NULL);
    for(i=0; i<np; i++)
        pthread_join(&prod[i], NULL);
    for(i=0; i<nc; i++)
        pthread_join(&cons[i], NULL);

    return 0;
}

void initialize(){
    pthread_mutex_init(&mutex, NULL);
    sem_init(&mayProduce, 0, 0);
    sem_init(&mayConsume, 0, BUFFER_SIZE);
    counter = 0;
}

void *producer(){
    sem_wait(&mayConsume);
    pthread_mutex_lock(&mutex);
    buffer[counter++] = counter;
    pthread_mutex_unlock(&mutex);
    sem_post(&mayProduce);
}

void *consumer(){
    if(counter==0)  exit(0);
    sem_wait(&mayProduce);
    pthread_mutex_lock(&mutex);
    printf("\nConsumer has Value : %d", buffer[--counter]);
    pthread_mutex_unlock(&mutex);
    sem_post(&mayConsume);
}