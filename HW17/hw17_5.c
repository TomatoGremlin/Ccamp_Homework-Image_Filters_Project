#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void sleep_ms(unsigned ms){
    usleep(ms * 1000);
}
void print(){
    while (1)
    {
        printf("MMS C Camp\n");
        sleep_ms(500);
    }
}

int main() {
    signal(SIGINT, SIG_IGN); //ctrl C = signal interupt
    signal(SIGSTOP, SIG_IGN); // Ctrl Z = signal stop
    
    print();

    //KILL and STOP signal can't be ignored because they are sent to the kernel of the OS and not to a process
    return 0;
}