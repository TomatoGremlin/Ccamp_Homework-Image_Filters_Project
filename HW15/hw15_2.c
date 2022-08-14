#include<stdio.h>
#include<stdlib.h>
#define COUNT 3
typedef struct Book
{
    char title[150];
    char author[100];
    unsigned pages;
    double price;
}Book;

typedef struct Node {  
    Book book;  
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *curNode = head;
    while(curNode) {
        printf("addr: %p,  Book: %s %s %u %.2lf , next: %p\n",
        curNode, curNode->book.title, curNode->book.author,  curNode->book.pages,  curNode->book.price, curNode->next);
        curNode = curNode->next;
    }
}
int read_binaryfile(const char* file_name, Node *head, int count){
    FILE* file = open(file_name, "rb");
    if (!file)
    {
        perror("Open file failed\n");
        return EXIT_FAILURE;
    }
    
    fread(&head->book, sizeof(head->book), count, file);
    fclose(file);
    return EXIT_SUCCESS;
}

int write_textfile(const char* file_name, Node* head, int count){
    FILE* file = open(file_name, "w+");
    if (!file)
    {
        perror("Open file failed\n");
        return EXIT_FAILURE;
    }
    Node* curNode = head;
    for (int i = 0; i < COUNT; i++)
    {
        fprintf(file, "Book %d:\n", i);
        fprintf(file, "%s %s %u %.2lf\n\n", curNode->book.title, curNode->book.author,  curNode->book.pages,  curNode->book.price);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char** argv) {
    Node *book_list = malloc(sizeof(Node)*COUNT);
    if (!book_list)
    {
        perror("Malloc failed\n");
        return EXIT_FAILURE;
    }
    read_binaryfile( argv[1], book_list, COUNT) ;
    print_list(book_list);

    write_textfile(argv[2], book_list, COUNT);
   
    free(book_list);
}