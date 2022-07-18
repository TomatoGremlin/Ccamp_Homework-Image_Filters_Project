#include <stdio.h>

int rectangle(double w, double h, double* S, double *P){
    if (w <= 0 || h <= 0){
     return -1;
    }
    *P = 2*(w+h);
    *S = w * h;
    return 0;
}
int main() {
  double w, h, P, S;
  
  printf("Enter values for height and width of a rectangle:\n");
   while (scanf("%lf %lf", &w, &h) != EOF )
    {
        if ( rectangle(w, h, &S, &P) == -1 )
        {
            printf("Invalid rectangle sizes!\n");
        }
        else{
            rectangle(w, h, &S, &P);
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }
    }
    return 0;
}
