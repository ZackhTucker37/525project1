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


void drawAxes()
{
	glColor3f(1, 1, 1);
	char y;
	y = 'Y';
	glRasterPos2f(-3, 155);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, int(y));

	char x;
	x = 'X';
	glRasterPos2f(155, -3);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, int(x));

	glPointSize(1);		// change point size back to 1

	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	glColor3f(0, 0, 0);			 // change drawing color to black
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawAxes();

	glFlush(); // flush out the buffer contents
}


//***********************************************************************************
void myInit()
{
	glClearColor(0.8, 0.8, 0.8, 0);			// specify a background color: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
int main(int argc, char ** argv)
{//glutInit(& argc, argv);                  // optional in our environment

	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Mouse-click drawing");	// create a titled window

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop

	return 0;
}