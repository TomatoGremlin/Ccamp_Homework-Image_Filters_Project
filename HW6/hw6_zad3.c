#include <stdio.h>
#include <stdint.h>
// 3.

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printValue(const void* valuePtr, uint8_t flag){

    if (TINT == flag)
    {
        printf("%d\n", *(int*)valuePtr);
    }
    else if (TCHAR == flag)
    {
        printf("%c\n", *(char*)valuePtr);
    }
    else if (TDOUBLE == flag){
        printf("%lf\n", *(double*)valuePtr);
    }
    else if (TFLOAT == flag)
    {
        printf("%f\n", *(float*)valuePtr);
    }
    else if (TUINT8 == flag)
    {
        printf("%u\n", *(uint8_t*)valuePtr);
    }
    else if (TUINT16 == flag)
    {
        printf("%ul\n", *(uint16_t*)valuePtr);

    }
    else if (TUINT32 == flag)
    {
        printf("%ull\n", *(uint32_t*)valuePtr);

    }
    else
    {
        printf("%lu\n", *(uint64_t*)valuePtr);
    }
     
}

int main(){

    int num = 23;
    double num2 = 3.14;
    char symbol = 'A';

    printValue(&num, TINT);
    printValue(&num2, TDOUBLE);
    printValue(&symbol, TCHAR);

    return 0;
}