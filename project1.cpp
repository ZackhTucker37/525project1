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
	uses a line stipple	to create 4 individual
	segments of the total viewing screen.
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

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawAxes();

	drawText();

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