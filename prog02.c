//3つのファイルを正規のフォルダに置けた場合
// #include <GL/glut.h>

//大学のPCの場合
#include "glut.h"

//何を描画するかを記述する関数
void display(void){
	//ウィンドウを塗りつぶす
	glClear(GL_COLOR_BUFFER_BIT);
	//溜まったOpenGLの命令を実行する
	glFlush();
}

void init(void){
	//ウィンドウを塗りつぶす色を決める
	//カッコ内は、RGBとA(0:透明 1:不透明)
	glClearColor(0.0, 1.0, 1.0, 0.5);
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	//ディスプレイの色モードの指定
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	//次でdisplay関数が実行される
	glutMainLoop();

	return 0;
}