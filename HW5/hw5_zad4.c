#include <stdio.h>
#include <math.h>
int quadEq(double a, double b, double c, double *D, double *x1, double *x2){
        *D = pow(b,2) - 4*a*c;
        if (*D < 0)
        {
            return -1;
        }
        *x1 = ((b - 2*b) + sqrt(*D))/(2*a);
        *x2 = ((b - 2*b) - sqrt(*D))/(2*a);
    
        return 0;
}

int main(void){
    double a,  b,  c , D, x1,  x2;
    printf("Enter values for a, b and c for the equation:\n");
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF )
    {
        D = pow(b,2) - 4*a*c;
        if ( quadEq( a,  b,  c,  &D, &x1, &x2) == -1)
        {
            printf("No real roots\n");
        }
        else{
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf\n", x2);
        }
    }
    return 0;
}
