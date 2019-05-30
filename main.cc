#ifndef MAIN
#define MAIN

using namespace std;

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <iostream>
#include <string.h>
bool filled = false;
bool drawAxis = false;
bool drawSign = false;
float zoomy = 0.0;
int persp = 1;


// the keyboard commands 
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') exit(0);
	if (key == 'r')
	{
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;

	}
	if (key == 's' || key == 'S')
	{
		yDeltaSpin = 0.0;
		xDeltaSpin = 0.0;
		zDeltaSpin = 0.0;
	}
	if (key == 'R')
	{
		filled = false;
		drawAxis = false;
		drawSign = false;
		zoomy = 0.0;
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;

	}
	if (key == 'x' || key == 'X') 
	{	
		xDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'y' || key == 'Y') 
	{	
		yDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'z' || key == 'Z') 
	{	
		zDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'f' || key == 'F') filled = !filled;

	glutPostRedisplay();
}
// special keyboard commands to zoom in and zoomout 
void special(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
		zoomy = zoomy + 0.05;
	if (key == GLUT_KEY_PAGE_DOWN)
		zoomy = zoomy - 0.05;

	glutPostRedisplay();
}
// use the mouse to contuct things 
void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
			{

				if(y > (WINDOW_HEIGHT/WINDOW_WIDTH)*x && y > -(WINDOW_HEIGHT/WINDOW_WIDTH)*x + WINDOW_HEIGHT)
					zDeltaSpin = zDeltaSpin + 0.5;
				else 
				{
					if (x>WINDOW_WIDTH/2)
						xDeltaSpin = xDeltaSpin + 0.5;
					if (x<WINDOW_WIDTH/2)
						yDeltaSpin = yDeltaSpin + 0.5;
				}
				glutIdleFunc(spinner);
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
			{
				if(y > (WINDOW_HEIGHT/WINDOW_WIDTH)*x && y > -(WINDOW_HEIGHT/WINDOW_WIDTH)*x + WINDOW_HEIGHT)
					zDeltaSpin = zDeltaSpin - 0.5;
				else 
				{
					if (x>WINDOW_WIDTH/2)
						xDeltaSpin = xDeltaSpin - 0.5;
					if (x<WINDOW_WIDTH/2)
						yDeltaSpin = yDeltaSpin - 0.5;
				}
				glutIdleFunc(spinner);
			}
			break;
		default:
			break;
	}
}
// turn the axis on and off 
void axisR(int msg)
{
	switch(msg) 
	{
		case 1:
			drawAxis = true;
			break;
		case 2:
			drawAxis = false;
			break;
	}
	glutPostRedisplay();
}
// turn the 'hello world' sign on and off 
void signR(int msg)
{
	switch(msg)
	{
		case 1:
			drawSign = true;
			break;
		case 2:
			drawSign = false;
			break;
	}
	glutPostRedisplay();
}
// fill in the polygon on not 
void fillR(int msg)
{
	switch(msg)
	{
		case 1:
			filled = true;
			break;
		case 2:
			filled = false;
			break;
	}
	glutPostRedisplay();
}
// change the view between perspective and orthogonal 
void viewR(int msg)
{
	switch(msg)
	{
        double customfovY,customaspect,customnear,customfar; 
		case 1:{
            // perspective viewpoint
          //  char perspective[40] = "Perspective";
			persp = 1;     
          //  drawString(10,60,GLUT_BITMAP_HELVETICA_18,perspective);  
			break;
                }
		case 2:
            {
            // ortographic viewpoint
            //char orthographic[40] = "Orthographic";
            //drawString(5000,5000,GLUT_BITMAP_HELVETICA_18,orthographic);
			persp = 2;
			break;
            }
		case 3:
            {
            // custom viewpoint
			persp = 3;
			cout << "Enter in your own type of view"<< endl;
            double fovY,aspect,near,far;
            cout << "Fovy: " << endl; 
            cin >> customfovY;
            cout << "Aspect Ratio: " << endl;
            cin >> customaspect; 
            cout << "Near: "<< endl;
            cin >> customnear;
            cout << "Far: "<<endl;
            cin >> customfar; 
            cout << "Thank you for outrageous shapes"<< endl;
			break;
			} 
	}
	glutPostRedisplay();
}
// exit the program or not 
void exitR(int msg)
{
	switch(msg)
	{
		case 1:
			exit(0);
			break;
	}
}
// reset the program or not 
void resetR(int msg)
{
	switch(msg)
	{
		case 1:
			filled = false;
			drawAxis = false;
			drawSign = false;
			zoomy = 0.0;
			yspin = 0.0; yDeltaSpin = 0.0;
			xspin = 0.0; xDeltaSpin = 0.0;
			zspin = 0.0; zDeltaSpin = 0.0;
			
			break;
		case 2:
			cout << "What you thought this was?\n\n";
	}
	glutPostRedisplay();
}
// just here 
void nope(int msg){};
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
  // add the ability the turn the axis on and off 
   int axis = glutCreateMenu(axisR);
   glutAddMenuEntry("I want to manually calculate my lines of intersect ", 1);
   glutAddMenuEntry("Look!! I floating in mid-air", 2);
// turn the sign on and off
   int sign = glutCreateMenu(signR);
   glutAddMenuEntry("Lets see that nice fine sign", 1);
   glutAddMenuEntry("I do want to remind of my trucking days with those road signs ", 2);
// fill the polygon on and off 
   int fill = glutCreateMenu(fillR);
   glutAddMenuEntry("Fill me up before you go go ", 1);
   glutAddMenuEntry("Dont fill me up ", 2);
// change the view between ortographic and perspective 
   int view = glutCreateMenu(viewR);
   glutAddMenuEntry("Perspective", 1);
   glutAddMenuEntry("Orthographic", 2);
   glutAddMenuEntry("Those Customs though", 3);
// exit the program or not 
   int exit = glutCreateMenu(exitR);
   glutAddMenuEntry("Kill it now ", 1);
   glutAddMenuEntry("No ready to leave yet", 2);
// reset the program or not 
   int reset = glutCreateMenu(resetR);
   glutAddMenuEntry("All the way to great beyond", 1);
   glutAddMenuEntry("Im cooling just chilling here",2);
// a mainmenu with everything else as submenus 
   int menu = glutCreateMenu(nope);
   glutAddSubMenu("Reset",reset);
   glutAddSubMenu("Axes", axis);
   glutAddSubMenu("Sign", sign);
   glutAddSubMenu("Fill", fill);
   glutAddSubMenu("View", view);
   glutAddSubMenu("Exit", exit);
// use the middle mouse button to access the menu 
   glutAttachMenu(GLUT_MIDDLE_BUTTON);

   glutMainLoop();
   return 0;
}

#endif
