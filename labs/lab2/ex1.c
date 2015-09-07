#include <pthread.h>
#include <stdio.h>

void* printStuff()
{
  printf("Nova thread criada. TID = %u!\n",pthread_self());
  pthread_exit(NULL);
}

int main()
{
  pthread_t thread;
  pthread_create(&thread,NULL,printStuff,NULL);
  pthread_join(thread,NULL);
  pthread_exit(NULL);
}
