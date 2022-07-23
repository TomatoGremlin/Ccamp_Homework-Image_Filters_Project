#include <stdio.h>
int SecondMax (const int* arr, size_t n, int* secondMax){
    
    if (arr == NULL)
    {
        printf("Error! The array is empty\n");
        return -1;
    }
    if (n == 1)
    {
        printf("Error! The array has only one element\n");
        return -1;
    }

    int maximum = arr[0];
    int equal = 1;
    for(int i = 1;i < n; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
            equal = 0;
        }
    }
    if(equal == 1){
        printf("Error! The array elements are all equal\n");
        return -1;
    } 
    
    *secondMax = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > *secondMax && arr[i]!=maximum) {
            *secondMax = arr[i];
           
        }
    }
    return *secondMax;
}

int main(){
    int secondMax;
    int arr[] = {13,34, 5, 70, 46};
    int arr2[] = {22, 22, 22, 22, 22};
    int arr3[] = {30};
    printf("%d\n", SecondMax(arr, 5, &secondMax));
    printf("%d\n", SecondMax(arr2, 5, &secondMax));
    printf("%d\n", SecondMax(arr3, 1, &secondMax));
    return 0;
}