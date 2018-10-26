//�����@�ŉ����M�`��������

#include <stdio.h>
#include <math.h>

#define IMAX 10
#define JMAX 10

int main(void){
	int i, j;
	double u[IMAX][JMAX], uu[IMAX][JMAX];
	double sum;
	int n;	//�����i�q�_��
	double e = pow(10, -4);	//��������


	n = IMAX*JMAX;

	//���������ݒ�
	for (i = 0; i < IMAX; i++)
		for (j = 0; j < JMAX; j++)
			u[i][j] = 0.0;
	for (i = 1; i < IMAX - 1; i++)
		u[i][0] = 1.0;

	do{
		for (i = 1; i < IMAX - 1; i++)
			for (j = 1; j < JMAX - 1; j++)
				uu[i][j] = (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1])/4;

		//�l�̍X�V
		for (i = 1; i < IMAX; i++)
			for (j = 1; j < JMAX; j++)
				u[i][j] = uu[i][j];

		//�c��
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