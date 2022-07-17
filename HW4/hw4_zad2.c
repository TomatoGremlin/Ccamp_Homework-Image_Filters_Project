#include <stdio.h>
#include <stdint.h>

void Attendance()
{
    uint64_t attendance = 0;  
    int option;
    int student;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");

        scanf("%d", &option);
        if (1 == option)
        {
            //scanf( "Which student? %d", &student);
            student = 0;
            attendance |= (1ULL << student); // set bit
        }
        else if (2 == option)
        {
            attendance &= ~(1ULL << student); // clear bit
        }
        else if (3 == option) //print
        {
           printf("Attendances:\n");
           for(int bit = sizeof(attendance)*__CHAR_BIT__-1; bit >= 0; bit --)
           {
            printf("%d",!!(attendance & (1ULL << bit)));
           }
           putchar('\n');
        }
        else if (4 == option)
        {
           attendance ^= (1ULL << student); //flip bit
        }
        else if (5 == option) break;
    
    }
}

int main(){
    Attendance();
    return 0;   
}