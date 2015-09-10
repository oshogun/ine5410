#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t cheio,vazio,lock_prod,lock_cons;
int bafer_circular[10];
int i = 0;
int j = 0;
void* produzir()
{
    sem_wait(&vazio);
    sem_wait(&lock_prod);
    i = (i+1)%10;
    bafer_circular[i] = i;
    sem_post(&lock_prod);
    sem_post(&cheio);
    pthread_exit(NULL);
}

void* consumir()
{
    sem_wait(&cheio);
    sem_wait(&lock_cons);
    j = (j+1)%10;
    printf("%d\n",bafer_circular[j]);
    sem_post(&lock_cons);
    sem_post(&vazio);
    pthread_exit(NULL);
}
int main(int argc, char** argv)
{
    pthread_t prods[10];
    pthread_t cons[10];
    sem_init(&cheio,0,0);
    sem_init(&vazio,0,10);
    sem_init(&lock_prod,0,1);
    sem_init(&lock_cons,0,1);
    for(int i = 0; i < 10; i++) {
        pthread_create(&prods[i],NULL,produzir,NULL);
        pthread_create(&cons[i],NULL,consumir,NULL);
  }
    for(int i = 0; i < 10; i++) {
        pthread_join(prods[i],NULL);
        pthread_join(cons[i],NULL);
    }
    sem_destroy(&cheio);
    sem_destroy(&vazio);
    sem_destroy(&lock_prod);
    sem_destroy(&lock_cons);
    pthread_exit(NULL);
}
