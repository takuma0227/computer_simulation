//3�̃t�@�C���𐳋K�̃t�H���_�ɒu�����ꍇ
// #include <GL/glut.h>

//��w��PC�̏ꍇ
#include "glut.h"

//����`�悷�邩���L�q����֐�
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	//��������`�悳������W���A�֐��Ŏw�肷��
	//�J�b�R���́A���W�_���ǂ̂悤�ɂȂ���
/*	glBegin(GL_LINE_STRIP);
	//�񎟌��̍��W�_�̎w��(x, y)
	glVertex2d(-0.9, 0.9);
	glVertex2d(0.0, -0.9);
	glVertex2d(0.0, 0.9);
	glVertex2d(0.9, -0.9);
*/
	glBegin(GL_POLYGON);
	glVertex2d(-0.5, 0.85);
	glVertex2d(0.5, 0.85);
	glVertex2d(1.0, 0.0);
	glVertex2d(0.5, -0.85);
	glVertex2d(-0.5, -0.85);
	glVertex2d(-1.0, 0.0);
	//�����܂�
	glEnd();

	glFlush();
}

void init(void){
	//�E�B���h�E��h��Ԃ��F�����߂�
	//�J�b�R���́ARGB��A(0:���� 1:�s����)
	glClearColor(0.0, 1.0, 1.0, 0.5);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}