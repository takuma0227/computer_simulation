#include <stdio.h>

//�����@�̏����l
#define A 3
#define B 76
#define M 100

#define N 30	//���������闐���̌�

int rand2;

double Goudou(void){
	int rand1;
	double r;

	//�����^�����@
	//		rand1 = (A*rand2 + C) % M;
	rand1 = (A*rand2) % M;
	r = (double)rand1 / (M - 1);	//���K��
	rand2 = rand1;	//�l�̍X�V

	return r;
}

int main(void){
	int rand1;
	int i;
	int pc = 0, cnt = 1;
	double r;

	//�����̏�����xi
	rand2 = B;

	for (i = 0; i < N; i++){

		//�����@�Ăяo��
		r = Goudou();

		//�\��
		printf("%f", r);
		if (i != N - 1)	printf(" ");
		else printf("\n");
	}
	return 0;
}