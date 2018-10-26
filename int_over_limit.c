#include <stdio.h>
#include <limits.h>

int main(void){
	int a, b;

	a = INT_MAX;
	b = a + 1;

	printf("%d + 1 = %d\n", a, b);

	return 0;
}