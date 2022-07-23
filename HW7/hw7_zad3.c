#include <stdio.h>

int sum(int* arr, int n){
    
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

void arrayEvaluate ( int* arr, size_t n, int (*f) (int*, int) ){

 printf("Value: %d", f(arr, n));

}

int main(){
    int arr [] = {1,2,3};

    arrayEvaluate(arr, 3, sum);
    return 0;
}