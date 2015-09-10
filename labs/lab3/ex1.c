#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define MAX_THREADS 128

int contador_global;
sem_t binario;

void* doStuff()
{
  for(int i = 0; i < 100; i++) {
    sem_wait(&binario);
    contador_global++;
    sem_post(&binario);
  }
  pthread_exit(NULL);
}

int main()
{
  contador_global = 0;
  sem_init(&binario,0,1);
  pthread_t threads[MAX_THREADS];
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_create(&threads[i],NULL,doStuff,NULL);
  }
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_join(threads[i],NULL);
  }
  printf("%d\n",contador_global);
  sem_destroy(&binario);
  pthread_exit(NULL);
}
