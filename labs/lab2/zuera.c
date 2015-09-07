#include <pthread.h>
#include <stdio.h>
#define MAX_THREADS 2

int contador_global;
pthread_mutex_t mutex;

void* doStuff()
{
  for(int i = 0; i < 100; i++) {
    pthread_mutex_lock(&mutex);
    contador_global++;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main()
{
  contador_global = 0;
  pthread_mutex_init(&mutex,NULL);
  pthread_t threads[MAX_THREADS];
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_create(&threads[i],NULL,doStuff,NULL);
  }
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_join(threads[i],NULL);
  }
  printf("%d\n",contador_global);
  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);
}
