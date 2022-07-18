#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double *S, double *P)
{
    if (a <=0 || b <= 0 || c <=0){
     return -1;
    }
    *P = a + b + c;
    *S = sqrt(*P*(*P-a)*(*P-a)*(*P-c));
    return 0;
}
int main() {
  
   double a, b, c, P, S;
  
   printf("Enter values for the 3 sides of a triagle:\n");
   while (scanf("%lf %lf %lf", &a, &b, &c) != EOF )
    {
        if (triangle(a, b, c, &S, &P) == -1 )
        {
             printf("Invalid triangle sides!\n");
        }
        else{
            triangle(a, b, c, &S, &P);
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }
    }
    return 0;
}
