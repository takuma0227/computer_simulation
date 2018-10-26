//3つのファイルを正規のフォルダに置けた場合
// #include <GL/glut.h>

//大学のPCの場合
#include "glut.h"

//何を描画するかを記述する関数
void display(void){

}

int main(int argc, char *argv[]){
	//GLUT と OPENGL の初期化
	glutInit(&argc, argv);

	//ウィンドウを開く
	glutCreateWindow(argv[0]);

	//ウィンドウ内への描画を実行する
	glutDisplayFunc(display);

	//無限ループ
	glutMainLoop();

	return 0;
}