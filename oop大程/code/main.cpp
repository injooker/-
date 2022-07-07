#ifndef FileName_H_
#define FileName_H_   

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
#include"drawmap.h"
#endif
using namespace std;
double  dx = 0, dy = 0;
double dz = 1;
int winwidth = 800, winheight = 500;//窗口长宽
float r;


//数据交换
void swap(GLint& a, GLint& b) { GLint t = a; a = b; b = t; }
//在屏幕上画一个点

/*
设置键盘触发事件
主要用于页面的平移和放缩

平移按键：w,a,s,d;
放大：z
缩小：x
*/
void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'z':
		dz = dz * 1.1;
	{   glTranslatef(500, 250,0);
		glScalef(1.1, 1.1, 1.1);
		glTranslatef(-500, -250,0);
		glClear(GL_COLOR_BUFFER_BIT);
		drawmap();
		break;
	}
	
	case 'x':
		dz = dz * 0.9;
	{ glTranslatef(500, 250, 0);
		glScalef(0.9, 0.9, 0.9);
		glTranslatef(-500, -250, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		drawmap();
		break;
	}
	
	case 'd':
		dx = (dx - 10*dz) ;
	{   glTranslatef(-10, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawmap();
	break;
	}
	case 'a':
		dx = (dx + 10*dz);
	{   glTranslatef(10, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawmap();
	break;
	}
	case 'w':
		dy = (dy + 10*dz);
	{   glTranslatef(0, 10, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawmap();
	break;
	}
	case 's':
		dy = (dy - 10*dz);
	{   glTranslatef(0, -10, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawmap();
	break;
	}
	
	
	
	
	}
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);//初始化
//	scanf("%d%d",&m0,&n0);
//	m1=m0,n1=n0;//让起始点与目标点重合

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//设置绘制模式
	glutInitWindowPosition(150, 100);//设置窗口出现的位置
	glutInitWindowSize(winwidth, winheight);//设置窗口大小
	glutCreateWindow("几何绘图程序");//创建窗口
	init();
	int submenu1 = glutCreateMenu(submenufunc1);
		glutAddMenuEntry("red", 1); 
		glutAddMenuEntry("blue", 2);
		glutAddMenuEntry("green", 3);
		glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutCreateMenu(mainMenu);			//创建主菜单，并使用回调函数mainMenu
	glutAddMenuEntry("line", 1);		//加入菜单项
	glutAddMenuEntry("point", 2);
	glutAddMenuEntry("triangle", 3);
	glutAddMenuEntry("circle", 4);
	glutAddMenuEntry("initial", 5);

	glutAddSubMenu("color", submenu1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutDisplayFunc(drawmap);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(mymouse);//鼠标监听回调函数
	glutMotionFunc(dragmouse);//鼠标拖动
	glutMainLoop();
                                                                                                                                                    	
}

