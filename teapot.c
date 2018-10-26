/* �e�B�[�|�b�g�̕`�� */

#include "glut.h"

GLfloat eye_position[] = { 40.0, 10.0, 20.0 };	//���_�̍��W
GLfloat light_position[] = { 100.0, 100.0, 100.0, 1.0 };	//�����̍��W

void myinit(void){
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	//�����̐ݒ�
	//������ ON OFF �̐ݒ�
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();	//���f���r���[�s��̏�����

	gluLookAt(eye_position[0], eye_position[1], eye_position[2],	//���E�ݒ�
					0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//���f�����O
	glutSolidTeapot(1.0);

	glFlush();
}

void myReshape(int w, int h){
	
	//�r���[�|�[�g�ݒ�
	glViewport(0, 0, w, h);
	//�ˉe�s�񃂁[�h�ϊ�
	glMatrixMode(GL_PROJECTION);
	//�ˉe�s��̏�����
	glLoadIdentity();

	//���̐ς̌`��ݒ�
	gluPerspective(10.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

	//�ˉe�s�񃂁[�h�ϊ�
	glMatrixMode(GL_MODELVIEW);
}

int main(void){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("�e�B�[�|�b�g��`��");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}