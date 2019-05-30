#ifndef DRAWBOX
#define DRAWBOX

#include "opengl.h"
#include "structs.h"

void drawBox( struct box *face )
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glTranslatef(0.0,2.0,0.0);

    for(j=0;j<6;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_POLYGON);
        for (i=0;i<4;i++)
        {
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
        }
        glEnd();
    }

    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCone(1.0,3.0,50,50);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-2.0,0.0);

    for(j=0;j<6;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_POLYGON);
        for (i=0;i<4;i++)
        {
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
        }
        glEnd();
    }

    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,1.0);
    glutSolidSphere(1.0,50,50);
    
    glPopMatrix();

}

#endif
