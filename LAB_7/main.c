#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 10

sem_t mayProduce, mayConsume;
pthread_t prod[5], cons[5];
pthread_mutex_t mutex;
int np, nc;
int counter;
int BUFFER[BUFFER_SIZE];

void initialize();
void *producer();
void *consumer();

int main() {
    printf("\nEnter No. of Producers");
    scanf("%d", &np);
    printf("\nEnter No. of Consumers");
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
}

void initialize(){
    pthread_mutex_init(&mutex, )
}