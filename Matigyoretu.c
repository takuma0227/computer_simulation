//�҂��s��v���O����

#include <stdio.h>

#define N 6	//�d�|���i��
#define M 12	//�C�x���g���X�g�̋L�^�� M = N * 2

int arrival_time[N] = { 0, 2, 6, 7, 9, 15 };	//�e�d�|���i�̓�������
int shori_time[N] = { 2, 1, 3, 2, 1, 4 };	//�e�d�|���i�̏�������

int start_time[N], wait_num, wait_top, end_time, j, now, sv_stat, i_shori, i_arrival;

void Initiate(void);	//�ϐ��̏�����
void EventChoise(void);	//�C�x���g����
void ArriveEvent(void);	//�����C�x���g
void OutEvent(void);	//�ދ��C�x���g
void WriteEventList(int);	//�C�x���g���X�g�̋L�^

int main(void){

	printf(" �����C�x���g �d�|���i�ԍ� ����\n");
	printf("--------------------------------\n");

	Initiate();

	while (!((wait_num == 0) && (sv_stat == 0) && (i_arrival >= N))){
		j++;
		EventChoise();
	}

	return 0;
}

void Initiate(void){
	now = 0;
	wait_num = 0;
	wait_top = 0;
	j = 0;
	sv_stat = 0;
	i_arrival = 0;
	end_time = 9999;

	ArriveEvent();
	i_arrival++;
}

void EventChoise(void){
	if ((arrival_time[i_arrival] < end_time) && (i_arrival < N)){
		now = arrival_time[i_arrival];
		ArriveEvent();
		i_arrival++;
	}
	else{
		now = end_time;
		OutEvent();
	}
}

void ArriveEvent(void){
	if ((wait_num == 0) && (sv_stat == 0)){
		sv_stat = 1;
		i_shori = i_arrival;
		start_time[i_arrival] = now;
		end_time = now + shori_time[i_shori];
	}
	else{
		wait_num++;
		if (wait_num == 1) wait_top = i_arrival;
	}
	WriteEventList(0);
}

void OutEvent(void){
	if (wait_num == 0){
		sv_stat = 0;
		end_time = 9999;
		WriteEventList(1);
	}
	else{
		WriteEventList(1);
		i_shori = wait_top;
		wait_num--;
		if (wait_num != 0) wait_top++;
		start_time[i_shori] = now;
		end_time = now + shori_time[i_shori];
	}
}

void WriteEventList(int cb){
	printf("%13s%13d%5d\n", (cb) ? "�ދ�" : "����",(cb)?i_shori+1:i_arrival+1 , now);
}