
#ifndef DISPLAY
#define DISPLAY

using namespace std;

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include <cmath>
#include <iostream>

double left0=-1.0;
double right0=1.0;
double bottom=-1.0;
double top=1.0;
double near=1.0;
double far=50.0;
double aspect = 0.0; 
double fovY = 0.0;
double customfovY,customaspect,customnear,customfar;


void p2Ortho( double fov, double aspecty, double zNear, double zFar )
{
    near = zNear;
    far = zFar;

    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    fH = tan( fov / 360 * pi ) * zNear;
    fW = fH * aspecty;

    right0 = fW;
    left0 = -fW;
    top = fH;
    bottom = -fH;

    glOrtho( left0-9, right0+9, bottom-9, top+9, near, far );
}
void o2Persp(double lefty, double righty, double bottomy, double topy, double neary, double fary)
{
    const GLdouble pi = 3.1415926535897932384626433832795;

    aspect = right0/top;
    fovY = atan(top/near)/pi*360;

    gluPerspective(fovY,aspect,neary,fary);
}

void changeView(int persp)
{
    if(persp == 1)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        o2Persp(left0,right0,bottom,top,near,far);      
        glMatrixMode(GL_MODELVIEW);    
    }
    else if(persp == 2)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        p2Ortho(fovY,aspect,near,far); 
        glMatrixMode(GL_MODELVIEW);
    }
    else if(persp == 3)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
        gluPerspective(customfovY,customaspect,customnear,customfar);     
        glMatrixMode(GL_MODELVIEW);    
    }

}
void display(void)
{

    struct pentagon faces[7];

    float *M;
    int i, j;

    // define the points of the polygon
    defineBox(&faces[0]);

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    /* ONLY MODIFY CODE BELOW */

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();             /* clear the matrix */

    // Let's manually move the camera back
    glTranslatef(0.0, 0.0, 0.0);


    // Now explicitly place the camera
    gluLookAt (5.7+zoomy, 5.7+zoomy, 5.7+zoomy, -10.0, -10.0, -10.0, 0.0, 0.0, 1.0);


    /* DO NOT MODIFY ANYTHING ELSE */

    /* Draw a coordinate axis */

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // draw the axes needed at this specific area 
    drawAxes(5, drawAxis);
    glPushMatrix();
    glTranslatef(1.0,1.0,0.0);
    glRotatef(zspin,0.0,0.0,1.0);
    glRotatef(xspin,1.0,0.0,0.0);
    glRotatef(yspin,0.0,1.0,0.0);
    glTranslatef(-1.0,-3.0,0.0);
    // draw the pentagon with the specific specifications 
    drawBox(&faces[0],filled);
    glPushMatrix();
    glScalef(0.0025,0.0025,0.0025);
    glRotatef(180.0,0.0,1.0,0.0);
    glTranslatef(-290.0,1200.0,-200.0);
    glRotatef(270.0,1.0,0.0,0.0);
    drawTheSign(drawSign);
    glPopMatrix();
    // if the view is ortographic
    glPushMatrix();
    glScalef(0.005,0.005,0.0005);
    glRotatef(90.0,0.0,0.0,1.0);
    glTranslatef(-290,2200.0,1000);
    glColor3f(1.0,1.0,1.0);
    OnScreenText(persp);
    changeView(persp);
    glPopMatrix();
    // if the view is perspective
    glPushMatrix();
    glScalef(0.005,0.005,0.0005);
    glRotatef(90.0,0.0,0.0,1.0);
    glTranslatef(-290,2200.0,1000);
    changeView(persp);
    glColor3f(1.0,1.0,1.0); 
    OnScreenText(persp);
    glPopMatrix();
    //OnScreenText(persp);
    // if the view is customized
    glPushMatrix();
    glPushMatrix();
    glScalef(0.005,0.005,0.0005);
    glRotatef(90.0,0.0,0.0,1.0);
    glTranslatef(-290,2200.0,1000);
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}

#endif
