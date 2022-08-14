#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int random_generate(int min, int max){
   return min + rand()% (max - min + 1);
}

int main(int argc, char** argp){
    int n = atoi(argp[1]); // number of processes
    char string_rand [11];

    for (int i = 0; i < n; i++)
    {
        pid_t process_split = fork();
        if (-1 == process_split){
            perror("fork");
            return(EXIT_FAILURE);
        }

        if (0 == process_split){
            // child
            for (int j = 0; j < n; j++)
            {
                string_rand[j] = random_generate('a', 'z');
            }
            printf("%s\n", string_rand);
            return 0;
        } 
    }
    // parent
    for (int i = 0; i < n; i++) wait(NULL);
   
    return 0;
}
