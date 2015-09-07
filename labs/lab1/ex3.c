#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void printStuff();

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            printStuff();
            pid_t pid3 = fork();
            if (pid3 == 0) {
                printStuff();
                return 0;
            } else {
                pid_t pid4 = fork();
                if (pid4 == 0) {
                    printStuff();
                    return 0;
                }
            }
        }
        wait(NULL);
    } else {
        printStuff();
        pid_t pid5 = fork();
        if (pid5 == 0) {
            printStuff();
            return 0;
        } else {
            pid_t pid6 = fork();
            if (pid6 == 0) {
                printStuff();
                return 0;
            }
        }
        wait(NULL);
    }
}

void printStuff() {
    printf("Processo %u filho de %u\n",getpid(),getppid());
}
