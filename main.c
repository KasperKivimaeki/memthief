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
		int limit;
		if (argc != 1) {
				limit = atoi(argv[1]);
		} else {
				limit = 75;
		}

		// Total memory of the system.
		uint64_t realMemory = getTotalSystemMemory();

		// Amount of percentage points to be allocated
		char size;

		// Ask user for print
		printf ("How much memory do you want to reserve?\n");
		for(;;) {
				// Read user input
				int scan = scanf ("%d", &size);
				// Prevent user from crashing the system
				if (size < limit)
						break;
		}

		printf ("Allocating memory\n");

		// Allocate memory and fill it with ones
		uint64_t beta = (realMemory * size) / 100;
		memset( malloc (beta), 1, beta);

		printf ("Memory allocated\n");

		// Leave the program running
		for(;;)
				// Prevent it from wasting system resources
				sleep (1000);
}
