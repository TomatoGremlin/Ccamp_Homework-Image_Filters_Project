#include <stdio.h>
#include <math.h>
/*int triangle(double a, double b, double c, double*S, double *P)
{ 
   
    if ()
    {
        return -1;
    }
    
    return 0;
}
*/
int main(){
   // 1. P = ? , S = ?
   double a, b, c, P, S;
   printf("Enter values for the 3 sides of a triagle:\n");
   while (scanf("%lf %lf %lf", &a, &b, &c) != EOF )
    {
        if ((a <0 || b < 0 || c < 0))
        {
            printf("Invalid triangle sides!\n");
        }
        else{
            P = a + b +c;
            S = sqrt(P*(P-a)*(P-a)*(P-c));
    
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }
      // triangle(a, b, c);
    }
   return 0;
}