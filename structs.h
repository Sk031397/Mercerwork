
#ifndef STRUCTS
#define STRUCTS
// holds the x,y,z coordinates 
typedef struct vertex {
        float x;
        float y;
        float z;
        float w;
} vertex;
// holds the different colors 
typedef struct colortype {
	float red;
	float green;
	float blue;
} colortype;
// creates a box out of the vertex box 
typedef struct box {
	vertex point[4];
	colortype color;	
} box;
// create a pentagon out of the vertex points 
typedef struct pentagon {
	vertex point[5];
	colortype color;
} pentagon;

#endif
