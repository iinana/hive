#include <stdio.h>

void test(int *******n) {
	*******n = 42;
	printf("%d", *******n);
}

int main() {
	int a = 1;
	int *pa = &a;
	int **ppa = &pa;
	int ***pppa = &ppa;
	int ****ppppa = &pppa;
	int *****pppppa = &ppppa;
	int ******ppppppa = &pppppa;
	test(&ppppppa);
}

