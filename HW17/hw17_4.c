#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argp) {
    int file_descriptors[2];
    if (pipe(file_descriptors) == -1) {
        return EXIT_FAILURE;
    }
    
    int pid1 = fork();
    if (pid1 < 0) {
        return EXIT_FAILURE;
    } 
    if (pid1 == 0) {
        // Child  1 
        dup2(file_descriptors[1], STDOUT_FILENO);
        close(file_descriptors[0]);
        close(file_descriptors[1]);
        execlp(argp[1], argp[1], NULL);
    }
    
    int pid2 = fork();
    if (pid2 < 0) {
        return EXIT_FAILURE;
    }
    if (pid2 == 0) {
        // Child 2 
        dup2(file_descriptors[0], STDIN_FILENO);
        close(file_descriptors[0]);
        close(file_descriptors[1]);
        execlp(argp[2], argp[2], NULL);
    }

    //parent
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    
    return 0;
}