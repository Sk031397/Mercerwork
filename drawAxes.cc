
#ifndef DRAW_AXES
#define DRAW_AXES
#include <string.h>
#include "opengl.h" 

void drawAxes(int length, bool drawAxis)
{   
    int i, len;
    char xaxis[] = "X"; 
    char yaxis[] = "Y";
    char zaxis[] = "Z";
    void *font = GLUT_STROKE_ROMAN;

/* This provides a coordinate axis about the origin. */
   if (drawAxis)
   {
   glPointSize(1.0);
   glBegin(GL_LINE_STRIP);
     glVertex3i(0,length,0);
     glVertex3i(0,-length,0);
   glEnd();
   glBegin(GL_LINE_STRIP);
     glVertex3i(length,0,0);
     glVertex3i(-length,0,0);
   glEnd();
   glBegin(GL_LINE_STRIP);
     glVertex3i(0,0,length);
     glVertex3i(0,0,-length);
   glEnd();
   
   // Z - Label
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(zaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, zaxis[i]);
    }
    glPopMatrix();

    // Y - Label
    glPushMatrix();
    glTranslatef(0.0, 4, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(yaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, yaxis[i]);
    }
    glPopMatrix();

    // X - Label 
    glPushMatrix();
    glTranslatef(4.0, 0.0, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(xaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, xaxis[i]);
    }
    glPopMatrix();
    }
}

#endif
