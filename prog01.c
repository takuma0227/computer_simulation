//3�̃t�@�C���𐳋K�̃t�H���_�ɒu�����ꍇ
// #include <GL/glut.h>

//��w��PC�̏ꍇ
#include "glut.h"

//����`�悷�邩���L�q����֐�
void display(void){

}

int main(int argc, char *argv[]){
	//GLUT �� OPENGL �̏�����
	glutInit(&argc, argv);

	//�E�B���h�E���J��
	glutCreateWindow(argv[0]);

	//�E�B���h�E���ւ̕`������s����
	glutDisplayFunc(display);

	//�������[�v
	glutMainLoop();

	return 0;
}