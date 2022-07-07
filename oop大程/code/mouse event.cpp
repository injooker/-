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
int m0, m1, n0, n1, m2, n2, op = 1,op1=0;//����ȫ�ֱ�������ʼ�������ֹ����

/*
��������setPixel
���ã���ҳ���л��㣬����괥���¼����ʹ��
*/
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
//����϶�
/*
��������dragmouse
���ã�ʵ���ڻ��㡢������ʱʵ���߶������ƶ����ƶ�
��������ͼ����
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

	if(op==1||op==4)D.DrawLine(m0, n0, m1, n1);//����
	if (op == 3 && flag == 2) { 
		m2 = (x - dx - 500) / dz + 500;
		n2 = (y - dy - 250) / dz + 250;
		D.Drawtangle(m0, n0, m1, n1, m2, n2); }
		glFlush();
	}

}
int flag = 0; //flagΪ0ʱ��ʾ�����

//������������
void mymouse(int button, int state, int x, int y) {
	/*
	��괥���¼���������½ǵ�ɫ���ѡ����Ӧ����ɫ
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
				glBegin(GL_POINT);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
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
				setPixel(m1, n1);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				D.DrawLine(m0, n0, m1, n1);//����

				glFlush();
				glEnd();
				flag = 0;
				if (op == 1) {
					line[li][0] = m0; line[li][1] = n0;
					line[li][2] = m1; line[li][3] = n1;
					li++;
				}//��¼���е��߶Σ����ڻָ�
				if (op == 2) {
					point[pi][0] = m1; point[pi][1] = n1; pi++;
				}//��¼���еĵ㣬���ڻָ�
				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m1, n1);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				glEnd();
				glFlush();
			}
		}
	}

	if (op == 3) {//��������
		op1 = op;
		if (flag == 0) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m0 = (x - dx - 500) / dz + 500;
				n0 = (y-dy-250)/dz + 250;
				setPixel(m0, n0);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				flag = 1;
				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m0, n0);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				glEnd();
				glFlush();
			}
		}
		else if (flag == 1) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
				m1 = (x - dx - 500) / dz + 500;
				n1 = (y-dy-250)/dz+250;
				setPixel(m1, n1);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�


				glFlush();
				glEnd();
				flag = 2;

				glBegin(GL_POINT);
				glPointSize(5.0f);
				glVertex2f(m0, n0);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				glEnd();
				glFlush();
			}
		}
		else {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
				m2 = (x - dx - 500) / dz + 500;
				n2 = (y - dy - 250) / dz + 250;
				setPixel(m2, n2);
				D.Drawtangle(m0, n0, m1, n1, m2, n2);//����

				glFlush();
				glEnd();
				flag = 0;

				glBegin(GL_POINT);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
				tangle[ti].a.x = m0; tangle[ti].a.y = n0;
				tangle[ti].b.x = m1; tangle[ti].b.y = n1;
				tangle[ti].c.x = m2; tangle[ti].c.y = n2;
				ti++;//��¼���е������Σ�����֮��ָ�
			}
		}
	}
	if (op == 4) {//��Բ
		op1 = op;
		if (flag == 0) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
				m0 = (x-dx-500)/dz+500;
				n0 = (y-dy-250)/dz+250;
				setPixel(m0, n0);
				flag = 1;
				glBegin(GL_POINT);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
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
				r = pow((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0), 0.5);//����Բ�İ뾶
				D.Drawcircle(m0, n0, r);//��֪Բ�ĺͰ뾶����Բ
				glFlush();
				glEnd();
				flag = 0;

				glBegin(GL_POINT);//����������ĵ��ǣ�����ʹ����ȷ��������ĵ�
				glPointSize(5.0f);
				glVertex2f(m0, n0);
				glEnd();
				glFlush();
				circle[ci][0] = m0; circle[ci][1] = n0; circle[ci][2] = r;
				ci++;//��¼�Ѿ�������Բ������ˢ�º�ָ�
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