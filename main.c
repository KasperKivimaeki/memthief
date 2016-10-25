#include <unistd.h>
#include <stdio.h>
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
		if (argc > 1) {
				size = atoi(argv[1]);
		} else {
				printf("No size given, default = 1\n"); 
				size = 1;
		}
		
		int time;
		if (argc == 3) {
				time = atoi(argv[2]);
		} else {
				printf("No time given, will never stop\n"); 
				time = -1;
		}

		// Total memory of the system.
		uint64_t realMemory = getTotalSystemMemory();

		// Allocate memory and fill it with ones
		uint64_t beta = (realMemory * size) / 100;
		memset( malloc (beta), 1, beta);

		// Closes program after time 
		sleep (time);
}
