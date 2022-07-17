#include <stdio.h>

int main(){
// 1.
 double num;
 double max = 0.0;
 printf("Enter 3 real numbers:\n");
 for (int i = 0; i < 3; i++)
 {
    scanf(" %lf", &num);
    if( num > max){
        max = num;
    }
 }
 printf("Biggest number = %lf\n", max);
 return 0;
}
/*

Terminal:
gcc hw2.c -o hw2
./hw2 < numbers.txt

*/