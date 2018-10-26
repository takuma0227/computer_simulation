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
	int i,j;
	int n;	//円
	long double x, y,s,ans,gs,ri;

	//乱数の初期化
	rand2 = B;

	ans = Pi*pow(0.5, 2);

	printf("点数　　面積　　円周率　　面積誤差\n");

	for (i = 30000000; i <= 30000000; i += 1000){

		n = 0;

		for (j = 0; j < i; j++){
			x = Goudou();	y = Goudou();
			ri = sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2));
			if (ri <= 0.5)
				n++;
		}
		s = (double)n/i;
		gs = (s < ans) ? (ans - s) / ans : (s - ans) / ans;
		printf("%6d　%.3f　 %.3f　    %.2f%%\n", i, s, s / pow(0.5, 2),gs*100);
	}
	return 0;
}