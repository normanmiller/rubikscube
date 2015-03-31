#include <stdlib.h>
#include <stdio.h>
#include "glut.h"

#include "RenderCube.h"

void displayCallBack() {
	glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

	//Transform(s)
    glRotatef(45.0f, 1, 1, 0);
    glTranslatef(0.5f, 0.5f, -1.33f);

	drawCube();

    glPopMatrix();

    glutSwapBuffers();
}

void drawCube() {
    glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), vertices);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), vertices + 3);

	glDrawArrays(GL_QUADS, 0, 24);

	glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	int win = glutCreateWindow("Rubik's Cube");

	glViewport(0, 0, 800, 600);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -3, 3, -1, 1);

	glutDisplayFunc(displayCallBack);

	glutMainLoop();
	return 0;
}