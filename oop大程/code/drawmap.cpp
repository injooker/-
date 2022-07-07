#ifndef FileName_H_
#define FileName_H_  

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
#include"drawmap.h"
#endif
int line[100][4] = { 0 }; int point[100][2] = { 0 }; float circle[100][3];
int li = 0, pi = 0, ci=0 , color;//��¼���е�ֱ��

/*
����OPENGLû��֧���ı�����ĺ����������Ҫ�õ����ֵ��������ı�������
*/
void selectFont(int size, int charset, const char* face)
{
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);//�����С������Ȳ���
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}


void drawCNString(const char* str)
{
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);


	// �����ַ��ĸ���
	// �����˫�ֽ��ַ��ģ����������ַ����������ֽڲ���һ���ַ�
	// ����һ���ֽ���һ���ַ�
	len = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}


	// ������ַ�ת��Ϊ���ַ�
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';


	// �������ַ�
	for (i = 0; i < len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}


	// ����������ʱ��Դ
	free(wstring);
	glDeleteLists(list, 1);
}

tang tangle[100]={0}; int ti = 0;
void* bitmap_fonts[7] = {
		GLUT_BITMAP_9_BY_15,
		GLUT_BITMAP_8_BY_13,
		GLUT_BITMAP_TIMES_ROMAN_10,
		GLUT_BITMAP_TIMES_ROMAN_24,
		GLUT_BITMAP_HELVETICA_10,
		GLUT_BITMAP_HELVETICA_12,
		GLUT_BITMAP_HELVETICA_18
};//����λͼ�Ȳ���
void print_bitmap_string(void* font, const char* s)
{
	if (s && strlen(s)) {
		while (*s) {
			glutBitmapCharacter(font, *s);
			s++;
		}
	}
}

/*
��������TextOut
���ã�������������ı�����
*/
int TextOut(float x, float y, const char* cstr)
{
	glRasterPos2f(x, y);
	print_bitmap_string(bitmap_fonts[4], cstr);
	return 1;
}

/*
��������DrawLine
���ã����ڻ����߶�
*/
void draw::DrawLine(int x0, int y0, int x1, int y1) {

	if (op == 1)	glBegin(GL_LINES);
	if (op == 2)   glBegin(GL_POINTS);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();
	glFlush();

}

/*
��������Drawtangle
����;���ڻ���������
*/
void draw::Drawtangle(int m0, int n0, int m1, int n1, int m2, int n2) {
	glBegin(GL_LINE_STRIP);
	glVertex2f(m0, n0);
	glVertex2f(m1, n1);
	glVertex2f(m2, n2);
	glVertex2f(m0, n0);
	glEnd();
	glFlush();
}
/*
��������Drawcircle
���ã����ڻ���Բ��
*/
void draw::Drawcircle(int x, int y, float r) {
	int n =40;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)     //ͨ����ѧ������������εĵ�
	{
		glVertex2f(x+r * cos(2 * 3.1415926 * i / n),y+ r* sin(2 * 3.1415926 * i / n));
	}
	glEnd();
	glFlush();

}


/*
�Ӳ˵���������ɫ��ѡ��
*/

void submenufunc1(int data) {
	switch (data) {
	case 1:
		color = 1;
		break;
	case 2:
		color = 3;
		break;
	case 3:
		color = 2;
		break;
	}
}
/*
mainMenu�������ڲ˵���ѡ�����ڻ���ͼ�ε�ȷ���Լ������ĳ�ʼ����
1Ϊ�߶Σ�2Ϊ�㣬3Ϊ�����Σ�4ΪԲ��5Ϊ������6Ϊѡ����ɫ
*/
void mainMenu(int id)
{
	switch (id)
	{
	case 1:
		op = 1;
		drawmap();
		break;
	case 2:
		op = 2;
		drawmap();
		break;
	case 3:
		op = 3;
		drawmap();
		break;
	case 4:
		op = 4;
		drawmap();
		break;
	case 5:
		op = 6;
		break;
	}
}
void init() {
	glClearColor(1, 1, 1, 1);//���û��ƴ�����ɫΪ��ɫ
	glClear(GL_COLOR_BUFFER_BIT);//�����������
	glPointSize(3.0f);//���õ�Ĵ�С
	/*����ΪͶӰ����ģʽ�������۲����*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 500, 0);
	glColor3f(0, 1, 0);//���û������ɫ
}
void zuobiaozhou() {
	glColor3f(0.0f, 0.0f, 0.0f);
	/*
	�����������������
	*/
	TextOut(-450, 260, "-19");
	TextOut(-400, 260, "-18");
	TextOut(-350, 260, "-17");
	TextOut(-300, 260, "-16");
	TextOut(-250, 260, "-15");
	TextOut(-200, 260, "-14");
	TextOut(-150, 260, "-13");
	TextOut(-100, 260, "-12");
	TextOut(-50, 260, "-11");
	TextOut(0, 260, "-10");
	TextOut(50, 260, "-9");
	TextOut(100, 260, "-8");
	TextOut(150, 260, "-7");
	TextOut(200, 260, "-6");
	TextOut(250, 260, "-5");
	TextOut(300, 260, "-4");
	TextOut(350, 260, "-3");
	TextOut(400, 260, "-2");
	TextOut(450, 260, "-1");
	TextOut(510, 260, "0");
	TextOut(550, 260, "1");
	TextOut(600, 260, "2");
	TextOut(650, 260, "3");
	TextOut(700, 260, "4");
	TextOut(750, 260, "5");
	TextOut(800, 260, "6");
	TextOut(850, 260, "7");
	TextOut(900, 260, "8");
	TextOut(950, 260, "9");
	TextOut(1000, 260, "10");
	TextOut(1050, 260, "11");
	TextOut(1100, 260, "12");
	TextOut(1150, 260, "13");
	TextOut(1200, 260, "14");
	TextOut(1250, 260, "15");
	TextOut(1300, 260, "16");
	TextOut(1350, 260, "17");
	TextOut(1400, 260, "18");
	TextOut(1450, 260, "19");
	/*
	�����������������
	*/
	TextOut(510, -690, "19");
	TextOut(510, -640, "18");
	TextOut(510, -590, "17");
	TextOut(510, -540, "16");
	TextOut(510, -490, "15");
	TextOut(510, -440, "14");
	TextOut(510, -390, "13");
	TextOut(510, -340, "12");
	TextOut(510, -290, "11");
	TextOut(510, -240, "10");
	TextOut(510, -190, "9");
	TextOut(510, -140, "8");
	TextOut(510, -90, "7");
	TextOut(510, -40, "6");
	TextOut(510, 10, "5");
	TextOut(510, 60, "4");
	TextOut(510, 110, "3");
	TextOut(510, 160, "2");
	TextOut(510, 210, "1");

	TextOut(510, 310, "-1");
	TextOut(510, 360, "-2");
	TextOut(510, 410, "-3");
	TextOut(510, 460, "-4");
	TextOut(510, 510, "-5");
	TextOut(510, 560, "-6");
	TextOut(510, 510, "-7");
	TextOut(510, 560, "-8");
	TextOut(510, 610, "-9");
	TextOut(510, 660, "-10");
	TextOut(510, 710, "-11");
	TextOut(510, 760, "-12");
	TextOut(510, 810, "-13");
	TextOut(510, 860, "-14");
	TextOut(510, 910, "-15");
	TextOut(510, 960, "-16");
	TextOut(510, 1010, "-17");
	TextOut(510, 1060, "-18");
	TextOut(510, 1110, "-19");
	glRasterPos2f(10, 10);

	/*
	��ҳ�����ϽǸ���ʹ��˵��
	*/
	selectFont(10, DEFAULT_CHARSET, "���ķ���");
	drawCNString(".......");
	glRasterPos2f(20, 40);
	selectFont(30, DEFAULT_CHARSET, "���ķ���");
	drawCNString("ʹ��˵����");

	glRasterPos2f(20, 100);
	selectFont(19, DEFAULT_CHARSET, "���ķ���");
	drawCNString("����Ҽ�ѡ��ͼ��");

	glRasterPos2f(20, 160);
	selectFont(19, DEFAULT_CHARSET, "���ķ���");
	drawCNString("����ڻ����л���ͼ��");


	TextOut(780, 260, "X");
	TextOut(510, 20, "y");
	glLineWidth(5.0);
	glBegin(GL_LINES);
	

	glVertex2f(-1200, 250);//��������
	glVertex2f(1800, 250);
	glVertex2f(500, -1200);//��������
	glVertex2f(500, 1500);

	/*������*/
	glVertex2f(450, 250);
	glVertex2f(450, 235);

	glVertex2f(400, 250);
	glVertex2f(400, 235);

	glVertex2f(350, 250);
	glVertex2f(350, 235);

	glVertex2f(300, 250);
	glVertex2f(300, 235);

	glVertex2f(250, 250);
	glVertex2f(250, 235);

	glVertex2f(550, 250);
	glVertex2f(550, 235);

	glVertex2f(600, 250);
	glVertex2f(600, 235);

	glVertex2f(650, 250);
	glVertex2f(650, 235);

	glVertex2f(700, 250);
	glVertex2f(700, 235);

	glVertex2f(750, 250);
	glVertex2f(750, 235);
	/*
	* �������ͷ
	*/
	for (int i = 16; i < 35; i++) {
		glVertex2f(i*50, 250);
		glVertex2f(i*50, 235);

		glVertex2f(-i * 50+1000, 250);
		glVertex2f(-i * 50+1000, 235);

		glVertex2f(500, -i * 50 + 1000);
		glVertex2f(515, -i * 50 + 1000);

		glVertex2f(500, i * 50 -300);
		glVertex2f(515, i * 50  -300);
	}
	glVertex2f(800, 250);
	glVertex2f(790, 260);

	glVertex2f(800, 250);
	glVertex2f(790, 240);

	/*������*/
	glVertex2f(500, 200);
	glVertex2f(515, 200);

	glVertex2f(500, 150);
	glVertex2f(515, 150);

	glVertex2f(500, 100);
	glVertex2f(515, 100);

	glVertex2f(500, 50);
	glVertex2f(515, 50);

	glVertex2f(500, 300);
	glVertex2f(515, 300);

	glVertex2f(500, 350);
	glVertex2f(515, 350);
	glVertex2f(500, 400);
	glVertex2f(515, 400);
	glVertex2f(500, 450);
	glVertex2f(515, 450);
	/*
	�������ͷ
	*/
	glVertex2f(500, 0);
	glVertex2f(490, 10);

	glVertex2f(500, 0);
	glVertex2f(510, 10);
	glEnd();
	glFlush();

	glLineWidth(1.0);
	glBegin(GL_LINES);
	for (int i = 0; i < 20; i++) {
		glVertex2f(500+50*i, -1200);
		glVertex2f(500+50*i, 1500);

		glVertex2f(500 -50 * i, -1200);
		glVertex2f(500 - 50 * i, 1500);

		glVertex2f(-1800, 250+50*i);
		glVertex2f(1800 , 250+50*i);

		glVertex2f(-1800, 250 - 50 * i);
		glVertex2f(1800, 250 - 50 * i);
	}
	  

	glEnd();
	glFlush();

}
/*
��������drawmap
���ã����ڻ�����ͼҳ�棬ͬʱ֧������������
�ָ�������

*/
void drawmap() {
	int i;
	draw D;
	/*
	��������ϵ��
	*/
	zuobiaozhou();
	
	/*
	���´������ڱ����Ѿ����Ƶ�ͼ��
	*/
	glLineWidth(2.0);
	/*�ָ��߶�*/
	glBegin(GL_LINES);
	for (i = 0; i < li; i++) {
		glVertex2f(line[i][0], line[i][1]);
		glVertex2f(line[i][2], line[i][3]);
	}
	glEnd();
	glFlush();
	/*
	�ָ���
	*/
	glBegin(GL_POINTS);
	for (i = 0; i < pi; i++) {
		glVertex2f(point[i][0], point[i][1]);

	}
	glEnd();
	glFlush();
	/*
	�ָ�������
	*/
	glBegin(GL_LINES);
	for (i = 0; i < ti; i++) {
		glVertex2f(tangle[i].a.x , tangle[i].a.y);
		glVertex2f(tangle[i].b.x , tangle[i].b.y);
		glVertex2f(tangle[i].b.x, tangle[i].b.y);
		glVertex2f(tangle[i].c.x , tangle[i].c.y);
		glVertex2f(tangle[i].c.x, tangle[i].c.y);
		glVertex2f(tangle[i].a.x, tangle[i].a.y);
	}
	glEnd();
	glFlush();
	/*
	
	�ָ�Բ
	
	*/
	for (i = 0; i < ci; i++) {
		D.Drawcircle(circle[i][0], circle[i][1], circle[i][2]);
	}
	
	/*
	* ѡ�����ͼ��ʱ����ɫ
	*/
	if (color == 1)glColor3f(1, 0, 0);
	if (color == 2)glColor3f(0, 1, 0);
	if (color == 3)glColor3f(0, 0, 1);
}

