#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>
#include<stdarg.h>

char* itoa(int val, int base){

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= base)

        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];
}

int my_fprintf(FILE *stream,  char *format, ...){
   va_list arguments; 
   va_start(arguments,format);
   int position = 0;
   char* string = malloc(sizeof(char)* strlen(format));

   while (format[position])
   {
       if (format [position]== '%')
       {
           if( format[position + 1] == 'u') 
           {
               char* number ;
               number = itoa(va_arg(arguments, int), 10);
               string = realloc(string, sizeof(char)* 5);
               strcpy(&string[position], number);
               break;
           }
           else if( format[position + 1] == 'l' && format[position + 2] == 'f' ) 
           {
               char number [20];
               double n = va_arg(arguments, double);
               gcvt(n, 3, number);
               
               string = realloc(string, sizeof(char)* 10);
               strcpy(&string[position], number);
               break;
           }
            else if( format[position + 1] == 'c')
           {
               char ch = (char)va_arg(arguments, int);
               string[position] = ch ;
               break;
           }
           else if( format[position + 1] == 's')
           {
               string = realloc(string, sizeof(char)* 5);
               strcpy(&string[position], va_arg(arguments, char*));
               break;
           }
           
       }
       string[position] = format[position];
       ++position;
   }
   fwrite(string, sizeof(char), strlen(string), stream ); 
   va_end(arguments); 
   free(string);
}

int main(){
    FILE* f = fopen("print","w+");
    
    my_fprintf(f,"Wrote %c", 'B');
    fprintf(f,"\n");
    my_fprintf(f,"Wrote %u", 16);
    fprintf(f,"\n");
    my_fprintf(f,"Wrote %lf", 1.5);
    fprintf(f,"\n");
    my_fprintf(f,"Wrote %s", "OK");
    
    fclose(f);
    return 0;
}