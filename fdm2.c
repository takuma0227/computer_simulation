//差分法で解く熱伝導方程式

#include <stdio.h>
#include <math.h>

#define IMAX 10
#define JMAX 10

int main(void){
	int i, j;
	double u[IMAX][JMAX], uu[IMAX][JMAX];
	double sum;
	int n;	//内部格子点数
	double e = pow(10, -4);	//収束条件


	n = IMAX*JMAX;

	//初期条件設定
	for (i = 0; i < IMAX; i++)
		for (j = 0; j < JMAX; j++)
			u[i][j] = 0.0;
	for (i = 1; i < IMAX - 1; i++)
		u[i][0] = 1.0;

	do{
		for (i = 1; i < IMAX - 1; i++)
			for (j = 1; j < JMAX - 1; j++)
				uu[i][j] = (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1])/4;

		//値の更新
		for (i = 1; i < IMAX; i++)
			for (j = 1; j < JMAX; j++)
				u[i][j] = uu[i][j];

		//残差
		sum = 0;
		for (i = 1; i < IMAX - 1; i++)
			for (j = 1; j < JMAX - 1; j++)
				sum += ((uu[i][j] - u[i][j])>0) ? (uu[i][j] - u[i][j]) : (u[i][j] - uu[i][j]) ;
		sum /= 4;

	} while (sum > e);


for (i = 0; i < IMAX; i++)
		for (j = 0; j < JMAX; j++)
			printf("%f\n", u[i][j]);


	return 0;
}