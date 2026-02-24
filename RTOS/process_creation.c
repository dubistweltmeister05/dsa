#include <stdio.h>
#include <unistd.h>   // Contains fork(), getpid(), getppid()
#include <sys/types.h> // Defines pid_t datatype

/*
    PROCESS CREATION USING fork()

    fork() creates a new process (child).
    
    After fork():
        - Parent process receives child's PID (> 0)
        - Child process receives 0
        - On failure, fork() returns -1

    pid_t:
        It is a datatype used to store Process IDs.
        Every process in an OS has a unique PID.
*/

int main()
{
    pid_t pid;   // Variable to store the return value of fork()

    // getpid() returns the current process ID
    printf("Before fork: PID = %d\n", getpid());

    pid = fork();   // Create child process

    if (pid > 0) {
        /*
            This block executes ONLY in the parent process.

            pid > 0 means:
            - fork() returned child's PID
            - This process is the parent
        */
        printf("\n--- Parent Process ---\n");
        printf("Parent PID  = %d\n", getpid());  // Parent's own PID
        printf("Child PID   = %d\n", pid);       // Child's PID (returned by fork)
    }
    else if (pid == 0) {
        /*
            This block executes ONLY in the child process.

            pid == 0 means:
            - This is the child
        */
        printf("\n--- Child Process ---\n");
        printf("Child PID   = %d\n", getpid());   // Child's own PID
        printf("Parent PID  = %d\n", getppid());  // Parent's PID
    }
    else {
        // fork failed
        printf("Fork failed!\n");
    }

    return 0;
}
