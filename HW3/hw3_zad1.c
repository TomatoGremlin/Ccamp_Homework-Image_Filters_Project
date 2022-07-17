#include <stdio.h>
#include <string.h>

void Dec_Bin (int decimal){
  int binary [14];
  int i = 0;
  printf ("%d in binary = ", decimal);
  
  while (decimal > 0)
    {
      binary[i] = decimal % 2;
      decimal = decimal / 2;
      i++;
    }
    for (int j = i - 1; j >= 0; j--)  printf ("%d", binary[j]);
}

void Hex_Bin(char*);
void Tri_Quad(char*);

int main()
{
 //1. base convertor
 // a) dec -> bin : 98, 56, 31, 32, 2, 1000, 111, 45, 14825
 printf("a) Base 10 to base 2:\n");
 int dec_bin[] = {98, 56, 31, 32, 2, 1000, 111, 45, 14825};
 int size = sizeof (dec_bin)/ sizeof(dec_bin[0]);
    for (int i = 0; i < size; i++)
    {
        Dec_Bin(dec_bin[i]);
        putchar('\n');
    }

 // b) bin -> dec: 10, 11101, 1111, 11110, 11011, 1001, 1110111, 11001100, 1010101010
  printf("\nb) Base 2 to base 10:\n");
  int bin_dec[] = {0b10, 0b11101, 0b1111, 0b11110, 0b11011, 0b1001, 0b1110111, 0b11001100, 0b1010101010};
  size = sizeof (bin_dec)/ sizeof(bin_dec[0]);
    for (int i = 0; i < size; i++)
    {
        printf("The binary number in oct = %d",  bin_dec[i]);
        putchar('\n');
    }  

 // c) dec -> hex 48, 156, 321, 255, 1024, 8, 100, 14567, 2020
    printf("\nc) Base 10 to base 16:\n");
    int dec_hex[] = {48,156, 321, 255, 1024, 8, 100, 14567,2020};
    size = sizeof (dec_hex)/ sizeof(dec_hex[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d in hex = %X", dec_hex[i], dec_hex[i]);
        putchar('\n');
    }

   // d) hex -> dec: A, 100, 3E, 1EA, ABC, EF, 5B3, 14C, 2A2B
    printf("\nd) Base 16 to base 10:\n");
    int hex_dec[] = {0xA, 0x100, 0x3E, 0x1EA, 0xABC, 0xEF, 0x5B3, 0x14C, 0x2A2B};
    size = sizeof (hex_dec)/ sizeof(hex_dec[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%X in dec = %d", hex_dec[i], hex_dec[i]);
        putchar('\n');
    }

 // e) hex-> bin : B, 200, 3E, 1EA, CAB, ED, 7B3, 24C, 3A2D
    printf("\ne) Base 16 to base 2:\n");
    char hex_bin[][4] = {{"B"}, {"200"}, {"3E"}, {"1EA"}, {"CAB"}, {"ED"}, {"7B3"}, {"24C"}, {"3A2D"}};
    size = sizeof(hex_bin)/4;
    for (int i = 0; i < size; i++)
    {
        printf("%s in bin = ", hex_bin[i]);
        Hex_Bin(hex_bin[i]);
        putchar('\n');
    }

 // f) bin -> hex: 110, 1100101, 110011, 101110110, 1011, 111101, 11001011, 101100, 1010110010
    printf("\nf) Base 2 to base 16:\n");
    int bin_hex[] = {0b110, 0b1100101, 0b110011, 0b101110110, 0b1011, 0b111101, 0b11001011, 0b101100, 0b1010110010};
    size = sizeof (bin_hex)/ sizeof(bin_hex[0]);
    for (int i = 0; i < size; i++)
    {
        printf("The binary number in hex = %X", bin_hex[i]);
        putchar('\n');
    }

 // g) dec -> oct: 8, 56, 31, 7, 2, 1000, 11, 45, 14825
    printf("\ng) Base 10 to base 8:\n");
    int dec_oct[] = {8, 56, 31, 7, 2, 1000, 11, 45, 14825};
    size = sizeof (dec_oct)/ sizeof(dec_oct[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d in oct = %o", dec_oct[i], dec_oct[i]);
        putchar('\n');
    }

  // h) oct -> dec: 25, 10, 24, 7, 2, 621, 45, 34, 5423
    printf("\nh) Base 8 to base 10:\n");
    int oct_dec[] = {025, 010, 024, 07, 02, 0621, 045, 034, 05423};
    size = sizeof (oct_dec)/ sizeof(oct_dec[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%o in dec = %d", oct_dec[i], oct_dec[i]);
        putchar('\n');
    }
 
   // h) (3) -> (4): 120, 10, 21, 2110, 112, 111221, 100, 110, 11001
    printf("\ng) Base 3 to base 4:\n");
    char tri_quad[][6]= {{"120"},{"10"},{"21"},{"2110"},{"112"},{"111221"},{"100"},{"110"},{"11001"} };
    size = sizeof(tri_quad)/6;
    for (int i = 0; i < size; i++)
    {
        printf("%s(3) in base 4 = ", tri_quad[i]);
        Tri_Quad(tri_quad[i]);
        putchar('\n');
    }

    return 0;
}
void Tri_Quad(char* ternary)
{
  //----------------- ternary to decimal-------
  int  b , i, n;
  int  len, decimal = 0; 
  len = strlen(ternary)-1;
 
  b = 1;
  for(i = len; i >=0; i--) 
  {   
      n = (ternary[i] - '0'); 
      decimal = decimal + n * b;
      b = b * 3;
  }
  
  //----------------- decimal to quaternary-------
  int quaternary [14];
  i = 0;
  
  while (decimal > 0)
    {
      quaternary[i] = decimal % 4;
      decimal = decimal / 4;
      i++;
    }
    for (int j = i - 1; j >= 0; j--)  printf ("%d", quaternary[j]);
}

void Hex_Bin(char* hex)
{
    long int i = 0;
    while (hex[i]) {
 
        switch (hex[i]) {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
            printf("1010");
            break;
        case 'B':
            printf("1011");
            break;
        case 'C':
            printf("1100");
            break;
        case 'D':
            printf("1101");
            break;
        case 'E':
            printf("1110");
            break;
        case 'F':
            printf("1111");
            break;
        }
        i++;
    }
}