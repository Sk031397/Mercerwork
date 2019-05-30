#ifndef RESHAPE
#define RESHAPE
#define PI 3.14159265
#include <math.h>
#include "opengl.h"
void reshape (int w, int h)
{
 
   float l, r, b, t, n, f,aspect,fovy;
   l = -1.5; r = 1.5;   // l=left, r=right
   b = -1.0; t = 1.0;   // b=bottom, t=top
   n =  2.0; f = 8.0;   // n=near, f=far  
   aspect = ( r - l) / (t-b); 
   fovy =  2 * atan((double)t/abs(n))*180.0/PI /*50.0*/; 
   // creating my own perspective projection matrix  
 /*  float myOwnPerspectiveMatrix[] = {
  2*fabs(n)/(r-l), 0.0f, (r+l)/(r-l), 0.0f,
  0.0f, 2*fabs(n)/(t-b), (t+b)/(t-b), 0.0f,
  0.0f, 0.0f, (fabs(n)+fabs(f))/(fabs(n)-fabs(f)), 2*fabs(n)*fabs(f)/(fabs(n)-fabs(f)),
  0.0f, 0.0f, -1.0f, 0.0f
 };*/ 
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
  //glFrustum ( l, r, b, t, n, f);
  #ifdef cflag
  float myOwnPerspectiveMatrix[] = {
  2*fabs(n)/(r-l), 0.0f, (r+l)/(r-l), 0.0f,
  0.0f, 2*fabs(n)/(t-b), (t+b)/(t-b), 0.0f,
  0.0f, 0.0f, (fabs(n)+fabs(f))/(fabs(n)-fabs(f)), 2*fabs(n)*fabs(f)/(fabs(n)-fabs(f)),
  0.0f, 0.0f, -1.0f, 0.0f
  };
   glMultTransposeMatrixf(myOwnPerspectiveMatrix);
 #else
   gluPerspective(fovy,aspect,n,f); 
#endif
   glMatrixMode (GL_MODELVIEW);
}
#endif
