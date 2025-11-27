#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process Running. PID = %d\n", getpid());
        sleep(2);   // simulate some work
        printf("Child Completed.\n");
    }
    else {
        wait(NULL);     // parent waits for child
        printf("Parent Process. Child finished. Parent continues.\n");
    }

    return 0;
}
