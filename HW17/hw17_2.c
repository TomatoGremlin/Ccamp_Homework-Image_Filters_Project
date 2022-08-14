#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char** argp){
    int n = argc - 1 ; // number of integers
    int sum;

    int file_descriptors[2]; // 0 = read,  1 = write  
    if (pipe(file_descriptors) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t process_split = fork();
    if (-1 == process_split)
    {
        perror("fork");
        return (EXIT_FAILURE);
    }

    if (0 == process_split)
    {
        // child
        for (size_t i = 1; i <= n / 2; i++)
        {
            sum += atoi(argp[i]);
        }
        write(file_descriptors[1], &sum, sizeof(sum));
        close(file_descriptors[1]);
    }else{
        // parent
        for (size_t i = (n / 2) + 1; i <= n; i++)
        {
            sum += atoi(argp[i]);
        }
        wait(NULL);

        int sumChild;
        read(file_descriptors[0], &sumChild, sizeof(sumChild));

        printf("Sum = %d\n", sum+sumChild);

        close(file_descriptors[0]);
    }
    return 0;
}
