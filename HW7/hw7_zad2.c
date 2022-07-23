#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n){
    
    unsigned sum = 0;
    int digit = 0;
    int num = 0;

    for(int i = 0 ; i < n ; i++ ){
        
        num = arr [i];
        while (num)
        {
            digit = num % 10;
            sum += digit;
            num /= 10;
        }
    }
    return sum;
}

int main(){

    int arr []= {12,34,5,70};
    printf("%u\n", sumArrayDigits(arr, 4));

    return 0;
}