#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status1, status2;
    
    printf("Parent process starting...\n");
    printf("Parent PID: %d\n\n", getpid());
    
    pid1 = fork();
    
    if (pid1 < 0) {
        fprintf(stderr, "First fork failed\n");
        exit(1);
    }
    else if (pid1 == 0) {
        printf("Child 1: My PID is %d\n", getpid());
        printf("Child 1: Exiting with status 5\n");
        exit(5);
    }
    else {
        printf("Parent: Created child 1 with PID %d\n", pid1);
        
        pid2 = fork();
        
        if (pid2 < 0) {
            fprintf(stderr, "Second fork failed\n");
            exit(1);
        }
        else if (pid2 == 0) {
            printf("Child 2: My PID is %d\n", getpid());
            printf("Child 2: Exiting with status 10\n");
            exit(10);
        }
        else {
            printf("Parent: Created child 2 with PID %d\n", pid2);
            
            printf("Parent: Waiting for child 1 using waitpid()...\n");
            pid_t waited_pid1 = waitpid(pid1, &status1, 0);
            if (WIFEXITED(status1)) {
                printf("Parent: Child %d exited normally with status %d\n", waited_pid1, WEXITSTATUS(status1));
            } else {
                printf("Parent: Child %d exited with error\n", waited_pid1);
            }
            
            printf("Parent: Waiting for child 2 using waitpid()...\n");
            pid_t waited_pid2 = waitpid(pid2, &status2, 0);
            if (WIFEXITED(status2)) {
                printf("Parent: Child %d exited normally with status %d\n", waited_pid2, WEXITSTATUS(status2));
            } else {
                printf("Parent: Child %d exited with error\n", waited_pid2);
            }
            
            printf("Parent: All children completed. Exiting...\n");
        }
    }
    
    return 0;
}
