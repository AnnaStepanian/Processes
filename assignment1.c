#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    printf("Parent process starting...\n");
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: Exiting...\n");
        exit(0);
    }
    else {
        printf("Parent process: My PID is %d\n", getpid());
        printf("Parent process: Child PID is %d\n", pid);
        printf("Parent process: Not waiting for child to complete\n");
        printf("Parent process: Exiting...\n");
    }
    
    return 0;
}
