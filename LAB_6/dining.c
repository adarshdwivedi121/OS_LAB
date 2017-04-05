#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <zconf.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2

int n;
pthread_mutex_t mutex;
sem_t *S;
pthread_t *P;

int *state;
int *phil_num;

void *philospher(void *num);
void take_fork(int ph_num);
void test(int ph_num);
void put_fork(int ph_num);

int main() {
    int i;
    printf("\nEnter the Number of Philosophers.");  scanf("%d", &n);

    S = (sem_t *) malloc(n * sizeof(sem_t));
    P = (pthread_t *) malloc(n * sizeof(pthread_t));

    state = (int *)malloc(n * sizeof(int));
    phil_num = (int *)malloc(n * sizeof(int));
    pthread_mutex_init(&mutex, NULL);

    for(i=0; i<n; i++){
        phil_num[i] = i;
        sem_init(&S[i], 0, 0);
        pthread_create(&P[i], NULL, philospher, &phil_num[i]);
        printf("\nPhilosopher %d is THINKING.", i+1);
    }
    for(i=0; i<n; i++)
        pthread_join(P[i], NULL);
}

void *philospher(void *num) {
    int *i = num;
    sleep(1);
    take_fork(*i);
    sleep(0);
    put_fork(*i);
    return NULL;
}

void take_fork(int ph_num)
{
    pthread_mutex_lock(&mutex);
    state[ph_num] = HUNGRY;
    printf("\nPhilosopher %d is HUNGRY",ph_num+1);
    test(ph_num);
    pthread_mutex_unlock(&mutex);
    sem_wait(&S[ph_num]);
    sleep(1);
}

void test(int ph_num)
{
    if (state[ph_num] == HUNGRY && state[(ph_num+n-1)%n] != EATING && state[(ph_num+1)%n] != EATING)
    {
        state[ph_num] = EATING;
        sleep(2);
        printf("\nPhilosopher %d Takes Forks %d and %d.",ph_num+1,(ph_num+n-1)%n+1,ph_num+1);
        printf("\nPhilosopher %d is EATING",ph_num+1);
        sem_post(&S[ph_num]);
    }
}

void put_fork(int ph_num)
{
    pthread_mutex_lock(&mutex);
    state[ph_num] = THINKING;
    printf("\nPhilosopher %d Put Down Forks %d and %d",ph_num+1,(ph_num+n-1)%n+1,ph_num+1);
    printf("\nPhilosopher %d is THINKING",ph_num+1);
    test((ph_num+n-1)%n);
    test((ph_num+1)%n);
    pthread_mutex_unlock(&mutex);
}
