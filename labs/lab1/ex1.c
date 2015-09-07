#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    fork();
    printf("Novo processo criado!\n");
}
