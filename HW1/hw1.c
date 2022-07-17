#include <stdio.h>
#include <math.h> 

int main() {
// 1. a) find BMI with the formula
double mass, height, BMI;
printf("Your mass in kg = ");
scanf ("%lf", &mass);
printf("Your height in meters = ");
scanf ("%lf", &height);

BMI = mass / pow(height, 2);

printf("Your BMI = %.1lf \n", BMI);

//  b) find BMI with the new formula by Nick Trefeten

BMI = 1.3 * mass / pow(height, 2.5);

printf("Your BMI by latest calculating method = %.1lf \n", BMI);

return 0; 
}
// include option -lm at the edn of compiling command in terminal because otherwise it doesn't link math.h