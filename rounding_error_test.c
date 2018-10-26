#include <stdio.h>

int main(void){
	double a = 0.1, b = 0.0;
	int i;

	for (i = 1; i <= 100000; i++)
		b += a;

	printf("%.16f\n", b);

	return 0;
}