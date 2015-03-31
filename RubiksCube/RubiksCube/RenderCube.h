#include <stdlib.h>
#include <stdio.h>
#include "glut.h"

void displayCallBack(void);
void drawCube(void);
int main(int argc, char *argv[]);

//struct vertex {
//	float x,y,z;
//    float r,g,b;
//};

GLfloat vertices[] = {
    0, 0, 1,    1, 1, 1,
    1, 0, 1,    1, 1, 1,
    1, 1, 1,    1, 1, 1,
    0, 1, 1,    1, 1, 1,

    0, 0, 1,    1, 0, 0,
    0, 1, 1,    1, 0, 0,
    0, 1, 0,   1, 0, 0,
    0, 0, 0,   1, 0, 0,

    0, 0, 1,    0, 0, 0,
    1, 0, 1,    0, 0, 0,
    1, 0, 0,   0, 0, 0,
    0, 0, 0,   0, 0, 0,

    0, 1, 1,    0, 1, 0,
    1, 1, 1,    0, 1, 0,
    1, 1, 0,   0, 1, 0,
    0, 1, 0,   0, 1, 0,

    0, 1, 0,   0, 0, 0,
    0, 0, 0,   0, 0, 0,
    1, 0, 0,   0, 0, 0,
    1, 1, 0,   0, 0, 0,

    1, 1, 0,   0, 0, 0,
    1, 1, 1,    0, 0, 0,
    1, 0, 1,    0, 0, 0,
    1, 0, 0,   0, 0, 0
};