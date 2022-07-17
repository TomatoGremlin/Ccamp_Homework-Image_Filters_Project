#include <stdio.h>
void Calculator()
{ // 1.
  char action;
  double num1, num2;
  printf("Enter an operation (+, -, *, /): ");
    while (scanf("%lf %c %lf", &num1, &action, &num2) != EOF)
    {
        switch (action) {
            case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
            case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
            case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
            case '/':
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            break;
            default:
            fprintf(stderr,"Error! Input is not correct.\n");
        }
    }
}
int main(){
   Calculator();
   return 0;
}