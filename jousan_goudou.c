#include <stdio.h>

//�����@�̏����l
#define A 3
#define B 77
#define M 100

#define N 30	//���������闐���̌�

int main(void){
	int rand1,rand2;
	int i;
	//�����̏�����xi
	rand2 = B;
	//�\��
	printf("%d ", rand2);


	for (i = 0; i < N; i++){
		//��Z�^�����@
		rand1 = (A*rand2) % M;
		printf("%d", rand1);
		if (i != N - 1)	printf(" ");
		else printf("\n");
		//�l�̍X�V
		rand2 = rand1;
	}
	return 0;
}