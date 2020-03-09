#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

// Reads the total amount of memory in the system.
uint64_t getTotalSystemMemory() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

int main(int argc, char** argv) {
    char size;
    int time;

    if(argc > 1) size = atoi(argv[1]);
    else         size = 1;

    if(argc > 2) time = atoi(argv[2]);
    else          time = -1;
   
    // Total memory of the system.
    uint64_t realMemory = getTotalSystemMemory();

    // Allocate memory and fill it with ones
    uint64_t beta = (realMemory * size)/100;
    memset(malloc(beta), 1, beta);

    // Closes program after time 
    sleep (time);
}
