# Operating Systems - Process Management

This repository contains C programs demonstrating process creation and management concepts in operating systems.

## Assignments

### Assignment 1 (`assignment1.c`)
Demonstrates basic process creation using `fork()` system call:
- Creates a child process
- Shows process IDs (PIDs) of both parent and child
- Parent process exits without waiting for child completion

### Assignment 2 (`assignment2.c`)
Demonstrates advanced process management:
- Creates two child processes using `fork()`
- Shows different process waiting mechanisms:
  - `wait()` - waits for any child process
  - `waitpid()` - waits for a specific child process
- Captures and displays exit status of child processes

## Compilation

To compile the programs:

```bash
gcc -o assignment1 assignment1.c
gcc -o assignment2 assignment2.c
```

## Running the Programs

```bash
./assignment1
./assignment2
```

## System Requirements

- Unix-like operating system (Linux, macOS)
- GCC compiler
- POSIX-compliant system calls support
