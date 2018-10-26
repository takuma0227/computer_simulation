#include <stdio.h>
#include <limits.h>
#include <math.h>

//合同法の初期値
#define A 2045ULL
#define B 257ULL
#define C 9379ULL
#define M ULONG_MAX
#define Pi 3.14159265359

unsigned long long rand2;

double Goudou(void){
	unsigned long long rand1;
	double r;

	//混合型合同法
	rand1 = (A*rand2 + C) % M;
	r = (double)rand1 / (M - 1ULL);	//正規化
	rand2 = rand1;	//値の更新

	return r;
}

int main(void){
	int i, j;
	int n;	//円
	long double x, y,z, s, ans, gs, ri;

	//乱数の初期化
	rand2 = B;

	ans = (4 * Pi*pow(0.5, 3)) / 3;

	printf("点数　　    体積　　   円周率　　    面積誤差\n");

	for (i = 100; i <= 10000000; i *=10){

		n = 0;

		for (j = 0; j < i; j++){
			x = Goudou();	y = Goudou();	z = Goudou();
				ri = sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2) + pow(z - 0.5, 2));
			if (ri <= 0.5)
				n++;
		}
		s = (double)n / i;
		gs = (s < ans) ? (ans - s) / ans : (s - ans) / ans;
		printf("%8d　  %.3f     %.8f　    %.2f%%\n", i, s,s*(3/(4*pow(0.5,3))), gs * 100);
	}
	return 0;
}