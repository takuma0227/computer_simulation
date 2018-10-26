//3つのファイルを正規のフォルダに置けた場合
// #include <GL/glut.h>

//大学のPCの場合
#include "glut.h"

//何を描画するかを記述する関数
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	//ここから描画させる座標を、関数で指定する
	//カッコ内は、座標点をどのようにつなぐか
/*	glBegin(GL_LINE_STRIP);
	//二次元の座標点の指定(x, y)
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
	//ここまで
	glEnd();

	glFlush();
}

void init(void){
	//ウィンドウを塗りつぶす色を決める
	//カッコ内は、RGBとA(0:透明 1:不透明)
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