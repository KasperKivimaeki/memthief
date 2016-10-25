#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

unsigned long long getTotalSystemMemory()
{
		long pages = sysconf(_SC_PHYS_PAGES);
		long page_size = sysconf(_SC_PAGE_SIZE);
		return pages * page_size;
}

int main(int argc, char** argv)
{
		uint64_t realMem = getTotalSystemMemory();
		int thief;
		for(;;){
				printf("How much memory do you want to reserve?\n");
				printf("Example: 50\n\nReserve: ");
				int scan = scanf("%d", &thief);
				printf("%");
				if(!scan){return -1;}
				if(thief > 75){
						printf("Don't steal it all!\n");
				} else {
						break;
				}
		}
		char *alpha = malloc(thief*((realMem)/100));
		memset(alpha, 1, (thief/100.0)*realMem);
		for(;;){sleep(1000);}
		return 1;
}
