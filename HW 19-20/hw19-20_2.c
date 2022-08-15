#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int comparator(const void *p, const void *q)
{
    int l = *(const int *)p;
    int r = *(const int *)q;

    if ((l&1) && (r&1))
        return (r-l);
  
    
    if ( !(l&1) && !(r&1) )
        return (l-r);
  

    if (!(l&1))
        return 1;

    return -1;
}

void *routine1(void* arg){
    char* file_name = (char*) arg;
    FILE* read_binary = fopen(file_name, "rb");
    FILE* write = fopen(file_name, "wb+");
    
    int lines = 0 ;
    char new_line = getc(read_binary);
    while (new_line != EOF)
    {
        if (new_line == '\n')
            lines++;
        new_line = getc(read_binary);
    }

    rewind(read_binary);
    int number [lines];
   
    fread( number, sizeof(int), lines , read_binary);
    
    qsort(number, lines , sizeof(int), comparator);
    
    for (size_t i = 0; i < lines; i++)
    {
        fprintf(write, "%d\n", number[i]);
    }

    fclose(read_binary);
    fclose(write);
}

int main(int argc, char **argp)
{
   
    pthread_t threads[argc - 1];

    for (int i = 0; i < argc-1; i++)
    {
        if (pthread_create(&threads[i], NULL, routine1, &argp[i+1]))
        {
            perror("thread create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < argc-1; i++)
    {
        if (pthread_join(threads[i], NULL))
        {
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}
