#include <stdio.h>
#include <stdarg.h> 
#include <float.h>
#include <stdint.h>

int checkBit(uint64_t *mask, size_t n, size_t bit){
    if (n * sizeof(*mask)*__CHAR_BIT__ <= bit){
        return -1;
    }
    int index = bit / (sizeof(*mask) * __CHAR_BIT__);;
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    return !!(mask[index] & (1ull << b)); 
}

size_t bitsNCount (size_t maskcount, size_t bitcount, ...){
    size_t masks = 0;
    va_list args;
    va_start(args,maskcount);

    for (int i = 0; i < maskcount; i++){
        int mask = va_arg(args, int);
        int maskBists = 0;
        for (size_t i = 0; i < sizeof(mask)*8; i++){
            maskBists += checkBit(mask, i);
        }
        masks += (maskBists == bitcount);
  
    }
    va_end(args);
    
    return masks;
}

int main() {
    

    return 0;
}



