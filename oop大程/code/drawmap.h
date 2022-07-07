#pragma once
class Point {
public:
	int x, y;
	Point(int x1 = 0, int y1 = 0) {
		x = x1; y = y1;
	}
};
class draw:public Point{
public:
	void DrawLine(int, int, int, int); //实际上画直线的函数
	void Drawtangle(int, int, int, int, int, int);
	void Drawcircle(int, int, float);
};

void init();
void drawmap();
void zuobiaozhou();
void submenufunc1(int data);

void mainMenu(int id);
void drawCNString(const char* str);
void dragmouse(int x, int y);
void mymouse(int button, int state, int x, int y);
void selectFont(int size, int charset, const char* face);
extern int line[100][4]  , point[100][2], color;
extern float circle[100][3];
extern float r;
extern int li , pi ,ti , ci;//
extern double dz, dx, dy;
extern int m0, m1, n0, n1, op , flag;//声明全局变量，起始坐标和终止坐标

class tang {
public:
	Point a, b, c;
	tang(int m0 = 0, int n0 = 0, int m1 = 0, int n1 = 0, int m2 = 0, int n2 = 0) { a.x = m0; a.y = n0; b.x = m1; b.y = n1; c.x = m2; c.y = n2; }
};
extern tang tangle[100];

class maping {
	void drawmap1();
	void zuobiaozhou1();
};