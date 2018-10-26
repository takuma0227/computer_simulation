#include <stdio.h>
#include <limits.h>
#include <math.h>

//�����@�̏����l
#define A 2045ULL
#define B 257ULL
#define C 9379ULL
#define M ULONG_MAX
#define Pi 3.14159265359

unsigned long long rand2;

double Goudou(void){
	unsigned long long rand1;
	double r;

	//�����^�����@
	rand1 = (A*rand2 + C) % M;
	r = (double)rand1 / (M - 1ULL);	//���K��
	rand2 = rand1;	//�l�̍X�V

	return r;
}

int main(void){
	int i, j;
	int n;	
	long double x, y, s;

	//�����̏�����
	rand2 = B;

	printf("�_���@    �ʐ�\n");

	for (i = 100; i <= 10000000; i *= 10){

		n = 0;

		for (j = 0; j < i; j++){
			x = Goudou();	y = Goudou();

			if (0<y&&y<pow(x,2))
				n++;
		}
		s = (double)n / i;
		printf("%8d�@  %.6f\n", i, s);
	}
	return 0;
}