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
	int n;	
	long double x, y, s;

	//乱数の初期化
	rand2 = B;

	printf("点数　    面積\n");

	for (i = 100; i <= 10000000; i *= 10){

		n = 0;

		for (j = 0; j < i; j++){
			x = Goudou();	y = Goudou();

			if (0<y&&y<pow(x,2))
				n++;
		}
		s = (double)n / i;
		printf("%8d　  %.6f\n", i, s);
	}
	return 0;
}