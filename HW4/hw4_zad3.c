#include <stdio.h>
#include <string.h>


// From the character to value
int ChartoValue(char letter)
{
  if (letter >= '0' && letter <= '9')
        return (int)letter - '0';
    else
        return (int)letter - 'A' + 10;
}


// Given base to decimal:
int To_Decimal(char* str, int base){
    int len = strlen(str);
    int power = 1;
    int num = 0;
 
    for (int i = len - 1; i >= 0; i--) {

        if (ChartoValue(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }
        
        num += ChartoValue(str[i]) * power;
        power = power * base;
    }
    return num;
}

void Reverse_string(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0 ; i < len/2 ; i++)
    {
        char temp = str [i];
        str [i] = str [len - i - 1];
        str [len - i - 1] = temp;
    }
}

// From given value to the character
char ValuetoChar(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Decimal to given base:
char* From_Decimal( char* result, int base, int inputNum)
{
    int i = 0;
    
    while (inputNum > 0) {
 
        result[i] = ValuetoChar( inputNum % base );
        inputNum /= base;
        i++;
    }
    result[i] = '\0';
    // Reverse the result
    Reverse_string(result);
    
    return result;
}


// Final number convertion:
void Convert_to (char* n, int base_from, int base_to)
{
    // base A to decimal
    int number = To_Decimal(n, base_from);
    
    // decimal to base B
    char result [20];
    From_Decimal(result , base_to, number);

    printf("%s", result);
} 

// 3. base convertor
int main(){
    
    char number[50];
    int base_from;
    int base_to;
   
    
    //input check
    
    scanf("%s", number);
    
    scanf("%d", &base_from);
    while (base_from < 2 || base_from > 36)
    {
       fprintf( stderr, "Error. %d is not a viable input for base, try again:\n", base_from);
       scanf("%d", &base_from);
    }
    
    scanf("%d", &base_to);
    while (base_to < 2 || base_to > 36)
    {
       fprintf( stderr, "Error. %d is not a viable input for base, try again:\n", base_to);
       scanf("%d", &base_to);
    }
 
   
    printf("%s(%d) in (%d) = ", number, base_from, base_to);
    Convert_to(number, base_from, base_to);

    return 0;
}
