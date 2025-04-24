#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to create a new process
pid_t create_process() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return -1;
    }
    
    return pid;
}

// Function to demonstrate process management
void process_demo() {
    printf("Process Management Demo\n");
    printf("----------------------\n");
    
    pid_t pid = create_process();
    
    if (pid == 0) {
        // Child process
        printf("Child Process (PID: %d)\n", getpid());
        sleep(2);
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent Process (PID: %d)\n", getpid());
        printf("Waiting for child process to complete...\n");
        
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        }
    }
}

int main() {
    process_demo();
    return 0;
} 