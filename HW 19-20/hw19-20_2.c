#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int comparator(const void *p, const void *q)
{
    // Get the values at given addresses
    int l = *(const int *)p;
    int r = *(const int *)q;
  
    // both odd, put the greater of two first.
    if ((l&1) && (r&1))
        return (r-l);
  
    // both even, put the smaller of two first
    if ( !(l&1) && !(r&1) )
        return (l-r);
  
    // l is even, put r first
    if (!(l&1))
        return 1;
  
    // l is odd, put l first
    return -1;
}

void *routine1(void* arg){
    FILE* read_binary = fopen("file[i]", "rb");
    FILE* write_decimal = fopen("file[i]", "w+");
    
    int lines = 0 ;
    while (EOF)
    {
        lines ++;
    }
    rewind(read_binary);
    int number [10];
   
    fread( number, sizeof(int), lines , read_binary);
    
    qsort(number, 10 , sizeof(int), comparator);
    
    for (size_t i = 0; i < 10; i++)
    {
        fprintf(write, "%d\n", number[i]);
    }

    fclose(read_binary);
    fclose(write_decimal);
}

int main(int argc, char **argp)
{
    unsigned files = argc - 1;
    pthread_t threads[files];

    for (int i = 0; i < files; i++)
    {
        if (pthread_create(&threads[i], NULL, routine1, NULL))
        {
            perror("thread create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < files; i++)
    {
        if (pthread_join(threads[i], NULL))
        {
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}