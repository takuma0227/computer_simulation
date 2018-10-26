/* ティーポットの描画 */

#include "glut.h"

GLfloat eye_position[] = { 40.0, 10.0, 20.0 };	//視点の座標
GLfloat light_position[] = { 100.0, 100.0, 100.0, 1.0 };	//光源の座標

void myinit(void){
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	//光源の設定
	//光源の ON OFF の設定
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();	//モデルビュー行列の初期化

	gluLookAt(eye_position[0], eye_position[1], eye_position[2],	//視界設定
					0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//モデリング
	glutSolidTeapot(1.0);

	glFlush();
}

void myReshape(int w, int h){
	
	//ビューポート設定
	glViewport(0, 0, w, h);
	//射影行列モード変換
	glMatrixMode(GL_PROJECTION);
	//射影行列の初期化
	glLoadIdentity();

	//視体積の形状設定
	gluPerspective(10.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

	//射影行列モード変換
	glMatrixMode(GL_MODELVIEW);
}

int main(void){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("ティーポットを描く");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}