#ifndef FileName_H_
#define FileName_H_  

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
#include"drawmap.h"
#endif
int line[100][4] = { 0 }; int point[100][2] = { 0 }; float circle[100][3];
int li = 0, pi = 0, ci=0 , color;//记录已有的直线

/*
由于OPENGL没有支持文本输入的函数，因此需要用到汉字点阵设置文本的输入
*/
void selectFont(int size, int charset, const char* face)
{
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);//字体大小、间隔等参数
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}


void drawCNString(const char* str)
{
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);


	// 计算字符的个数
	// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
	// 否则一个字节算一个字符
	len = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}


	// 将混合字符转化为宽字符
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';


	// 逐个输出字符
	for (i = 0; i < len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}


	// 回收所有临时资源
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
};//汉字位图等参数
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
函数名：TextOut
作用：用于输出单个文本汉字
*/
int TextOut(float x, float y, const char* cstr)
{
	glRasterPos2f(x, y);
	print_bitmap_string(bitmap_fonts[4], cstr);
	return 1;
}

/*
函数名：DrawLine
作用：用于绘制线段
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
函数名：Drawtangle
作用;用于绘制三角形
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
函数名：Drawcircle
作用：用于绘制圆形
*/
void draw::Drawcircle(int x, int y, float r) {
	int n =40;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)     //通过数学计算来画多边形的点
	{
		glVertex2f(x+r * cos(2 * 3.1415926 * i / n),y+ r* sin(2 * 3.1415926 * i / n));
	}
	glEnd();
	glFlush();

}


/*
子菜单，用于颜色的选择
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
mainMenu函数用于菜单的选择，用于绘制图形的确定以及画布的初始化；
1为线段，2为点，3为三角形，4为圆，5为清屏，6为选择颜色
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
	glClearColor(1, 1, 1, 1);//设置绘制窗口颜色为白色
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口内容
	glPointSize(3.0f);//设置点的大小
	/*设置为投影类型模式和其他观察参数*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 500, 0);
	glColor3f(0, 1, 0);//设置画点的颜色
}
void zuobiaozhou() {
	glColor3f(0.0f, 0.0f, 0.0f);
	/*
	给横坐标轴标上数字
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
	给纵坐标轴标上数字
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
	在页面左上角附上使用说明
	*/
	selectFont(10, DEFAULT_CHARSET, "华文仿宋");
	drawCNString(".......");
	glRasterPos2f(20, 40);
	selectFont(30, DEFAULT_CHARSET, "华文仿宋");
	drawCNString("使用说明：");

	glRasterPos2f(20, 100);
	selectFont(19, DEFAULT_CHARSET, "华文仿宋");
	drawCNString("点击右键选择图形");

	glRasterPos2f(20, 160);
	selectFont(19, DEFAULT_CHARSET, "华文仿宋");
	drawCNString("左键在画布中绘制图像");


	TextOut(780, 260, "X");
	TextOut(510, 20, "y");
	glLineWidth(5.0);
	glBegin(GL_LINES);
	

	glVertex2f(-1200, 250);//横坐标轴
	glVertex2f(1800, 250);
	glVertex2f(500, -1200);//纵坐标轴
	glVertex2f(500, 1500);

	/*横坐标*/
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
	* 横坐标箭头
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

	/*纵坐标*/
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
	纵坐标箭头
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
函数名：drawmap
作用：用于绘制作图页面，同时支持清屏后重新
恢复坐标轴

*/
void drawmap() {
	int i;
	draw D;
	/*
	绘制坐标系；
	*/
	zuobiaozhou();
	
	/*
	以下代码用于保存已经绘制的图形
	*/
	glLineWidth(2.0);
	/*恢复线段*/
	glBegin(GL_LINES);
	for (i = 0; i < li; i++) {
		glVertex2f(line[i][0], line[i][1]);
		glVertex2f(line[i][2], line[i][3]);
	}
	glEnd();
	glFlush();
	/*
	恢复点
	*/
	glBegin(GL_POINTS);
	for (i = 0; i < pi; i++) {
		glVertex2f(point[i][0], point[i][1]);

	}
	glEnd();
	glFlush();
	/*
	恢复三角形
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
	
	恢复圆
	
	*/
	for (i = 0; i < ci; i++) {
		D.Drawcircle(circle[i][0], circle[i][1], circle[i][2]);
	}
	
	/*
	* 选择绘制图形时的颜色
	*/
	if (color == 1)glColor3f(1, 0, 0);
	if (color == 2)glColor3f(0, 1, 0);
	if (color == 3)glColor3f(0, 0, 1);
}

