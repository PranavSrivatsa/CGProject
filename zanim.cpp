#include<glut.h>
#include<stdio.h>
#include<math.h>
#include<ctime>
#include<iostream>
using namespace std;
int switchs = 1;
float bottomx1 = 600, bottomx2 = 650, bottomy1 = 790, bottomy2 = 790;
float bottomx11 = 600, bottomx21 = 600, bottomy11 = 550, bottomy21 = 490;
float bottomx12 = 760, bottomx22 = 710, bottomy12 = 582, bottomy22 = 572;
bool notdone = true,flag = true, flag2 = true, flag3 = true, f1 = false, f2 = false;
float ypos = 10, c5 = 0.1,C4 = 0.1, hy = 0, hx1 = 0;
GLfloat alpha = 1;
float scale = 0.5, width, height;
const float DEG2RAD = 3.14159 / 180;
int ctr = 0,pages=1;

void reset_ln() {
	switchs = 1;
	alpha = 1;
	bottomx1 = 600, bottomx2 = 650, bottomy1 = 790, bottomy2 = 790;
	bottomx11 = 600, bottomx21 = 600, bottomy11 = 550, bottomy21 = 490;
	bottomx12 = 760, bottomx22 = 710, bottomy12 = 582, bottomy22 = 572;

	if (ctr == 15)
		ctr = 0;
}

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 0, 1080);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_NORMALIZE);
	glPointSize(5);
	glLineWidth(2);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	//glTranslatef(500, 200, 0);
	//glScalef(0.5, 0.5, 0.5);

}

void drawCircleFilled(double centerX, double centerY, double radiusX, double radiusY)
{

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerX, centerY);
	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2f(centerX + cos(degInRad) * radiusX,
			centerY + sin(degInRad) * radiusY);
	}
	glEnd();
	glFlush();
}
void drawmouth()
{
	glColor3f(0, 0, 0);
	float x2, y2;
	glBegin(GL_LINE_STRIP);
	for (float angle = 250.0; angle < 291.0; angle += 0.2)
	{
		x2 = 317.5 + cos(angle * DEG2RAD) * 40;
		y2 = 333 + sin(angle * DEG2RAD) * 40;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawface()
{
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(225, 330);
	glVertex2f(255, 430);
	glVertex2f(385, 430);
	glVertex2f(415, 330);
	glEnd();
	glFlush();
}

void drawcloud() {
	float angle, n = 6, x1, x2, y1, y2;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 650 + cos(angle) * 80;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= 8; i++) {
		x1 = 320 + 120 * sin((i * 360 / n) * DEG2RAD);
		y1 = 650 + 80 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 30;
			y2 = y1 + cos(angle) * 30;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	glFlush();
}
void thirdln() {
	//glScalef(0.5, 0.5, 1);
	glColor4f(1, 1, 0, alpha);
	if (switchs == 3) {

		if (bottomx22 < bottomx12) {
			bottomx12 -= 5;
			bottomx22 -= 2.5;
			bottomy12 -= 30;
			bottomy22 -= 30;
		}
		else
			switchs = 4;

		glBegin(GL_POLYGON);
		glVertex2f(710, 572);
		glVertex2f(760, 590);
		glVertex2f(bottomx12, bottomy12);
		glVertex2f(bottomx22, bottomy22);
		glEnd();
		glFlush();
		glLoadIdentity();
	}
}

void secondln() {
	//glScalef(0.5, 0.5, 1);

	glColor4f(1, 1, 0, alpha);

	if (switchs == 2) {

		if (bottomx11 < 700) {
			bottomx11 += 25;
			bottomx21 += 25;
			bottomy11 += 5.6;
			bottomy21 += 2;
		}
		else if(bottomx11 < 710) {
			
			bottomx11 += 10;
			bottomx21 += 5;
			bottomy11 += 1;
			bottomy21 += 1;
		}
		else
			switchs = 3;

		glBegin(GL_POLYGON);
		glVertex2f(623, 465);
		glVertex2f(628, 530);
		glVertex2f(bottomx11, bottomy11);
		glVertex2f(bottomx21, bottomy21);
		glEnd();
		//thirdln();
		glFlush();
		//glLoadIdentity();
	}
}

void drawlightning() {
	//glScalef(0.5, 0.5, 1);

	glColor4f(1, 1, 0, alpha);

	if (true) {
		if (bottomx2 > 625) {
			bottomx2 -= 2;
			bottomy1 -= 25;
			bottomy2 -= 25;
		}
		else
			switchs = 2;

		glBegin(GL_POLYGON);
		glVertex2f(600, 800);
		glVertex2f(650, 800);
		glVertex2f(bottomx2, bottomy1);
		glVertex2f(600, bottomy2);
		glEnd();
		glFlush();
		//glLoadIdentity();
	}
}
void resetpage2()
{
	c5 =0,ypos = 10, C4 = 0.1, hy = 0, hx1 = 0, f2 = f1 = false;;
	glutPostRedisplay();
}
void update(int)
{

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, update, 0);
	if (pages == 2) {
		if (ypos < 600)
			ypos += 10;
		if (hy < 45)
			hy += 1;
		if (hx1 < 20)
			hx1 += 1;
		if (C4 < 0.80) {
			C4 += 0.0035;
			c5 += 0.0025;
		}
		if (C4 >= 0.80)
			f1 = true;
	}
}

void drawbox1()
{

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(1800, 50);
	glVertex2f(1870, 50);
	glVertex2f(1870, 80);
	glVertex2f(1800, 80);
	glEnd();
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x >= 580 && x <= 850) && (y >= 480 && y <= 810)) {

		f2 = true;
		pages = 2;
		if (notdone) {
			glutTimerFunc(0, update, 0);
			notdone = false;
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x >= 1439 && x <= 1495) && (y >= 798 && y <= 822)) {
		pages = 1;
		resetpage2();
		
	}
}

void drawclouds(int x3, int y3, float s1, float s2)
{

	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;

	glTranslated(-250, 0, 0);
	glScalef(s1, s2, 0);

	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = x3 + sin(angle) * 180;
		y2 = y3 + cos(angle) * 120;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= 10; i++) {
		x1 = x3 + 157 * sin((i * 360 / 10) * DEG2RAD);
		y1 = y3 + 107 * cos((i * 360 / 10) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 52;
			y2 = y1 + cos(angle) * 52;
			glVertex2f(x2, y2);
		}
		glEnd();
	}


	glLoadIdentity();
	glFlush();
}

void drawfaceh()
{

	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;

	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 360; angle += 0.2)
	{
		x2 = 320 + sin(angle * DEG2RAD) * 95;
		y2 = 330 + cos(angle * DEG2RAD) * 120;
		glVertex2f(x2, y2);
	}
	glEnd();
}


void drawzeus() {
	glScalef(0.85, 0.85, 1);
	glTranslated(800, 400, 0);
	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;
	//thunderbolt
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(hx + 100 - hx1, 300 + hy);
	glVertex2f(hx + 120 - hx1, 200 + hy);
	glVertex2f(hx + 135 - hx1, 220 + hy);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(hx + 170 - hx1, 100 + hy);
	glVertex2f(hx + 150 - hx1, 250 + hy);
	glVertex2f(hx + 130 - hx1, 230 + hy);
	glEnd();

	//left hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = (x1 - hx1) + sin(angle) * radius;
		y2 = (y1 + hy) + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(hx + 150 - hx1, 195 + hy);
	glVertex2f(hx + 210, 250);
	glVertex2f(hx + 220, 240);
	glVertex2f(hx + 160 - hx1, 190 + hy);
	glEnd();

	//right robe flap
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(387, 237);
	glVertex2f(370, 90);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(385, 92);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(420, 95);
	glEnd();

	//right hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(395, 240);
	glVertex2f(405, 240);
	glVertex2f(417, 160);
	glVertex2f(405, 160);
	glVertex2f(405, 200);
	glEnd();

	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = 405 + sin(angle) * 12;
		y2 = 160 + cos(angle) * 12;
		glVertex2f(x2, y2);
	}
	glEnd();
	//robe lower
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(210, 130);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(215, 125);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(207, 110);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(242, 90);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(243, 120);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glVertex2f(265, 65);
	glVertex2f(310, 75);
	glVertex2f(365, 65);
	glVertex2f(390, 70);
	glVertex2f(382, 185);
	glEnd();

	//shading
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(265, 65);
	glColor3f(0.9, 0.9, 0.9);
	glVertex2f(278, 100);

	glVertex2f(300, 200);
	glEnd();

	//waist left
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(239, 220);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(260, 184);
	glVertex2f(245, 240);
	glEnd();

	//left crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(300, 165);
	glVertex2f(265, 65);
	glVertex2f(295, 70);
	glEnd();

	//right crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(320, 155);
	glVertex2f(325, 70);
	glVertex2f(355, 65);
	glEnd();

	//robe upper
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(245, 238);
	glVertex2f(260, 184);
	glVertex2f(265, 170);
	glVertex2f(300, 145);
	glVertex2f(330, 135);
	glVertex2f(385, 185);
	glVertex2f(355, 240);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(388, 75);
	glVertex2f(393, 77);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(398, 80);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(385, 185);
	glVertex2f(330, 135);
	glEnd();

	//waist right
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(355, 240);
	glVertex2f(385, 185);
	glVertex2f(390, 240);
	//glVertex2f(390, 77);
	glEnd();

	//mid left crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(280, 215);
	glVertex2f(288, 200);
	glVertex2f(320, 155);
	glVertex2f(360, 135);
	glVertex2f(330, 170);
	glEnd();

	//mid right crease
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(310, 215);
	glVertex2f(330, 190);
	glVertex2f(360, 160);
	glVertex2f(348, 190);
	glEnd();
	int n = 16;
	//zpratz
	//zhair
	glColor3f(0.55, 0.55, 0.55);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 350 + cos(angle) * 130;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n; i++) {
		x1 = 320 + 110 * sin((i * 360 / n) * DEG2RAD);
		y1 = 350 + 120 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 25;
			y2 = y1 + cos(angle) * 25;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zface
	drawface();
	//zbeard
	glColor3f(0.45, 0.45, 0.45);
	glBegin(GL_POLYGON);

	for (angle = 90; angle < 270; angle += 0.2)
	{
		x2 = 320 + sin(angle * DEG2RAD) * 95;
		y2 = 330 + cos(angle * DEG2RAD) * 100;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n / 2 - 1; i++) {
		//printf("%f\n",(i * 360 / n));
		x1 = 320 + 80 * sin((90 + i * 360 / n) * DEG2RAD);
		y1 = 330 + 95 * cos((90 + i * 360 / n) * DEG2RAD);
		//glVertex2f(x1, y1);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 35;
			y2 = y1 + cos(angle) * 35;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zeyes
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 280 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 355 + cos(angle * DEG2RAD) * 10;
		y2 = 350 + sin(angle * DEG2RAD) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	//zmouth
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 317.5 + cos(angle * DEG2RAD) * 30;
		y2 = 295 + sin(angle * DEG2RAD) * 20;
		glVertex2f(x2, y2);
	}

	glEnd();
	drawmouth();

	glLoadIdentity();
	glFlush();
}

void drawpos()
{
	glScalef(0.85, 0.85, 1);
	glTranslated(1420, 300, 0);
	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;
	//trident
	glColor3f(0.917, 0.717, 0.223);
	glBegin(GL_POLYGON);
	glVertex2f(170 + 17, 70);
	glVertex2f(180 + 17, 70);
	glVertex2f(130 + 17, 310);
	glVertex2f(120 + 17, 310);
	glEnd();

	glColor3f(0.403, 0.313, 0.094);
	glBegin(GL_POLYGON);
	glVertex2f(130 + 17, 310);
	glVertex2f(120 + 17, 310);
	glVertex2f(123 + 17, 295);
	glVertex2f(133 + 17, 295);
	glEnd();

	glColor3f(0.917, 0.717, 0.223);
	glBegin(GL_POLYGON);
	glVertex2f(120 + 17, 305);
	glVertex2f(95 + 17, 305);
	glVertex2f(95 + 17, 310);
	glVertex2f(120 + 17, 310);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex2f(130 + 17, 305);
	glVertex2f(152 + 17, 305);
	glVertex2f(152 + 17, 310);
	glVertex2f(130 + 17, 310);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex2f(95 + 17, 305);
	glVertex2f(100 + 17, 305);
	glVertex2f(95 + 17, 327);
	glVertex2f(90 + 17, 327);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(150 + 17, 305);
	glVertex2f(155 + 17, 305);
	glVertex2f(150 + 17, 330);
	glVertex2f(145 + 17, 330);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(120 + 19, 309);
	glVertex2f(127 + 19, 309);
	glVertex2f(122 + 19, 337);
	glVertex2f(115 + 19, 337);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex2f(141 + 17, 330);
	glVertex2f(145 + 17, 345);
	glVertex2f(155 + 17, 330);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex2f(87 + 17, 326);
	glVertex2f(90 + 17, 342);
	glVertex2f(100 + 17, 326);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(131, 336);
	glVertex2f(135, 352);
	glVertex2f(144, 336);
	glEnd();
	
	//left hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = (x1 - hx1) + sin(angle) * radius;
		y2 = (y1 + hy) + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(hx + 150 - hx1, 195 + hy);
	glVertex2f(hx + 210, 250);
	glVertex2f(hx + 220, 240);
	glVertex2f(hx + 160 - hx1, 190 + hy);
	glEnd();

	//right robe flap
	glColor3f(0.180, 0.376, 0.937);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(387, 237);
	glVertex2f(370, 90);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(385, 92);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(420, 95);
	glEnd();

	//right hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(395, 240);
	glVertex2f(405, 240);
	glVertex2f(417, 160);
	glVertex2f(405, 160);
	glVertex2f(405, 200);
	glEnd();

	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = 405 + sin(angle) * 12;
		y2 = 160 + cos(angle) * 12;
		glVertex2f(x2, y2);
	}
	glEnd();
	//robe lower
	glColor3f(0.180, 0.376, 0.937);
	glBegin(GL_POLYGON);
	glVertex2f(210, 130);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(215, 125);
	glEnd();

	glColor3f(0.180, 0.376, 0.937);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(207, 110);
	glColor3f(0.086, 0.286, 0.435);
	glVertex2f(242, 90);
	glColor3f(0.050, 0.176, 0.270);
	glVertex2f(243, 120);
	glEnd();

	glColor3f(0.486, 0.721, 0.894);
	glBegin(GL_POLYGON);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glVertex2f(265, 65);
	glVertex2f(310, 75);
	glVertex2f(365, 65);
	glVertex2f(390, 70);
	glVertex2f(382, 185);
	glEnd();

	//shading
	glColor3f(0.180, 0.376, 0.937);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glColor3f(0.486, 0.721, 0.894);
	glVertex2f(265, 65);
	glColor3f(0.647, 0.890, 0.952);
	glVertex2f(278, 100);

	glVertex2f(300, 200);
	glEnd();

	//waist left
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(239, 220);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(260, 184);
	glVertex2f(245, 240);
	glEnd();

	//left crease
	glColor3f(0.086, 0.317, 0.372);
	glBegin(GL_POLYGON);
	glVertex2f(300, 165);
	glVertex2f(265, 65);
	glVertex2f(295, 70);
	glEnd();

	//right crease
	glColor3f(0.086, 0.317, 0.372);
	glBegin(GL_POLYGON);
	glVertex2f(320, 155);
	glVertex2f(325, 70);
	glVertex2f(355, 65);
	glEnd();

	//robe upper
	glColor3f(0.221, 0.454, 0.698);
	glBegin(GL_POLYGON);
	glVertex2f(245, 238);
	glVertex2f(260, 184);
	glVertex2f(265, 170);
	glVertex2f(300, 145);
	glVertex2f(330, 135);
	glVertex2f(385, 185);
	glVertex2f(355, 240);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.221, 0.521, 0.698);
	glVertex2f(388, 75);
	glVertex2f(393, 77);
	glColor3f(0.243, 0.682, 0.878);
	glVertex2f(398, 80);
	glColor3f(0.221, 0.454, 0.698);
	glVertex2f(385, 185);
	glVertex2f(330, 135);
	glEnd();

	//waist right
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(355, 240);
	glVertex2f(385, 185);
	glVertex2f(390, 240);
	//glVertex2f(390, 77);
	glEnd();

	//mid left crease
	glColor3f(0.086, 0.317, 0.372);
	glBegin(GL_POLYGON);
	glVertex2f(280, 215);
	glVertex2f(288, 200);
	glVertex2f(320, 155);
	glVertex2f(360, 135);
	glVertex2f(330, 170);
	glEnd();

	//mid right crease
	glColor3f(0.086, 0.317, 0.372);
	glBegin(GL_POLYGON);
	glVertex2f(310, 215);
	glVertex2f(330, 190);
	glVertex2f(360, 160);
	glVertex2f(348, 190);
	glEnd();
	int n = 16;
	//zpratz
	//zhair
	glColor3f(0.250, 0.262, 0.388);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 350 + cos(angle) * 130;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n; i++) {
		x1 = 320 + 110 * sin((i * 360 / n) * DEG2RAD);
		y1 = 350 + 120 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 25;
			y2 = y1 + cos(angle) * 25;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zface
	drawfaceh();

	glColor3f(0.250, 0.262, 0.388);
	//cover face
	glBegin(GL_POLYGON);
	glVertex2f(225, 450);
	glVertex2f(250, 420);
	glVertex2f(390, 420);
	glVertex2f(415, 450);
	glEnd();

	//zbeard
	glColor3f(0.192, 0.196, 0.247);
	glBegin(GL_POLYGON);

	for (angle = 90; angle < 270; angle += 0.2)
	{
		x2 = 320 + sin(angle * DEG2RAD) * 96;
		y2 = 330 + cos(angle * DEG2RAD) * 70;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n / 2 - 1; i++) {
		//printf("%f\n",(i * 360 / n));
		x1 = 320 + 75 * sin((90 + i * 360 / n) * DEG2RAD);
		y1 = 320 + 80 * cos((90 + i * 360 / n) * DEG2RAD);
		//glVertex2f(x1, y1);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 35;
			y2 = y1 + cos(angle) * 35;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//zeyes
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 280 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 355 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();

	//zmouth
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 317 + cos(angle * DEG2RAD) * 30;
		y2 = 295 + sin(angle * DEG2RAD) * 20;
		glVertex2f(x2, y2);
	}

	glEnd();
	drawmouth();

	glLoadIdentity();
	glFlush();
}

void drawhades()
{
	glScalef(0.85, 0.85, 1);
	glTranslatef(200, 300, 0);
	float hx = 25, x1 = hx + 150, y1 = 190, x2, y2;
	float angle, radius = 10;

	glColor3f(0.65, 0.65, 0.65);
	glBegin(GL_POLYGON);
	glVertex2f(170 + 17, 70);
	glVertex2f(180 + 17, 70);
	glVertex2f(130 + 17, 310);
	glVertex2f(120 + 17, 310);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(130 + 17, 310);
	glVertex2f(120 + 17, 310);
	glVertex2f(123 + 17, 295);
	glVertex2f(133 + 17, 295);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(120 + 17, 305);
	glVertex2f(95 + 17, 305);
	glVertex2f(95 + 17, 310);
	glVertex2f(120 + 17, 310);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(130 + 17, 305);
	glVertex2f(152 + 17, 305);
	glVertex2f(152 + 17, 310);
	glVertex2f(130 + 17, 310);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(95 + 17, 305);
	glVertex2f(100 + 17, 305);
	glVertex2f(95 + 17, 327);
	glVertex2f(90 + 17, 327);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(155 + 17, 305);
	glVertex2f(150 + 17, 305);
	glVertex2f(145 + 17, 330);
	glVertex2f(150 + 17, 330);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(141 + 17, 330);
	glVertex2f(145 + 17, 345);
	glVertex2f(155 + 17, 330);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(87 + 17, 326);
	glVertex2f(90 + 17, 342);
	glVertex2f(100 + 17, 326);
	glEnd();

	//left hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = (x1)+sin(angle) * radius;
		y2 = (y1)+cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(150 + hx, 195);
	glVertex2f(210 + hx, 250);
	glVertex2f(220 + hx, 240);
	glVertex2f(160 + hx, 190);
	glEnd();

	//right robe flap
	glColor3f(0.2, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(387, 237);
	glVertex2f(370, 90);
	glColor3f(0.6, 0, 0);
	glVertex2f(385, 92);
	glColor3f(1, 0, 0);
	glVertex2f(420, 95);
	glEnd();

	//right hand
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(395, 240);
	glVertex2f(405, 240);
	glVertex2f(417, 160);
	glVertex2f(405, 160);
	glVertex2f(405, 200);
	glEnd();

	glBegin(GL_POLYGON);
	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = 405 + sin(angle) * 12;
		y2 = 160 + cos(angle) * 12;
		glVertex2f(x2, y2);
	}
	glEnd();
	//robe lower
	glColor3f(0.9, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(210, 130);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(215, 125);
	glEnd();

	glColor3f(0.7, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(207, 110);
	glColor3f(0.6, 0, 0);
	glVertex2f(242, 90);
	glColor3f(0.8, 0, 0);
	glVertex2f(243, 120);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glVertex2f(265, 65);
	glVertex2f(310, 75);
	glVertex2f(365, 65);
	glVertex2f(390, 70);
	glVertex2f(382, 185);
	glEnd();

	//shading
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(245, 185);
	glVertex2f(237, 70);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(265, 65);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(278, 100);

	glVertex2f(300, 200);
	glEnd();

	//waist left
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(239, 220);
	glVertex2f(240, 190);
	glVertex2f(245, 185);
	glVertex2f(260, 184);
	glVertex2f(245, 240);
	glEnd();

	//left crease
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 165);
	glVertex2f(265, 65);
	glVertex2f(295, 70);
	glEnd();

	//right crease
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(320, 155);
	glVertex2f(325, 70);
	glVertex2f(355, 65);
	glEnd();

	//robe upper
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(245, 238);
	glVertex2f(260, 184);
	glVertex2f(265, 170);
	glVertex2f(300, 145);
	glVertex2f(330, 135);
	glVertex2f(385, 185);
	glVertex2f(355, 240);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(388, 75);
	glVertex2f(393, 77);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(398, 80);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(385, 185);
	glVertex2f(330, 135);
	glEnd();

	//waist right
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	glVertex2f(355, 240);
	glVertex2f(385, 185);
	glVertex2f(390, 240);
	//glVertex2f(390, 77);
	glEnd();

	//mid left crease
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(280, 215);
	glVertex2f(288, 200);
	glVertex2f(320, 155);
	glVertex2f(360, 135);
	glVertex2f(330, 170);
	glEnd();

	//mid right crease
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(310, 215);
	glVertex2f(330, 190);
	glVertex2f(360, 160);
	glVertex2f(348, 190);
	glEnd();
	int n = 16;

	//hhair
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);

	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 320 + sin(angle) * 120;
		y2 = 350 + cos(angle) * 130;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n; i++) {
		x1 = 320 + 110 * sin((i * 360 / n) * DEG2RAD);
		y1 = 350 + 120 * cos((i * 360 / n) * DEG2RAD);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 25;
			y2 = y1 + cos(angle) * 25;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//hface
	drawfaceh();
	//hbeard
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);

	for (angle = 90; angle < 270; angle += 0.2)
	{
		x2 = 320 + sin(angle * DEG2RAD) * 95;
		y2 = 330 + cos(angle * DEG2RAD) * 100;
		glVertex2f(x2, y2);
	}
	glEnd();

	for (float i = 1; i <= n / 2 - 1; i++) {
		//printf("%f\n",(i * 360 / n));
		x1 = 320 + 80 * sin((90 + i * 360 / n) * DEG2RAD);
		y1 = 330 + 95 * cos((90 + i * 360 / n) * DEG2RAD);
		//glVertex2f(x1, y1);
		glBegin(GL_POLYGON);
		for (angle = 1.0f; angle < 361.0f; angle += 0.2)
		{
			x2 = x1 + sin(angle) * 35;
			y2 = y1 + cos(angle) * 35;
			glVertex2f(x2, y2);
		}
		glEnd();
	}
	//heyes
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 280 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 355 + cos(angle) * 10;
		y2 = 350 + sin(angle) * 10;
		glVertex2f(x2, y2);
	}
	glEnd();
	//hmouth
	glColor3f(0.96, 0.80, 0.69);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 317.5 + cos(angle * DEG2RAD) * 30;
		y2 = 295 + sin(angle * DEG2RAD) * 20;
		glVertex2f(x2, y2);
	}

	glEnd();
	drawmouth();

	glLoadIdentity();
	glFlush();
}

void drawgrass()
{
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	for (float angle = 65; angle <= 115.0; angle += 0.2)
	{
		float x2 = 935 + cos(angle * DEG2RAD) * 3000;
		float y2 = -3000 + sin(angle * DEG2RAD) * 3200;
		glVertex2f(x2, y2);
	}

	glEnd();
	glFlush();
}
void drawcirc(float x, float y, float z)
{
	glTranslatef(x, y, z);
	float angle, x2, y2;
	//glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (angle = 1.0; angle < 361.0; angle += 0.2)
	{
		x2 = 280 + cos(angle) * 5;
		y2 = 350 + sin(angle) * 5;
		glVertex2f(x2, y2);
	}
	glEnd();
	glLoadIdentity();
}

void display() {
	if (pages == 1) {
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < 10; i++)
		{
			float v1, v2;
			v1 = rand() % 1920;
			v2 = rand() % 1080;
			glColor3f(1,1,1);
			drawcirc(-250 + v1, -300 + v2, 0);
		}
		glutPostRedisplay();
		drawzeus();
		drawpos();
		drawhades();
		glutSwapBuffers();
		glFlush();
	}
	else if (pages == 2) {
		glClearColor(0.567320 - c5, 0.806536 - c5, 0.906536 - c5, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		drawgrass();
		glScalef(1.1, 1.1, 1);
		glTranslatef(-90, -300, 0);
		drawzeus();
		glLoadIdentity();
		drawbox1();
		if (f1 == true && ctr % 5 == 0)
		{
			glScalef(1, 0.75, 0.75);
			glTranslatef(-100, 270, 0);
			drawlightning();
			secondln();
			thirdln();


			glLoadIdentity();

			if (switchs == 5) {
				reset_ln();
			}
		}
		if (f1 == true && ctr % 3 == 0)
		{
			glScalef(1, 0.75, 0.75);
			glTranslatef(720, 270, 0);
			drawlightning();
			secondln();
			thirdln();
			glLoadIdentity();
			if (switchs == 5) {
				reset_ln();
			}
		}
		if (f1 == true)
		{
			glScalef(1, 0.75, 0.75);
			glTranslatef(5720, 5270, 0);
			drawlightning();
			secondln();
			thirdln();
			if (switchs == 4) {
				alpha -= 0.05;
				if (alpha < 0.1) {
					ctr++;
					reset_ln();
					switchs = 5;
				}
			}
			glLoadIdentity();
			if (switchs == 5) {
				reset_ln();
			}
		}
		glColor3f(1 - C4, 1 - C4, 1 - C4);
		drawclouds(550, 1510 - ypos, 0.80, 0.80);
		drawclouds(770, 1510 - ypos, 1, 1);
		drawclouds(1480, 1510 - ypos, 0.80, 0.80);
		drawclouds(1600, 1510 - ypos, 1, 1);
		drawclouds(2450, 1510 - ypos, 0.80, 0.80);
		glutSwapBuffers();
		glFlush();
	}
	
}
//void idle() {
//
//	if (f2 == true)
//	{
//		glScalef(1, 0.75, 0.75);
//		glTranslatef(-80, 270, 0);
//		drawlightning();
//		secondln();
//		thirdln();
//		if (ypos < 600)
//			ypos += 10;
//		if (hy < 45)
//			hy += 1;
//		if (hx1 < 20)
//			hx1 += 1;
//		if (C4 < 0.50)
//			C4 += 0.0035;
//		if (C4 >= 0.50)
//			f1 = true;
//	}
//	glLoadIdentity();
//	
//}


//void reshape(int w, int h) {
//	
//	if(w>=h)
//		glViewport(0, 0, (GLsizei)h, (GLsizei)h);
//	else
//		glViewport(0, 0, (GLsizei)w, (GLsizei)w);
//}

void reshape(int width, int height)
{
	::width = width;
	::height = height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);        // set projection parameters
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);
	//glutTimerFunc(0, update, 0);
	glMatrixMode(GL_MODELVIEW);        // set projection parameters
	//glLoadIdentity();
	glScalef(0.5, 0.5, 0.5);
	glTranslatef(1100, 400, 0);

}



void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Zues");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	//glutTimerFunc(0, update, 0);

	glutFullScreen();
	//glutIdleFunc(idle);

	//glutReshapeFunc(reshape);
	glutMainLoop();
}
