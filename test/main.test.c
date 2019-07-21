#include "malloc.h"
#include <stdio.h>

int main(void) {

	int i = 0;
	int x = 0;
	char *addr = NULL;

	while(i < 1024) {
		addr = (char*)ft_malloc(1024);
		++i;
		x = 0;
		while (x < 1024) {
			addr[x] = 42;
			++x;
		}
		ft_free(addr);
	}
	return 0;
}

