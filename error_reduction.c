#include <stdio.h>
#include <math.h>

double cx1(double a, double b){
	double x;
	x = ((-a + sqrt(pow(a, 2) - 4 * b)) / 2);

	return x;
}

double cx2(double a, double b){
	double x;
	x = ((-a - sqrt(pow(a, 2) - 4 * b)) / 2);

	return x;
	
}

double cxa(double b, double x2){
	return b / x2;
}

int main(void){
	int i;
	long double a = 1.0, b = pow(10, -8);
	long double e1, e2,x1,xa,x2;



	for (i = 0; i < 10;i++){
		x1 = cx1(a, b);
		x2 = cx2(a, b);
		xa = cxa(b, x2);
		e1 = x1 * x2 - b;
		e2 = xa * x2 - b;

		printf("b: %.20f\n", b);
		printf("x1: %.20f\n xa: %.20f\n x2: %.20f\n",x1,xa,x2);
		printf("E1: %.20f	E2: %.20f\n", e1, e2);

		b /= 10;
		i++;
	}

	return 0;
}