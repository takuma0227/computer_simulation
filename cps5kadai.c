#include <stdio.h>
#include <limits.h>

#include <stdio.h>
#include <limits.h>

//�����@�̏����l
#define A 2045ULL
#define B 257ULL
#define C 9379ULL
#define M ULONG_MAX

#define N ULONG_MAX	//���������闐���̌�

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
	unsigned long long i;
	long double r;
	unsigned long long li[11] = { 0 };

	//�����̏�����xi
	rand2 = B;

	for (i = 0; i < N; i++){

		//�����@�Ăяo��
		r = Goudou();

		li[(int)(r * 100) / 10]++;
	}

	//�x�����z�\
	for (i = 0; i < 9; i++)
		printf("%2f<=x<%2f	%llu\n", i / 10.0, i / 10.0 + 0.1, li[i]);
	printf("%2f<=x<=%2f	%llu\n", i / 10.0, i / 10.0 + 0.1, li[i] + li[i + 1]);

	return 0;
}