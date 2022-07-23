#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask){
    unsigned ones = 0;
    for (int j = 0; j < sizeof(mask)*8; j++){ // bitovete
      ones += !!(mask & (1ULL << j));
    }
    printf ("Number of ones in the mask = %u\n", ones);
    return ones;
}

int main() {

   onesCount(0x0a); // 2 ones
   onesCount(0xaaaa); // 8 ones
   onesCount(0b1010111110111); // 10 ones
   return 0;
}
