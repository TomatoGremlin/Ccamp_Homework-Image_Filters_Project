#include <stdio.h>
#include <math.h>
// 2. test functions for double

//ulp Units in the Last Place
bool AlmostEqualUlpsAndAbs(float , float ,float , int);
//relative epsilon
bool AlmostEqualRelative(float , float , float);
// fixed epsilon
int FixedEps_compare(float , float );
// adaptive epsilon
int AdaptEps_compare(float , float );
//basic
int Basic_compare(float , float );
int main(void){
    float a = 2010.0f * 0.2f;
    float b = 0.0f;
    for (int i = 0; i < 1000; i++, b += 0.2f);
    if (FixedEps_compare(a, b)){
        printf("With fixed epsilon: Equals\n");
    } else {
        printf("With fixed epsilon: Not equals\n");
    }
    if (AdaptEps_compare(a, b)){
        printf("With adaptive epsilon: Equals\n");
    } else {
        printf("With adaptive epsilon: Not equals\n");
    }
    if (AlmostEqualUlpsAndAbs(a, b)){
        printf("With ulp: Equals\n");
    } else {
        printf("With ulp: Not equals\n");
    }
    if (AlmostEqualRelative(a, b)){
        printf("With relative epsilon: Equals\n");
    } else {
        printf("With relative epsilon: Not equals\n");
    }
    if (Basic_compare(a, b)){
        printf("With basic ==: Equals\n");
    } else {
        printf("With basic == : Not equals\n");
    }
    return 0;
}
//ulp Units in the Last Place
bool AlmostEqualUlpsAndAbs(float A, float B,float maxDiff, int maxUlpsDiff)
{
    
    float absDiff = fabs(A - B);
    if (absDiff <= maxDiff)
        return true;

    Float_t uA(A);
    Float_t uB(B);

    // Different signs means they do not match.
    if (uA.Negative() != uB.Negative())
        return false;

    // Find the difference in ULPs.
    int ulpsDiff = abs(uA.i - uB.i);
    if (ulpsDiff <= maxUlpsDiff)
        return true;
    return false;
}
//relative epsilon
bool AlmostEqualRelative(float A, float B, float maxRelDiff = FLT_EPSILON)
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
int FixedEps_compare(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int AdaptEps_compare(float a, float b){
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}

//basic
int Basic_compare(float a, float b){
    return a == b;
}
