//�e�B�[�|�b�g��3D�`�� �Ώۂ̐F�E���˓����̐ݒ�

#include "glut.h"

GLfloat eye_position[] = { 40.0, 10.0, 20.0 };	//���_�̍��W

//���C�e�B���O
GLfloat light_position0[] = { 100.0, 100.0, 100.0, 1.0 },
		light_ambient0[] = { 0.1, 0.1, 0.1, 1.0 },	//�����i���͂̐F�j
		light_diffuse0[] = { 0.5, 0.5, 0.5, 1.0 },	//�g�U���i��������L����F�j
		light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };	//���ˌ��i�����������̐F�j

//���̕\��
GLfloat mat_ambient0[] = { 0.5, 0.0, 0.0, 1.0 },	//�����i�����ɂ��Ƃ炵�������F�j
		mat_diffuse0[] = { 0.0, 0.5, 0.5, 1.0 },	//�g�U���i���̎��̂̐F�j
		mat_specular0[] = { 0.0, 1.0, 1.0, 1.0 },	//���ˌ��i���������̐F�j
		mat_shininess0[] = { 100.0 };				//���ʎw���i���˂��Č�����̈�̍L���j

void myinit(void){

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);	//�����̐ݒ�
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);

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

	glRotatef(45.0, 1.0, 0.0, 0.0);	//�e�B�[�|�b�g����]������ix�������60�x�j

	//���f�����O
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular0);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess0);
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