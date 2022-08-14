#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int fork_process(const char *command)
{
    pid_t pid1 = fork();
    if (0 == pid1)
    {
        // child 
        if (-1 == execlp(command, command, NULL))
        {
            perror("exec error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // parent 
        int return_status;
        wait(&return_status);
        if (return_status)
        {
            fprintf(stderr, "First command error");
            return -1;
        }
        return WIFEXITED(return_status);
    }
}
int main(int argc, char **argp)
{
    if(argc < 3){
        fprintf(stderr, "Not enough arguments.\n");
        return -1;
    }

    int status = fork_process(argp[1]);
    
    if (status)
    {
        return EXIT_FAILURE;
    }
    
    status = fork_process(argp[2]);

    return EXIT_SUCCESS;
}
