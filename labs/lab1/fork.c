#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();

    if(pid >= 0) {
        if (pid == 0)
            puts("Sou o filho");
        else {
            printf("Sou o papai\n");
            wait(NULL);
        }
        return 0;
    } else {
        printf("Não pode criar o rpocesso\n");
        return -1;
    }
}
