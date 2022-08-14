#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define COUNT 3

typedef struct Book
{
    char title[150];
    char author[100];
    unsigned pages;
    double price;
} Book;

int write_binaryfile(const char *file_name, Book *book_arr, int count)
{
    FILE *file = fopen(file_name, "wb+");
    if (!file)
    {
        perror("Open file failed\n");
        return EXIT_FAILURE;
    }

    fwrite(book_arr, sizeof(Book), count, file);
    fclose(file);
    return EXIT_SUCCESS;
}

int random_generate(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    Book *book_array = malloc(sizeof(Book) * COUNT);
    if (!book_array)
    {
        perror("Malloc failed\n");
        return EXIT_FAILURE;
    }

    int length = random_generate(10, 20);
    for (int i = 0; i < COUNT; i++)
    {
        book_array[i].title[0] = random_generate('A', 'Z');
        book_array[i].author[0] = random_generate('A', 'Z');
        for (int j = 1; j < length; j++)
        {
            book_array[i].title[j] = random_generate('a', 'z');
            book_array[i].author[j] = random_generate('a', 'z');
        }
        book_array[i].pages = random_generate(5, 2000);
        book_array[i].price = random_generate(100, 100000) / 100.;
    }

    for (int i = 0; i < COUNT; i++)
    {
        printf("Book %d: %s %s %u %.2lf\n", i, book_array[i].title, book_array[i].author, book_array[i].pages, book_array[i].price);
    }

    write_binaryfile(argv[1], book_array, COUNT);

    free(book_array);
    return 0;
}