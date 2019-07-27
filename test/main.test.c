#include "malloc.h"
#include <stdio.h>

/*
void test4() {
	void *a = ft_malloc(10);
	void *b = ft_malloc(1024 * 32);
	void *c = ft_malloc(1024 * 1024);
	void *d = ft_malloc(1024 * 1024 * 16);
	void *e = ft_malloc(1024 * 1024 * 128);

	show_alloc_mem();

	void *f = ft_realloc(e, 10);

	show_alloc_mem();

	ft_free(a);
	ft_free(b);
	ft_free(c);
	ft_free(d);
	ft_free(e);
	ft_free(f);

}

void test3() {
	void *a = ft_malloc(10);
	void *b = ft_malloc(1024 * 32);
	void *c = ft_malloc(1024 * 1024);
	void *d = ft_malloc(1024 * 1024 * 16);
	void *e = ft_malloc(1024 * 1024 * 128);

	void *f = ft_realloc(e, 10);

	ft_free(a);
	ft_free(b);
	ft_free(c);
	ft_free(d);
	ft_free(e);
	ft_free(f);
}
*/

void test2() {
	int i = 0;
	int x = 0;
	char *addr = NULL;

	while(i < 1000) {
		addr = (char*)ft_malloc(30);
		++i;
		x = 0;
		while (x < 10) {
			addr[x] = 42;
			++x;
		}
		ft_free(addr);
	}
}

/*
void test1() {
	int i = 0;
	char x = 0;
	char *addr = NULL;
	char *print = NULL;

	// for (size_t c = 0; c < 100; c++) {
	//	printf("size %lu\n", c);
		i = 0;
		while(i < 20) {
			addr = (char*)ft_malloc(10);
			if (!print) {
				print = addr;
			}
			++i;
			x = 16;
			while (x < 32) {
				addr[x - 16] = x;
				++x;
			}
		}
		ft_putendl("");
		ft_print_memory(print, 100);
	// }
}
*/

/*
void test0() {
	void *a = ft_malloc(10);
	ft_free(a);
}
*/

int main(void) {

	printf("getPageSize %d\n", getpagesize());
	test2();
	show_alloc_mem();
	return 0;
}
   
