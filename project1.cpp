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
#include <GL/glut.h>				// include GLUT library
#include <math.h>
#include <string>

using namespace std;

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
	glColor3f(1, 0, 1);			// specify drawing color: red 
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
	glColor3f(0, 0, 0);
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


//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawAxes();

	drawText();

	drawPolygon();

	glFlush(); // flush out the buffer contents
}


//***********************************************************************************
void myInit()
{
	glClearColor(0.8, 0.8, 0.8, 0);			// specify a background color: grey
	gluOrtho2D(-700, 700, -700, 700);  // specify a viewing area
}

//***********************************************************************************
int main(int argc, char ** argv)
{//glutInit(& argc, argv);                  // optional in our environment

	glutInitWindowSize(700, 700);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Project 1");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop

	return 0;
}