#include <stdio.h>

#define TRUE_E 2.71828182845904524

int fractorial(int n){
	if (n > 0)
		return n*fractorial(n - 1);
	else
		return 1;
}

int main(void){
	int i=0;
	double e=0;
	while (e < TRUE_E){
		e += (double)1 /fractorial(i);
		printf("%d€‚Ü‚Å%.16f Œë·F%.16f\n", i + 1, e,TRUE_E-e);
		i++;
	}

	return 0;

}