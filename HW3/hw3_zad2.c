#include <stdio.h>
#include <math.h>
// 2. test functions for double



int main(void){
    float a = 1000.0f * 0.1f;
    float b = 0.0f;
    for (int i = 0; i < 1000; i++, b += 0.1f);
    if (floatCompare1(a, b)){
        printf("== Equals\n");
    } else {
        printf("== Not equals\n");
    }
    if (floatCompare2(a, b)){
        printf("fixed E: Equals\n");
    } else {
        printf("fixed E: Not equals\n");
    }
    if (floatCompare3(a, b)){
        printf("Adaptive E: Equals\n");
    } else {
        printf("Adaptive E: Not equals\n");
    }
    return 0;
}
//ulp Units in the Last Place

// build-in compare operator
int floatCompare1(float a, float b){
    return a == b;
}
//relative epsilon
bool AlmostEqualRelative(float A, float B,
                         float maxRelDiff = FLT_EPSILON)
{
    // Calculate the difference.
    float diff = fabs(A - B);
    A = fabs(A);
    B = fabs(B);
    // Find the largest
    float largest = (B > A) ? B : A;

    if (diff <= largest * maxRelDiff)
        return true;
    return false;
}
// fixed epsilon
int floatCompare2(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int floatCompare3(float a, float b){
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}
