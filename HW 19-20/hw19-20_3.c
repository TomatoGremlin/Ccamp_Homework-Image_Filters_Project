#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *routine1(void* arg){
    
    printf("%s\n", arg);
}

int main(int argc, char **argp)
{
    unsigned P = atoi(argp[1]);
    unsigned T = atoi(argp[2]);
    char* MSG[] = argp[3];
    pthread_t threads [T];

    for (int i = 0; i < P; i++)
    {
        for (size_t j = 0; j < T; j++)
        {
            if (pthread_create(&threads[j], NULL, routine1, NULL))
            {
                perror("thread create");
                return EXIT_FAILURE;
            }
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