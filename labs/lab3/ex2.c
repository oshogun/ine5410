#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMPROD 5
#define NUMCONS 5

int buffer[15];
sem_t cheio,vazio,lock_prod,lock_cons;
int f = 0, j = 0;

void* prod() {
    while(1) {
        sem_wait(&vazio);
        sem_wait(&lock_prod);
        f= (f + 1) % 15;
        buffer[f]=(int)rand() % 100;
        printf("Thread %lu produzindo! buffer[%d]=%d!\n\n",pthread_self(),f,buffer[f]);
        sem_post(&lock_prod);
        sem_post(&cheio);
    }
    pthread_exit(NULL);
}
void* cons(){
    while(1) {
        sem_wait(&cheio);
        sem_wait(&lock_cons);
        j = (j + 1) % 15;
        printf("Thread %lu consumindo! buffer[%d]=%d! \n\n",pthread_self(),j,buffer[j]);
        sem_post(&lock_cons);
        sem_post(&vazio);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(void) {
    pthread_t produtoras[NUMPROD];
    pthread_t consumidoras[NUMCONS];
    srand(time(NULL));
    sem_init(&cheio,0,0);
    sem_init(&vazio,0,15);
    sem_init(&lock_prod,0,1);
    sem_init(&lock_cons,0,1);

    for (int i = 0; i < NUMPROD; i++)
        pthread_create(&produtoras[i],NULL,prod,NULL);
    for (int i = 0; i < NUMCONS; i++)
        pthread_create(&consumidoras[i],NULL,cons,NULL);
    for (int i = 0; i < NUMPROD; i++)
        pthread_join(produtoras[i],NULL);
    for (int i = 0; i < NUMCONS; i++)
        pthread_join(consumidoras[i],NULL);
    
    sem_destroy(&cheio);
    sem_destroy(&vazio);
    sem_destroy(&lock_prod);
    sem_destroy(&lock_cons);

    pthread_exit(NULL);

}
