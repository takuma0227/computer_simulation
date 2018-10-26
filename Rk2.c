//2回微分方程式をRK法で解く

#include <stdio.h>
#include <math.h>

#define XINIT 0
#define YINIT 1.0
#define ZINIT 1.0
#define XMAX 1.5
#define H 0.001

// dy / dx = z = f(x,y,z)
double f(double x, double y,double z){
	return z;
}


double g(double x, double y, double z){
	return 3 * z - 2 * y;
}

double true_y(double x){
	return 2 * exp(x) + exp(2*x);
}

int main(void){

	double xi, xii, yi,yii,zi,zii;	//ex)xii = x_i  + 1
	double b1, b2, b3, b4;
	double c1, c2, c3, c4;
	double rb, rc;

	//初期値代入
	xi = XINIT;
	yi = YINIT;
	zi = ZINIT;

	printf("%3s%9s%9s\n", "x", "真値", "RK4d");

	do{
		xii = xi + H;


		//4次精度Runge-Kutta法
		b1 = f(xi, yi,zi);
		c1 = g(xi, yi, zi);
		b2 = f(xi + H / 2, yi + H*b1 / 2, zi + c1*H / 2);
		c2 = g(xi + H / 2, yi + H*b1 / 2, zi + c1*H / 2);
		b3 = f(xi + H / 2, yi + H*b2 / 2, zi + c2*H / 2);
		c3 = g(xi + H / 2, yi + H*b2 / 2, zi + c2*H / 2);
		b4 = f(xi + H, yi + H*b3, zi + c3*H);
		c4 = g(xi + H, yi + H*b3, zi + c3*H);

		yii = yi + H / 6 * (b1 + 2 * b2 + 2 * b3 + b4);
		zii = zi + H / 6 * (c1 + 2 * c2 + 2 * c3 + c4);
		

		//出力
		printf("%3.2f%9.5f%9.5f\n", xii, true_y(xii), yii);

		//値の更新
		xi = xii;
		yi = yii;
		zi = zii;
	} while (xii < XMAX);

	return 0;
}