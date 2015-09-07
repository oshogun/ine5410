#include <pthread.h>
#include <stdio.h>
#define MAX_THREADS 128

int contador_global;

void* doStuff()
{
  for(int i = 0; i < 100; i++) {
    contador_global++;
  }
  pthread_exit(NULL);
}

int main()
{
  contador_global = 0;
  pthread_t threads[MAX_THREADS];
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_create(&threads[i],NULL,doStuff,NULL);
  }
  for(int i = 0; i < MAX_THREADS; i++){
    pthread_join(threads[i],NULL);
  }
  printf("%d\n",contador_global);
  pthread_exit(NULL);
}
