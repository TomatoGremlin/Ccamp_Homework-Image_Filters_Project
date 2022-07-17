#include <stdio.h>

int main(){
// 2. XOR

 int num1, num2, num3, result;

 printf("Enter 0 or 1:\n");
 scanf(" %d", &num1);
 scanf(" %d", &num2);
 result = num1 ^ num2;

 printf("%d ^ %d = %d\n", num1, num2, result);

 printf("Enter 0 or 1:\n");
 scanf("%d", &num3);
 result ^= num3;
 printf("%d ^ %d ^ %d = %d\n", num1, num2, num3, result);

 return 0;
}
/*

Terminal:
gcc hw2zad2.c -o hw2_zad2
./hw2_zad2 < numbers.txt

*/