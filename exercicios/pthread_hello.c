#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *PrintHello(void *arg);

int main(int argc, char**argv) {
    if (argc != 2) {
        printf("Usage: %s [NUM_THREADS]\n",argv[0]);
        return -1;
    }
    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i],NULL,PrintHello,NULL);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i],NULL);
    }
    pthread_exit(NULL);
}

void* PrintHello(void* arg) {
    int tid = pthread_self();
    printf("Thread %u says: HELLO! I AM A COMPUTER\n", tid);
    pthread_exit(NULL);
}
