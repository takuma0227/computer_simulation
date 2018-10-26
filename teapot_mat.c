//ティーポットの3D描画 対象の色・反射特性の設定

#include "glut.h"

GLfloat eye_position[] = { 40.0, 10.0, 20.0 };	//視点の座標

//ライティング
GLfloat light_position0[] = { 100.0, 100.0, 100.0, 1.0 },
		light_ambient0[] = { 0.1, 0.1, 0.1, 1.0 },	//環境光（周囲の色）
		light_diffuse0[] = { 0.5, 0.5, 0.5, 1.0 },	//拡散光（光源から広がる色）
		light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };	//反射光（光源が放つ光の色）

//物体表面
GLfloat mat_ambient0[] = { 0.5, 0.0, 0.0, 1.0 },	//環境光（環境光により照らしだされる色）
		mat_diffuse0[] = { 0.0, 0.5, 0.5, 1.0 },	//拡散光（物体自体の色）
		mat_specular0[] = { 0.0, 1.0, 1.0, 1.0 },	//反射光（光源部分の色）
		mat_shininess0[] = { 100.0 };				//鏡面指数（反射して見える領域の広さ）

void myinit(void){

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);	//光源の設定
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);

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

	glRotatef(45.0, 1.0, 0.0, 0.0);	//ティーポットを回転させる（x軸周りに60度）

	//モデリング
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular0);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess0);
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