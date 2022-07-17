#include <stdio.h>
#include <math.h> 

int main() {
//  2.  V of water in a cylinder =?
//a)vertical
double R, L, H, V, area;
printf("b)Water volume of a vertically laid down cylinder:\n");
printf("Cylinder base radius in meters = ");
scanf ("%lf", &R);
printf("Cylinder water height in meters = ");
scanf ("%lf", &H);

V = M_PI * pow(R, 2)* H;

printf("Cylinder water volume  = %lf m^3 \n", V);

//  b) horizontal
printf("\nb)Water volume of a horizontally laid down cylinder:\n");
printf("Cylinder base radius in meters = ");
scanf ("%lf", &R);
printf("Cylinder water height in meters = ");
scanf ("%lf", &H);
printf("Height the cylinder in meters = ");
scanf ("%lf", &L);

area = acos((R-H)/R) * pow(R, 2) - (R - H) * sqrt(2*R*H - pow(H,2));
V = area * L;
printf("Cylinder water volume = %lf m^3 \n", V);

return 0; 
}