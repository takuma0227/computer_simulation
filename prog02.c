//3�̃t�@�C���𐳋K�̃t�H���_�ɒu�����ꍇ
// #include <GL/glut.h>

//��w��PC�̏ꍇ
#include "glut.h"

//����`�悷�邩���L�q����֐�
void display(void){
	//�E�B���h�E��h��Ԃ�
	glClear(GL_COLOR_BUFFER_BIT);
	//���܂���OpenGL�̖��߂����s����
	glFlush();
}

void init(void){
	//�E�B���h�E��h��Ԃ��F�����߂�
	//�J�b�R���́ARGB��A(0:���� 1:�s����)
	glClearColor(0.0, 1.0, 1.0, 0.5);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	//�f�B�X�v���C�̐F���[�h�̎w��
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	//����display�֐������s�����
	glutMainLoop();

	return 0;
}