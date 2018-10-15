/*==================================================================================================
 PROGRAMMER:			Zackh Tucker // Josiah McGurty
 COURSE:				CSC 525/625
 MODIFIED BY:			Zackh Tucker <tucker117> // Josiah McGurty <mcgurty1337>
 LAST MODIFIED DATE:	10.13.2018
 DESCRIPTION:			Lab project 1, culminated work from throughout the semester, working with
							1. Line Segments
							2. Pattern Filled polygons
							3. Circles
							4. Bitmaps
							5. Pixel maps
							6. Text
 NOTE:					Combining the work we've done throughout the semester into one project
 FILES:					project1.cpp, (labProject.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2017
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on labProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <fstream>
#include <GL/glut.h>				// include GLUT library
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n;
int m;
GLuint *image;

GLubyte pattern4Polygon[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
	0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
	0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
	0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
	0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
	0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
	0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
	0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
	0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
	0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
	0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
	0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
	0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
	0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
	0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08 };

/*========================================
	Function drawAxes()
	uses a line stipple	to create 4 individual
	segments of the total viewing screen.
	No arguments are given.
========================================*/
void drawAxes()
{
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0C0F);
	glPointSize(5);
	glBegin(GL_LINES);	// use the default point size: 1
	glColor3f(0.917, 0.879, 0.197);			// specify drawing color: yellow
	glVertex2f(0, -680);			// specify a point location
	glVertex2f(0, 680);		// 1 line
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-680, 0);
	glVertex2f(680, 0);
	glEnd();

	glDisable(GL_LINE_STIPPLE);
}

/*========================================
	Function drawText()
	Uses RasterText to render text on the screen,
	located in the top left of each 4 coordinates,
	dictating what will be drawn in each segment.
	No arguments are given.
========================================*/
void drawText()
{
	glColor3f(1, 1, 1);
	string x;
	x = "Pattern filled Polygon";
	glRasterPos2f(-650, 650);
	for (int i = 0; i < x.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, int(x[i]));
	}

	string x2;
	x2 = "Circle";
	glRasterPos2f(20, 650);
	for (int i = 0; i < x2.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, int(x2[i]));
	}

	string x3;
	x3 = "Bitmap";
	glRasterPos2f(-650, -40);
	for (int i = 0; i < x3.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, int(x3[i]));
	}

	string x4;
	x4 = "Pixel Map";
	glRasterPos2f(20, -40);
	for (int i = 0; i < x4.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, int(x4[i]));
	}
}

/*========================================
	Function drawPolygon()
	uses a polygon stipple kept in a global
	variable to render and fill a polygon,
	creating a diamond shape.
	No arguments are given.
========================================*/
void drawPolygon()
{
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(pattern4Polygon);
	glEnable(GL_POLYGON);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 1.0, 0.0);
	glVertex2f(-350, 450);
	glColor3f(0.5, 1.0, 0.0);
	glVertex2f(-600, 300);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-100, 300);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-350, 150);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-600, 300);
	glEnd();
	glDisable(GL_POLYGON);
	glDisable(GL_POLYGON_STIPPLE);
}

/* Function drawCirlce()
Draws a set of circles with increasing
diameter centered in the top-right
portion of the screen. */
void drawCircle() {
 const double pi = 3.1415926535897;
 glColor3f(0.193, 0.459, 0.778); // magestic blue
 int x = 0;
 int y = 0;
 int r = 10; // radius starts at 10 pixels
 glPointSize(1);
 glBegin(GL_POINTS);
 for (int z = 0; z <= 20; z++) {
	 for (int i = 0; i <= 400; i++) {
		double angle = 2 * pi * i / 400;
		double x = r * cos(angle);
		double y = r * sin(angle);
		x += 350; // center in the top-right portion
		y += 350; // center in the top-right portion
		glVertex2d(x, y); // plot the points
	 }
	 r += 15; // increase radius by 15, for z (20) times
 }
 glEnd();
}

/* Function drawBitmap()
Draws a Missouri State logo in the bottom-left
region of the screen utilizing a bitmap stored in
an array. Rendered in maroon. */
void drawBitmap() {
	GLubyte missouriStateLogo[] = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xf8,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xc0,0x00,0x1f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xff,0x00,0x00,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xfc,0x00,0x00,0x03,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xf8,0x00,0x00,0x01,0xff,0x80,0x00,0x00,0x00,0x00,0x7f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xf8,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xf0,0x00,0x00,0x00,0xff,0xc0,0x03,0xff,0xe0,0x07,0xff,0xf0,0x1f,0xfe,0x07,0xff,0x80,0x00,0xff,0xff,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xe0,0x00,0x00,0x00,0xff,0xe0,0x03,0xff,0x80,0x0f,0xff,0xf8,0x1f,0xfc,0x0f,0xff,0x00,0x07,0xff,0xff,0xc0,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,0x00,0x7f,0xf0,0x07,0xff,0x00,0x3f,0xfc,0x0c,0x3f,0xf8,0x0f,0xfe,0x00,0x0f,0xff,0x01,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x80,0x00,0x00,0x00,0x7f,0xf8,0x07,0xff,0x00,0x7f,0xf0,0x06,0x3f,0xf0,0x0f,0xfc,0x00,0x3f,0xfc,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x80,0x00,0x00,0x00,0x7f,0xf8,0x07,0xff,0x00,0xff,0xf0,0x03,0x3f,0xf0,0x0f,0xfc,0x00,0x7f,0xf8,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x7f,0xfc,0x07,0xfe,0x00,0xff,0xe0,0x01,0xff,0xe0,0x1f,0xfc,0x00,0xff,0xe0,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x3f,0xfc,0x07,0xfe,0x01,0xff,0xe0,0x01,0xff,0xe0,0x1f,0xfc,0x00,0xff,0xe0,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0x00,0x00,0x00,0x00,0x3f,0xfc,0x07,0xfe,0x01,0xff,0xe0,0x01,0xff,0xe0,0x1f,0xf8,0x01,0xff,0xc0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x3f,0xfe,0x07,0xfe,0x01,0xff,0xc0,0x00,0xff,0xe0,0x1f,0xf8,0x03,0xff,0x80,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x7f,0xfe,0x07,0xfe,0x01,0xff,0xc0,0x00,0xff,0xe0,0x1f,0xf8,0x03,0xff,0x80,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x7f,0xfe,0x07,0xfe,0x01,0xff,0xc0,0x00,0xff,0xe0,0x1f,0xf8,0x07,0xff,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x7f,0xfe,0x07,0xfe,0x01,0xff,0xc0,0x00,0xff,0xe0,0x1f,0xf8,0x07,0xff,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0xff,0xfe,0x07,0xfe,0x01,0xff,0xc0,0x00,0xff,0xe0,0x1f,0xf8,0x07,0xff,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x01,0xff,0xfe,0x07,0xfe,0x01,0xff,0xe0,0x00,0xff,0xe0,0x1f,0xf8,0x0f,0xff,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xfe,0x07,0xfe,0x01,0xff,0xe0,0x00,0xff,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xfe,0x07,0xfc,0x00,0xff,0xe0,0x00,0xff,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xfe,0x07,0xfc,0x00,0x7f,0xf0,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xff,0xfe,0x07,0xfc,0x00,0x3f,0xf8,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xff,0xfc,0x07,0xfc,0x00,0x1f,0xfc,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xff,0xff,0xff,0xfc,0x07,0xfc,0x00,0x07,0xfe,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xff,0xff,0xf8,0x07,0xfc,0x00,0x00,0xff,0x80,0x7f,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xff,0xf8,0x07,0xfc,0x00,0x00,0x0f,0xff,0xff,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xff,0xff,0xff,0xff,0xf0,0x07,0xfc,0x00,0x00,0x00,0x0f,0xff,0xe0,0x1f,0xf8,0x0f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xff,0xff,0xff,0xff,0xe0,0x07,0xfc,0x00,0x00,0x00,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,0xff,0xc0,0x07,0xfc,0x00,0x00,0x00,0x00,0x7f,0xe0,0x1f,0xf8,0x0f,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0x80,0x07,0xfc,0x00,0x18,0x00,0x00,0xff,0xe0,0x1f,0xf8,0x07,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xff,0xff,0xfe,0x00,0x07,0xfc,0x00,0x18,0x00,0x00,0xff,0xc0,0x1f,0xf8,0x07,0xfe,0x00,0x01,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xff,0xff,0xff,0xf8,0x00,0x07,0xfc,0x00,0x18,0x00,0x00,0xff,0xc0,0x1f,0xf8,0x07,0xff,0x00,0x01,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xff,0xc0,0x00,0x07,0xfc,0x00,0x3c,0x00,0x00,0xff,0xc0,0x1f,0xf8,0x03,0xff,0x00,0x03,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xfe,0x00,0x00,0x07,0xfc,0x00,0x3c,0x00,0x00,0xff,0xc0,0x1f,0xf8,0x03,0xff,0x00,0x03,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xc0,0x00,0x00,0x07,0xfc,0x00,0x3c,0x00,0x00,0xff,0xc0,0x1f,0xf8,0x01,0xff,0x00,0x03,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xff,0xf0,0x00,0x00,0x00,0x07,0xfc,0x00,0x7e,0x00,0x01,0xff,0x80,0x1f,0xf8,0x00,0xff,0x80,0x03,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xff,0x00,0x00,0x00,0x00,0x07,0xfc,0x00,0x7f,0x00,0x01,0xff,0x80,0x1f,0xf8,0x00,0x7f,0x80,0x07,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xf8,0x00,0x00,0x00,0x00,0x07,0xfc,0x00,0x7f,0x00,0x03,0xff,0x00,0x1f,0xf8,0x00,0x3f,0xc0,0x07,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xf0,0x00,0x00,0x00,0x00,0x7f,0xff,0xfc,0xff,0x80,0x07,0xfe,0x01,0xff,0xff,0xf8,0x1f,0xe0,0x0f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xc0,0x00,0x00,0x00,0x00,0x7f,0xff,0xfc,0x3f,0xe0,0x0f,0xf8,0x00,0xff,0xff,0xf8,0x07,0xf0,0x1f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xc0,0x00,0x00,0x01,0x80,0x3f,0xff,0xfe,0x07,0xfc,0x7f,0xe0,0x00,0x7f,0xff,0xf8,0x01,0xfc,0x7f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0x80,0x00,0x00,0x01,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xff,0x00,0x00,0x3f,0xf8,0x00,0x00,0x7f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0x80,0x00,0x00,0x01,0x80,0x07,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0x00,0x00,0x00,0x01,0xc0,0x01,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,0x03,0xc0,0x00,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,0x03,0xc0,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,0x07,0xe0,0x00,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x80,0x00,0x00,0x07,0xe0,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0x80,0x00,0x00,0x0f,0xe0,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xc0,0x00,0x00,0x1f,0xe0,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xc0,0x00,0x00,0x3f,0xf0,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0,0x00,0x00,0x7f,0xf0,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf0,0x00,0x00,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xfc,0x00,0x03,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0x00,0x0f,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0xff,0xff,0xfc,0x00,0x18,0x00,0x1f,0xff,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x3f,0xff,0xf0,0x00,0x1c,0x00,0x07,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x0f,0xff,0xc0,0x00,0x3c,0x00,0x01,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x0f,0xff,0x80,0x00,0x3e,0x00,0x01,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x07,0xff,0x00,0x00,0x7e,0x00,0x00,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x03,0xfe,0x00,0x00,0x7e,0x00,0x00,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xff,0xfc,0x00,0x00,0x03,0xff,0xf8,0x00,0x00,0x00,0x1f,0xfe,0x00,0x00,0x00,0x07,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x03,0xfe,0x00,0x00,0xff,0x00,0x00,0x7f,0xff,0x80,0x7f,0xff,0xc0,0x1f,0xff,0xff,0x80,0x00,0x3f,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xc0,0x00,0x00,0x3f,0xff,0xc0,0xff,0xf8,0x7f,0xff,0xc0,0x03,0xff,0xfc
,0x01,0xfc,0x00,0x00,0xff,0x00,0x00,0x7f,0xff,0x80,0x3f,0xff,0x00,0xff,0xc0,0x1f,0xe0,0x01,0xff,0x80,0x3f,0xc0,0x00,0x03,0xf8,0x07,0xf0,0x00,0x00,0x7f,0xff,0xe0,0xff,0xe0,0x3f,0xff,0x00,0x01,0xff,0xf8
,0x01,0xfc,0x00,0x00,0xff,0x00,0x00,0x7f,0xff,0x00,0x1f,0xff,0x03,0xff,0x00,0x07,0xf8,0x07,0xfe,0x00,0x0f,0xf0,0x00,0x0f,0xf0,0x03,0xfc,0x00,0x00,0xff,0xf1,0xf0,0xff,0xe0,0x1f,0xff,0x00,0x00,0xff,0xf0
,0x00,0xfc,0x00,0x01,0xff,0x80,0x00,0x7f,0xff,0x00,0x1f,0xfe,0x03,0xfe,0x00,0x03,0xfc,0x07,0xfc,0x00,0x07,0xf8,0x00,0x1f,0xe0,0x01,0xff,0x00,0x01,0xff,0xc0,0x78,0xff,0xc0,0x1f,0xfe,0x00,0x00,0xff,0xf0
,0x00,0xf8,0x00,0x01,0xff,0x80,0x00,0x7f,0xff,0x00,0x0f,0xfe,0x03,0xfc,0x00,0x03,0xfe,0x07,0xf8,0x00,0x07,0xfc,0x00,0x7f,0xc0,0x00,0xff,0x80,0x03,0xff,0x00,0x1d,0xff,0xc0,0x0f,0xfe,0x00,0x00,0x7f,0xf0
,0x00,0xf8,0x00,0x03,0xff,0xc0,0x00,0x7f,0xff,0x00,0x0f,0xfe,0x01,0xf8,0x00,0x01,0xff,0x03,0xf0,0x00,0x03,0xfe,0x00,0xff,0x80,0x00,0x7f,0xc0,0x03,0xff,0x00,0x0d,0xff,0x80,0x0f,0xfe,0x00,0x00,0x7f,0xe0
,0x00,0xf8,0x00,0x03,0xff,0xc0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x01,0xf8,0x00,0x01,0xff,0x83,0xf0,0x00,0x03,0xff,0x00,0xff,0x80,0x00,0x7f,0xe0,0x07,0xfe,0x00,0x0f,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x78,0x00,0x07,0xff,0xc0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x01,0xf0,0x00,0x01,0xff,0x83,0xe0,0x00,0x03,0xff,0x01,0xff,0x00,0x00,0x3f,0xe0,0x07,0xfe,0x00,0x07,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x78,0x00,0x07,0xff,0xe0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xf0,0x00,0x01,0xff,0x81,0xe0,0x00,0x03,0xff,0x03,0xff,0x00,0x00,0x3f,0xf0,0x07,0xfc,0x00,0x07,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x78,0x00,0x0f,0xff,0xe0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xe0,0x00,0x01,0xff,0xc1,0xc0,0x00,0x03,0xff,0x83,0xff,0x00,0x00,0x3f,0xf0,0x0f,0xfc,0x00,0x03,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x0f,0xff,0xf0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xe0,0x00,0x01,0xff,0xc1,0xc0,0x00,0x03,0xff,0x87,0xff,0x00,0x00,0x1f,0xf8,0x0f,0xfc,0x00,0x03,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x0f,0xff,0xf0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x60,0x00,0x03,0xff,0xc0,0xc0,0x00,0x07,0xff,0x87,0xfe,0x00,0x00,0x1f,0xf8,0x0f,0xfc,0x00,0x03,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x1f,0xff,0xf0,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x40,0x00,0x07,0xff,0xc0,0x80,0x00,0x0f,0xff,0x8f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x03,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x1f,0xff,0xf8,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x40,0x00,0x1f,0xff,0xc0,0x80,0x00,0x3f,0xff,0x8f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x3f,0xff,0xf8,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x00,0x00,0xff,0xff,0xc0,0x00,0x01,0xff,0xff,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x3f,0xff,0xfc,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x00,0x0f,0xff,0xff,0x80,0x00,0x1f,0xff,0xff,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x7f,0xff,0xfc,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x00,0xff,0xff,0xff,0x80,0x01,0xff,0xff,0xff,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0x7f,0xff,0xdc,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x03,0xff,0xff,0xff,0x00,0x07,0xff,0xff,0xfe,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0xff,0xff,0x8e,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x0f,0xff,0xff,0xfe,0x00,0x1f,0xff,0xff,0xfc,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x00,0xff,0xff,0x8e,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x1f,0xff,0xff,0xfc,0x00,0x3f,0xff,0xff,0xf8,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x01,0xff,0xff,0x06,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x3f,0xff,0xff,0xf0,0x00,0x7f,0xff,0xff,0xe0,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x01,0xff,0xff,0x07,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0xff,0xff,0xc0,0x00,0xff,0xff,0xff,0x80,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x03,0xff,0xfe,0x07,0x00,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0xff,0xfc,0x00,0x00,0xff,0xff,0xf8,0x00,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfe,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x03,0xff,0xfc,0x03,0x80,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0xff,0xc0,0x00,0x01,0xff,0xff,0x80,0x00,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfe,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x03,0xff,0xfc,0x03,0x80,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xff,0xfc,0x00,0x00,0x01,0xff,0xf8,0x00,0x00,0x0f,0xfe,0x00,0x00,0x1f,0xfc,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfe,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x07,0xff,0xf8,0x01,0x80,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xff,0xf0,0x00,0x00,0x01,0xff,0xe0,0x00,0x00,0x07,0xfe,0x00,0x00,0x1f,0xf8,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xff,0x00,0x00,0x7f,0xe0
,0x00,0x70,0x07,0xff,0xf8,0x01,0xc0,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xff,0xe0,0x00,0x08,0x01,0xff,0x80,0x00,0x10,0x07,0xff,0x00,0x00,0x1f,0xf8,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xff,0x80,0x00,0x7f,0xe0
,0x00,0x70,0x0f,0xff,0xf0,0x01,0xc0,0x7f,0xff,0x00,0x0f,0xfc,0x00,0xff,0xc0,0x00,0x0c,0x01,0xff,0x80,0x00,0x18,0x03,0xff,0x00,0x00,0x3f,0xf0,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xff,0xc1,0x00,0x7f,0xe0
,0x00,0x70,0x0f,0xff,0xf0,0x00,0xe0,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0xc0,0x00,0x1c,0x01,0xff,0x80,0x00,0x38,0x03,0xff,0x00,0x00,0x3f,0xf0,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xff,0xff,0x80,0x7f,0xe0
,0x00,0x70,0x1f,0xff,0xe0,0x00,0xe0,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0x80,0x00,0x1c,0x00,0xff,0x00,0x00,0x38,0x01,0xff,0x00,0x00,0x3f,0xe0,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfd,0xff,0x80,0x7f,0xe0
,0x00,0x70,0x1f,0xff,0xe0,0x00,0x60,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x7f,0xc0,0x00,0x3e,0x00,0xff,0x00,0x00,0x7c,0x00,0xff,0x80,0x00,0x7f,0xe0,0x0f,0xfc,0x00,0x01,0xff,0x80,0x0f,0xfc,0xff,0x80,0x7f,0xe0
,0x00,0x70,0x3f,0xff,0xc0,0x00,0x70,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x3f,0xc0,0x00,0x3e,0x00,0x7f,0x80,0x00,0x7c,0x00,0xff,0x80,0x00,0x7f,0xc0,0x1f,0xfc,0x00,0x03,0xff,0x80,0x0f,0xfc,0xff,0xc0,0x7f,0xe0
,0x00,0x70,0x3f,0xff,0xc0,0x00,0x70,0x7f,0xff,0x00,0x0f,0xfc,0x00,0x1f,0xc0,0x00,0x7e,0x00,0x7f,0x80,0x00,0xfc,0x00,0x7f,0xc0,0x00,0xff,0x80,0x1f,0xfc,0x00,0x03,0xff,0x80,0x1f,0xfc,0x7f,0xc0,0xff,0xe0
,0x00,0x70,0x7f,0xff,0x80,0x00,0x38,0x7f,0xff,0x00,0x1f,0xfc,0x00,0x1f,0xe0,0x00,0xff,0x00,0x3f,0xc0,0x01,0xfe,0x00,0x3f,0xe0,0x01,0xff,0x00,0x3f,0xfc,0x00,0x07,0xff,0x80,0x3f,0xfc,0x3f,0xc1,0xff,0xe0
,0x00,0x70,0x7f,0xff,0x80,0x00,0x38,0x7f,0xff,0x00,0xff,0xfc,0x00,0x07,0xf0,0x01,0xff,0x00,0x0f,0xe0,0x03,0xfe,0x00,0x0f,0xf0,0x03,0xfc,0x00,0xff,0xfc,0x00,0x1f,0xff,0x80,0xff,0xfc,0x1f,0xe7,0xff,0xe0
,0x00,0x70,0xff,0xff,0x00,0x00,0x38,0x7f,0xff,0x00,0x01,0xfc,0x00,0x03,0xf8,0x07,0xfe,0x00,0x07,0xf0,0x0f,0xfc,0x00,0x03,0xf8,0x07,0xf0,0x00,0x01,0xfc,0x00,0x00,0x7f,0x80,0x01,0xfc,0x0f,0xe0,0x1f,0xe0
,0x00,0x70,0xff,0xfe,0x00,0x00,0x1c,0x7f,0xff,0x00,0x00,0x0c,0x00,0x00,0xff,0xff,0xf0,0x00,0x01,0xff,0xff,0xe0,0x00,0x00,0xff,0xff,0xc0,0x00,0x00,0x0c,0x00,0x00,0x01,0x80,0x00,0x0c,0x07,0xe0,0x00,0x60
,0x00,0x71,0xff,0xfe,0x00,0x00,0x1c,0x7f,0xff,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,0x1f,0xfe,0x00,0x00,0x00,0x1f,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xf0,0x00,0x00
,0x00,0x71,0xff,0xfc,0x00,0x00,0x0c,0x7f,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x73,0xff,0xfc,0x00,0x00,0x0e,0x7f,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x00,0x73,0xff,0xf8,0x00,0x00,0x0e,0x7f,0xff,0x00,0x07,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x80
,0x00,0x73,0xff,0xf8,0x00,0x00,0x07,0x7f,0xff,0x00,0x0f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xc0
,0x00,0x77,0xff,0xf0,0x00,0x00,0x07,0x7f,0xff,0x00,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xe0
,0x00,0x7f,0xff,0xf0,0x00,0x00,0x03,0xff,0xff,0x00,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0
,0x00,0x7f,0xff,0xe0,0x00,0x00,0x03,0xff,0xff,0x00,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xf0
,0x00,0x7f,0xff,0xe0,0x00,0x00,0x03,0xff,0xff,0x00,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe0
,0x00,0x7f,0xff,0xc0,0x00,0x00,0x01,0xff,0xff,0x00,0x1f,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xe0
,0x00,0xff,0xff,0xc0,0x00,0x00,0x01,0xff,0xff,0x00,0x0f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xc0
,0x00,0xff,0xff,0x80,0x00,0x00,0x00,0xff,0xff,0x80,0x01,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00
,0x01,0xff,0xff,0x80,0x00,0x00,0x00,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x03,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x0f,0xff,0xff,0x00,0x00,0x00,0x00,0x7f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
	glColor3f(0.369, 0.0, 0.035);
	glRasterPos2i(-680, -520);
	glBitmap(320, 123, 0.0, 0.0, 0.0, 0.0, missouriStateLogo);
}

/* Function drawPixelmap()
Draws a Mandelbrot set (with primary colors) loaded from a pixel map stored in a file.
*/
void drawPixelmap() {
  printf("pixel map\n");
	glRasterPos2i(116, -700);
	glDrawPixels(n, m, GL_RGB, GL_UNSIGNED_INT, image);
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	drawAxes();
	drawPolygon();
	drawCircle();
	drawBitmap();
	drawPixelmap();
	drawText();
	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void myInit()
{
	glClearColor(0.1, 0.1, 0.1, 0);			// specify a background color: grey
	gluOrtho2D(-700, 700, -700, 700);  // specify a viewing area
}

//***********************************************************************************
int main(int argc, char ** argv)
{
	FILE *fd;
	int k, nm;
	char c;
	int i;
	char b[70];
	float s;
	int red, green, blue;
	//fd = fopen("/home/owner/Desktop/Mandelbrot.ppm", "r");
	fd = fopen("C:/TEMP/Mandelbrot.ppm", "r");
  fscanf(fd, "%[^\n]", b);
  if(b[0] != 'P'|| b[1] != '3') {
    printf("%s is not a PPM file!\n", b);
    exit(0);
  }
  printf("%s is a PPM file\n", b);
  fscanf(fd, "%c", &c);
  while(c == '#') {
    fscanf(fd, "%[^\n]", b);
    printf("%s\n", b);
    fscanf(fd, "%c", &c);
  }
  ungetc(c,fd);
  fscanf(fd, "%d %d %d", &n, &m, &k);

  printf("%d rows %d columns max value = %d\n", n, m, k);
  nm = n*m;
  image = (GLuint *)malloc(3*sizeof(GLuint)*nm);
  s = 255./k;
  for(i = 0; i < nm; i++) {
    fscanf(fd, "%d %d %d", &red, &green, &blue);
    image[3*nm - 3*i - 3] = red;
    image[3*nm - 3*i - 2] = green;
    image[3*nm - 3*i - 1] = blue;
  }
  printf("%s\n", b);
  printf("read image\n");
	glutInit(& argc, argv); // optional in some environments
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Project One");	// create a titled window
	myInit();									// setting up
	glutDisplayFunc(myDisplayCallback);		// register a callback
  glPixelTransferf(GL_RED_SCALE, s);
  glPixelTransferf(GL_GREEN_SCALE, s);
  glPixelTransferf(GL_BLUE_SCALE, s);
  glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	glutMainLoop();							// get into an infinite loop
	return 0;
}
