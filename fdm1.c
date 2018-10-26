//平版の温度分布

#include <math.h>
#include <stdio.h>

#define DXNUM 21	//格子点数（= 分割数 + 1）
#define DT 0.001	//無次元時間間隔
#define BC 0.0		//境界条件値
#define IC 1.0		//初期条件値

int main(void){
	int i, ii;
	double u[DXNUM], uu[DXNUM];		//u:時間 n の温度　uu:時間(n + 1)の温度
	double dx, now;					//dx:格子幅⊿x　now:現在時刻

	//計算用データ値設定
	ii = DXNUM - 1;			//ii は添字 i の最大数 I
	dx = 1.0 / (double)ii;	//格子間隔を設定
	now = 0.0;				//初期時刻設定

	//境界値設定
	u[0] = BC;
	u[ii] = BC;

	//初期条件設定
	for (i = 1; i < ii; i++)
		u[i] = IC;

	do{
		now += DT;	//現在時刻更新

		//差分式から(n + 1)での u[i] の値を計算
		for (i = 1; i < ii; i++)
			uu[i] = u[i] + DT / pow(dx, 2.0)*(u[i + 1] - 2.0*u[i] + u[i - 1]);

		//次の計算のために温度を更新
		for (i = 1; i < ii; i++)
			u[i] = uu[i];

	} while (now < IC);

	for (i = 1; i < ii; i++)
		printf("%f\n", u[i]);

	return 0;
}