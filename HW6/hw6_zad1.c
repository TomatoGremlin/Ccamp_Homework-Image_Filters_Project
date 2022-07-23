#include<stdio.h>
float SquareRoot (int number){
    float temp, sqroot;
    // store the half of the given number e.g from 256 => 128
    sqroot = number / 2;
    temp = 0;
    // Iterate until sqrt is different of temp, that is updated on the loop
    while(sqroot != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = sqroot;

        // Then, replace values (256 / 128 + 128 ) / 2 = 65
        // (on second iteration 34.46923076923077)
        // and so on
        sqroot = ( number/temp + temp) / 2;
    }
  return sqroot;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("The square root of %d is %f", number, SquareRoot(number));
    return 0;
}
