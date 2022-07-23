#include <stdio.h>
#include <stdarg.h> 

unsigned bitsNCount ( unsigned bitscnt, unsigned maskcount, ...){ // broi maski i broi edinici koito trqbva da ima maskata
   
    unsigned masks = 0;
    
    va_list args;
    va_start(args, maskcount);

    for (int i = 0; i < maskcount; i++){ // smenqme maskite
        
        int mask = va_arg(args, int);
        int maskBists = 0;
        
        for (int j = 0; j < sizeof(mask)*8; j++){ // proverqvane na bit po bit na tekushtata maska
            
            maskBists += !!(mask & (1ULL << j));
        }
        
        if(maskBists == bitscnt){  // ako v maskata namerenite edinici sa tolkova kolkoto jelanite
            masks++;  // uvelichavame broq na maskite
        }
    }
    va_end(args);
    
    printf ("Masks that have %u ones = %u\n", bitscnt,masks);
    return masks;
}


int main() {

   bitsNCount(2, 4, 0x0a, 0xff, 0, 1); //1 mask has 2 ones
   bitsNCount(8, 3, 0xff, 0x13f1, 0xaaaa); //3 masks have 8 ones
   bitsNCount(10, 5, 0x0a, 0xa0ff, 0, 10, 0b1010111110111); //2 masks have 10 ones
    return 0;
}


