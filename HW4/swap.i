# 0 "swap.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "swap.c"
void swap(int* num1, int* num2)
{
*num1 ^= *num2;
*num2 ^= *num1;
*num1 ^= *num2;
}
