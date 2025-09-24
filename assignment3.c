#include <stdio.h>
#include <stdlib.h>

void cleanup1() {
    printf("Cleanup 1: Closing files\n");
}

void cleanup2() {
    printf("Cleanup 2: Saving data\n");
}

int main() {
    printf("Program starting...\n");
    
    atexit(cleanup1);
    atexit(cleanup2);
    
    printf("Cleanup functions registered\n");
    printf("Functions execute in REVERSE order (LIFO)\n\n");
    
    printf("Test 1: exit() early in program\n");
    printf("Calling exit(0) - cleanup functions will execute:\n");
    exit(0);
    
    printf("This line will never be reached\n");
    return 0;
}
