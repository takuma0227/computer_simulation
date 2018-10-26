#include <stdio.h>
#include <math.h>

#define XINIT 0
#define YINIT 0
#define XMAX 2
#define H 0.1

// dy / dx で表される微分方程式の右辺の関数
double f(double x, double y){
	return 2 * x;
}

//真の解の値
double true_y(double x){
	return pow(x, 2);
}

int main(void){

	double xi, fyi, xii, fyii,byi,byii,tyi,tyii,yi2,yii2,yi4,yii4,yi;	//ex)xii = x_i  + 1
	double k1, k2, k4_1, k4_2, k4_3, k4_4;

	//初期値代入
	xi = XINIT;
	fyi = byi = tyi = yi2 = yi4 = yi = YINIT;
	
	printf("%2s%7s%7s%7s%7s%7s%7s\n", "x", "真値","前進","後方","台形","RK2d","RK4d");
	printf("%2.1f%7.3f%7.3f%7.3f%7.3f%7.3f%7.3f\n", xi,true_y(xi),fyi,byi,tyi,yi2,yi4);

	while (xi <= XMAX){
		xii = xi + H;

		fyii = fyi + H*f(xi,yi);	//前進オイラー法
		byii = byi + H*f(xi,yi);	//後退オイラー法
		tyii = tyi + H / 2 * (f(xi,yi) + f(xii,yi));	//台形オイラー法

		//Runge-Kutta法
		k1 = f(xi, yi2);
		k2 = f(xi + H/2, yi2 + H/2*k1);
		yii2 = yi2 + (k1 + k2)*H / 2;	//2次精度Runge-Kutta法

		k4_1 = f(xi, yi4);
		k4_2 = f(xi + H, yi4 + H*k4_1/2);
		k4_3 = f(xi + H / 2, yi4 + H*k4_2 / 2);
		k4_4 = f(xi + H, yi + H*k4_3);
		yii4 = yi4 + H / 6 * (k4_1 + 2 * k4_2 + 2 * k4_3 + k4_4);	//4次精度runge-kutta法

		//出力
		printf("%2.1f%7.3f%7.3f%7.3f%7.3f%7.3f%7.3f\n", xii, true_y(xii), fyii, byii, tyii,yii2,yii4);

		//値の更新
		xi = xii;
		fyi = fyii;	byi = byii;	tyi = tyii; yi2 = yii2; yi4 = yii4;

	}

	return 0;
}