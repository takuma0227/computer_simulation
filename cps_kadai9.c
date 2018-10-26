#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define XINIT 0
#define YINIT 0
#define XMAX 2
#define H 0.01

// dy / dx �ŕ\���������������̉E�ӂ̊֐�
double f(double x, double y){
	return 5*pow(x,4);
}

//�^�̉��̒l
double true_y(double x){
	return pow(x, 5);
}

int main(void){

	double xi, xii, fyi, fyii, tyi, tyii, yi4, yii4;	//ex)xii = x_i  + 1
	double k4_1, k4_2, k4_3, k4_4;
	double ck = 1.80;

	//�����l���
	xi = XINIT;
	fyi = tyi = yi4 = YINIT;

	printf("%3s%7s%7s%7s%7s\n", "x", "�^�l", "�O�i", "��`", "RK4d");
	printf("%3.2f%7.3f%7.3f%7.3f%7.3f\n", xi, true_y(xi), fyi, tyi, yi4);

	while (xi <= XMAX){
		xii = xi + H;

		fyii = fyi + H*f(xi, fyi);	//�O�i�I�C���[�@
		tyii = tyi + H / 2 * (f(xi, tyi) + f(xii, tyi));	//��`�I�C���[�@

		//Runge-Kutta�@
		k4_1 = f(xi, yi4);
		k4_2 = f(xi + H/2, yi4 + H*k4_1 / 2);
		k4_3 = f(xi + H / 2, yi4 + H*k4_2 / 2);
		k4_4 = f(xi + H, yi4 + H*k4_3);
		yii4 = yi4 + H / 6 * (k4_1 + 2 * k4_2 + 2 * k4_3 + k4_4);	//4�����xrunge-kutta�@

		if (xii>1.78&&xii<1.79){
			printf("%3s%7s%7s%7s%7s\n", "x", "�^�l", "�O�i", "��`", "RK4d");
		}

		//�o��
		printf("%3.2f%7.3f%7.3f%7.3f%7.3f\n", xii, true_y(xii), fyii, tyii, yii4);

		//�l�̍X�V
		xi = xii;
		fyi = fyii;	tyi = tyii; yi4 = yii4;
	}

	return 0;
}