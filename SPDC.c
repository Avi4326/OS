#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process. PID = %d\n", getpid());
        printf("Child executing its own code.\n");
    }
    else {
        printf("Parent Process. PID = %d\n", getpid());
        printf("Parent executing parent code.\n");
    }

    return 0;
}
