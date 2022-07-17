#include <stdio.h>

int main(void){
 // 1. P = ? , S = ?
   double w, h, P, S;
   printf("Enter values for height and width of a rectangle:\n");
   while (scanf("%lf %lf", &w, &h) != EOF )
    {
        if ((w <0 || h < 0 ))
        {
            printf("Invalid rectangle sizes!\n");
        }
        else{
            P = 2*(w+h);
            S = w * h;
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }
      
    }
   
    return 0;
}
