#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void printStuff();

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printStuff();
        return 0;
    } else {
        pid_t pid2 = fork();
        if(pid2 == 0) {
            printStuff();
            return 0;
        }
        pid_t pid3 = fork();
        if(pid3 == 0) {
            printStuff();
            return 0;
        }
        pid_t pid4 = fork();
        if(pid4 == 0) {
            printStuff();
            return 0;
        }
       wait(NULL);
       return 0;
    }       
}

void printStuff() {
    printf("Processo pai %d criou %d\n",getppid(),getpid());
}
