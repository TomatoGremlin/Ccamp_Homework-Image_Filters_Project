#include <stdio.h>
#include <math.h>

double Sinus(double x, int n)
{
    double Sum = 0;
    double Obsht_chlen = x;
    double Znmn = 1;

    for (int i = 1; i <= n; i++)
    {
        Sum = Sum + Obsht_chlen;
        Znmn = Znmn + 2;
        Obsht_chlen = -Obsht_chlen * x * x / (Znmn * (Znmn - 1));
    }
    return Sum;
}

int main(){
    printf("Sin(rad) calculator\n");

    printf("sin(Pi/6 ) = %.6lf",  Sinus(M_PI/6, 6));
    putchar('\n');
    return 0;
}