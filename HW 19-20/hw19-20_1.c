#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int random_generate(int min, int max){
   return min + rand()% (max - min + 1);
}
void *routine1(void* arg){
    int length = 10;
    char string_rand [length+1];
    for (int j = 0; j < length; j++)
    {
        string_rand[j] = random_generate('a', 'z');
    }
    printf("%s\n", string_rand);
}

int main(int argc, char **argp)
{
    unsigned N = atoi(argp[1]);
    pthread_t threads[N];

    for (int i = 0; i < N; i++)
    {
        if (pthread_create(&threads[i], NULL, routine1, NULL))
        {
            perror("thread create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (pthread_join(threads[i], NULL))
        {
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}