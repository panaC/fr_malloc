#include "malloc.h"
#include <stdio.h>

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

void test2() {
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
}

void test1() {
	int i = 0;
	int x = 0;
	char *addr = NULL;

	while(i < 1024) {
		addr = (char*)ft_malloc(100);
		++i;
		x = 0;
		while (x < 100) {
			addr[x] = x;
			++x;
		}
	}
}

void test0() {
	void *a = ft_malloc(10);
	ft_free(a);
}

int main(void) {

	test1();
	return 0;
}

