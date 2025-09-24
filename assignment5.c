#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    int use_wait = 1;  // Change to 0 to demonstrate zombie
    
    printf("=== Assignment 5: Zombie Process Demonstration ===\n\n");
    
    printf("Parent process starting...\n");
    printf("Parent PID: %d\n\n", getpid());
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: Exiting in 3 seconds...\n");
        sleep(3);
        printf("Child process: Exiting now\n");
        exit(0);
    }
    else {
        printf("Parent: Created child with PID %d\n", pid);
        
        if (use_wait) {
            printf("Parent: Using wait() to prevent zombie\n");
            printf("Parent: Waiting for child to complete...\n");
            
            pid_t waited_pid = wait(&status);
            
            if (WIFEXITED(status)) {
                printf("Parent: Child %d exited normally with status %d\n", waited_pid, WEXITSTATUS(status));
            } else {
                printf("Parent: Child %d exited with error\n", waited_pid);
            }
            
            printf("Parent: Child process cleaned up - no zombie created\n");
        } else {
            printf("Parent: NOT using wait() - child will become zombie\n");
            printf("Parent: Sleeping for 10 seconds to observe zombie\n");
            printf("Run 'ps aux | grep assignment5' in another terminal to see zombie\n");
            sleep(10);
            printf("Parent: Exiting after 10 seconds\n");
        }
        
        printf("Parent: Exiting now\n");
    }
    
    return 0;
}
