#ifndef FileName_H_
#define FileName_H_  

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
#include"drawmap.h"
#endif

using namespace std;
draw D;
int m0, m1, n0, n1, m2, n2, op = 1,op1=0;//声明全局变量，起始坐标和终止坐标

/*
函数名：setPixel
作用：在页面中画点，与鼠标触发事件配合使用
*/
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
//鼠标拖动
/*
函数名：dragmouse
作用：实现在画点、三角形时实现线段随点的移动而移动
，提升绘图体验
*/
void dragmouse(int x, int y) {
	 {
		glClear(GL_COLOR_BUFFER_BIT);
		drawmap();
		if (flag == 1) {
			m1 = (x - dx - 500) / dz + 500;
			n1 = (y - dy - 250) / dz + 250;
		}
			setPixel( m1, n1);

	if(op==1||op==4)D.DrawLine(m0, n0, m1, n1);//画线
	if (op == 3 && flag == 2) { 
		m2 = (x - dx - 500) / dz + 500;
		n2 = (y - dy - 250) / dz + 250;
		D.Drawtangle(m0, n0, m1, n1, m2, n2); }
		glFlush();
	}

}
int flag = 0; //flag为0时表示是起点

//鼠标监听，画点
void mymouse(int button, int state, int x, int y) {
	/*
	鼠标触发事件，点击左下角的色块可选择相应的颜色
	*/
	

	if (op == 1 || op == 2) {
		op1 = op;
		if (flag == 0) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP  ){
				m0 = (x - dx-500 ) / dz +500;
				n0 = (y - dy-250 ) / dz +250;
				setPixel(m0, n0);
				flag = 1;

				if (op == 2) {
					point[pi][0] = m0; point[pi][1] = n0; pi++;
				}
				glBegin(GL_POINT);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
			}
		}
		else {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m1 = (x - dx - 500) / dz + 500;
				n1 = (y - dy - 250) / dz + 250;
				setPixel(m1, n1);//对鼠标点击过的点标记，便于使用者确定点击过的点
				D.DrawLine(m0, n0, m1, n1);//画线

				glFlush();
				glEnd();
				flag = 0;
				if (op == 1) {
					line[li][0] = m0; line[li][1] = n0;
					line[li][2] = m1; line[li][3] = n1;
					li++;
				}//记录已有的线段，便于恢复
				if (op == 2) {
					point[pi][0] = m1; point[pi][1] = n1; pi++;
				}//记录已有的点，便于恢复
				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m1, n1);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glEnd();
				glFlush();
			}
		}
	}

	if (op == 3) {//画三角形
		op1 = op;
		if (flag == 0) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m0 = (x - dx - 500) / dz + 500;
				n0 = (y-dy-250)/dz + 250;
				setPixel(m0, n0);//对鼠标点击过的点标记，便于使用者确定点击过的点
				flag = 1;
				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m0, n0);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glEnd();
				glFlush();
			}
		}
		else if (flag == 1) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m1 = (x - dx - 500) / dz + 500;
				n1 = (y-dy-250)/dz+250;
				setPixel(m1, n1);//对鼠标点击过的点标记，便于使用者确定点击过的点


				glFlush();
				glEnd();
				flag = 2;

				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m0, n0);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glEnd();
				glFlush();
			}
		}
		else {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
				m2 = (x - dx - 500) / dz + 500;
				n2 = (y - dy - 250) / dz + 250;
				setPixel(m2, n2);
				D.Drawtangle(m0, n0, m1, n1, m2, n2);//画线

				glFlush();
				glEnd();
				flag = 0;

				glBegin(GL_POINT);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
				tangle[ti].a.x = m0; tangle[ti].a.y = n0;
				tangle[ti].b.x = m1; tangle[ti].b.y = n1;
				tangle[ti].c.x = m2; tangle[ti].c.y = n2;
				ti++;//记录已有的三角形，便于之后恢复
			}
		}
	}
	if (op == 4) {//画圆
		op1 = op;
		if (flag == 0) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
				m0 = (x-dx-500)/dz+500;
				n0 = (y-dy-250)/dz+250;
				setPixel(m0, n0);
				flag = 1;
				glBegin(GL_POINT);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
			}
		}
		else {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m1 = (x -dx- 500) / dz +500;
				n1 = (y - dy -  250) / dz + 250;
				setPixel(m1, n1);
				r = pow((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0), 0.5);//计算圆的半径
				D.Drawcircle(m0, n0, r);//已知圆心和半径，画圆
				glFlush();
				glEnd();
				flag = 0;

				glBegin(GL_POINT);//对鼠标点击过的点标记，便于使用者确定点击过的点
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
				circle[ci][0] = m0; circle[ci][1] = n0; circle[ci][2] = r;
				ci++;//记录已经画过的圆，便于刷新后恢复
			}
		}
	}
	if (op == 6) {
		li = 0; pi = 0; ti = 0; flag = 0;
		ci = 0;
		glClear(GL_COLOR_BUFFER_BIT);
		op = op1;
		
		drawmap();
	}
}