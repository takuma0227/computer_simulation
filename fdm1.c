//���ł̉��x���z

#include <math.h>
#include <stdio.h>

#define DXNUM 21	//�i�q�_���i= ������ + 1�j
#define DT 0.001	//���������ԊԊu
#define BC 0.0		//���E�����l
#define IC 1.0		//���������l

int main(void){
	int i, ii;
	double u[DXNUM], uu[DXNUM];		//u:���� n �̉��x�@uu:����(n + 1)�̉��x
	double dx, now;					//dx:�i�q����x�@now:���ݎ���

	//�v�Z�p�f�[�^�l�ݒ�
	ii = DXNUM - 1;			//ii �͓Y�� i �̍ő吔 I
	dx = 1.0 / (double)ii;	//�i�q�Ԋu��ݒ�
	now = 0.0;				//���������ݒ�

	//���E�l�ݒ�
	u[0] = BC;
	u[ii] = BC;

	//���������ݒ�
	for (i = 1; i < ii; i++)
		u[i] = IC;

	do{
		now += DT;	//���ݎ����X�V

		//����������(n + 1)�ł� u[i] �̒l���v�Z
		for (i = 1; i < ii; i++)
			uu[i] = u[i] + DT / pow(dx, 2.0)*(u[i + 1] - 2.0*u[i] + u[i - 1]);

		//���̌v�Z�̂��߂ɉ��x���X�V
		for (i = 1; i < ii; i++)
			u[i] = uu[i];

	} while (now < IC);

	for (i = 1; i < ii; i++)
		printf("%f\n", u[i]);

	return 0;
}