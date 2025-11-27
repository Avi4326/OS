#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();    // create new process

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    printf("Process executing same code. PID = %d\n", getpid());
    return 0;
}
