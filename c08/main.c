#include <stdio.h>
#include <string.h>
#include "ex04/ft_strs_to_tab.c"

int main()
{
	char **a = (char**)malloc(sizeof(char*) * 3);
	a[0] = (char*)malloc(sizeof(char) * 1024);
	a[1] = (char*)malloc(sizeof(char) * 1024);
	a[2] = (char*)malloc(sizeof(char) * 1024);
	strcpy(a[0], "ieSrBXBI5d4rW9O2");
	strcpy(a[1], "eadLhPjehRMwjqv9JJ7Q0WiLTBoVxsLx");
	strcpy(a[2], "MKynFC5rJwCJ0jdD");
	t_stock_str *b = ft_strs_to_tab(3, a);
	for (int i = 0; b[i].str != 0; i++)
		printf("%s \n%s | %d\n", b[i].str, b[i].copy, b[i].size);

	/*for (int i = 0; b[i].str != 0; i++)*/
		/*free(b[i].copy);*/
	/*free(b);*/
	/*free(a[0]);*/
	/*free(a[1]);*/
	/*free(a[2]);*/
	/*free(a);*/

	return 0;
}
