#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int x;

void *areaCritica() {
    pthread_mutex_lock(&mutex);
    x++;
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_mutex_init(&mutex,NULL);
    pthread_t threads[2];
    x = 0;
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i],NULL,areaCritica,NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("%d\n",x);
    pthread_exit(NULL);
}
