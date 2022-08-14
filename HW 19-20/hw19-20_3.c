#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void *routine1(void* arg){
    char* MSG= (char*)arg;
    printf("%s\n", MSG);
    printf("Process PID = %d, Thread ID = %ld\n\n", getpid(), pthread_self());
}

int main(int argc, char **argp)
{
    unsigned P = atoi(argp[1]);
    unsigned T = atoi(argp[2]);
    char* MSG = argp[3];
    pthread_t threads [T];

    for (int i = 0; i < P; i++)
    {
        pid_t process_split = fork();
        if (-1 == process_split){
            perror("fork");
            return(EXIT_FAILURE);
        }

        if (0 == process_split){
            // child
            for (size_t j = 0; j < T; j++)
            {
                if (pthread_create(&threads[j], NULL, routine1, argp[3]))
                {
                    perror("thread create");
                    return EXIT_FAILURE;
                }
            }
            for (size_t j = 0; j < T; j++)
            {
                if (pthread_join(threads[j], NULL))
                {
                    perror("join");
                    return EXIT_FAILURE;
                }
            }
            return 0;
        }
    }
    // parent
    for (int i = 0; i < P; i++) wait(NULL);

    return 0;
}
