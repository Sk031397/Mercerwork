#ifndef RESHAPE
#define RESHAPE
#include <cmath>
#include "opengl.h"
#include "prototypes.h"
#define PI 3.1415926535897932384626433832795
void reshape (int w, int h)
{
   double persp; 
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
 
   glFrustum (left0,right0,bottom,top,near,far);
  
   glMatrixMode (GL_MODELVIEW);
}
#endif
