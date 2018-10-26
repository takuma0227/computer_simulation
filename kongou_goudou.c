#include <stdio.h>

//合同法の初期値
#define A 3
#define B 76
#define M 100

#define N 30	//生成させる乱数の個数

int rand2;

double Goudou(void){
	int rand1;
	double r;

	//混合型合同法
	//		rand1 = (A*rand2 + C) % M;
	rand1 = (A*rand2) % M;
	r = (double)rand1 / (M - 1);	//正規化
	rand2 = rand1;	//値の更新

	return r;
}

int main(void){
	int rand1;
	int i;
	int pc = 0, cnt = 1;
	double r;

	//乱数の初期化xi
	rand2 = B;

	for (i = 0; i < N; i++){

		//合同法呼び出し
		r = Goudou();

		//表示
		printf("%f", r);
		if (i != N - 1)	printf(" ");
		else printf("\n");
	}
	return 0;
}