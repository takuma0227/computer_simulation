#include <stdio.h>
#include <math.h>

//3�̃t�@�C���𐳋K�̃t�H���_�ɒu�����ꍇ
//#include <GL/glut.h>

//��w��pc�̏ꍇ
#include "glut.h"

void display(void){
	int i;
	double x;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);

	//���W����`��
	glBegin(GL_LINES);
	glVertex2d(-2.0, 0.0);
	glVertex2d(2.0, 0.0);
	glVertex2d(0.0, -2.0);
	glVertex2d(0.0, 2.0);
	glEnd();

	//�Q���Ȑ���`��
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 40; i++){
		//x��-2.0 �` 2.0 �܂ŕω�������
		x = (double)(i - 20) / 10.0;
		//y = x * x - 1.5 �̋Ȑ���`��
		glVertex2d(x, x*x - 1.5);
	}
	glEnd();

	//�T�C���Ȑ���`��
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 40; i++){
		x = (double)(i - 20) / 10.0;
		glVertex2d(x, sin(x));
	}
	glEnd();

	glFlush();
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("���w�I�Ȏg����");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}