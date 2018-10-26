#include <stdio.h>

//合同法の初期値
#define A 3
#define B 77
#define M 100

#define N 30	//生成させる乱数の個数

int main(void){
	int rand1,rand2;
	int i;
	//乱数の初期化xi
	rand2 = B;
	//表示
	printf("%d ", rand2);


	for (i = 0; i < N; i++){
		//乗算型合同法
		rand1 = (A*rand2) % M;
		printf("%d", rand1);
		if (i != N - 1)	printf(" ");
		else printf("\n");
		//値の更新
		rand2 = rand1;
	}
	return 0;
}