#include <stdio.h>
#include <math.h>

//3つのファイルを正規のフォルダに置けた場合
//#include <GL/glut.h>

//大学のpcの場合
#include "glut.h"

void display(void){
	int i;
	double x;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);

	//座標軸を描く
	glBegin(GL_LINES);
	glVertex2d(-2.0, 0.0);
	glVertex2d(2.0, 0.0);
	glVertex2d(0.0, -2.0);
	glVertex2d(0.0, 2.0);
	glEnd();

	//２次曲線を描く
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 40; i++){
		//xを-2.0 ～ 2.0 まで変化させる
		x = (double)(i - 20) / 10.0;
		//y = x * x - 1.5 の曲線を描く
		glVertex2d(x, x*x - 1.5);
	}
	glEnd();

	//サイン曲線を描く
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
	glutCreateWindow("数学的な使い方");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}