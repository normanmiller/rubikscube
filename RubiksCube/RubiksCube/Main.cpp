#include <stdlib.h>
#include <glut.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <math.h>

#include "3DCube.h"

using namespace std;

float red = 0.0;
float green = 0.0;
float blue = 1.0;

int _screenWidth = 800;
int _screenHeight = 600;

Rotation _cubeRotation = None;

/*camera vertical position */
GLdouble verticalPos = 0.0;
GLfloat focalPoint = 0.0;
/*starting gaze rotation angle*/
GLdouble gazeRotation = 0.0;
GLfloat eyeRotation = 0.0;
GLfloat aspect = 1.0f;
GLfloat zoomFactor = 1.0f;

static void reshape_CB(GLsizei width, GLsizei height)
{
	/* handle case for divide by 0 */
	if (height == 0)
		height = 1;

	/* compute aspect ratio of the new window */
	aspect = (GLfloat)width / (GLfloat)height;

	/* set the viewport */
	glViewport(0, 0, width, height);

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(15.0f*zoomFactor, aspect, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(sin(gazeRotation)*verticalPos + 10.0, cos(gazeRotation)*verticalPos + 3, 10.0,
		0.0, 0.0, 0.0,
		sin(gazeRotation), cos(gazeRotation), 0.0);

	glTranslatef(0.0f, 0.0f, 0.0f);

	glRotatef(eyeRotation, 0.0f, 1.0f, 0.0f);
    
    cubeInteraction(_cubeRotation);    //Function that renders the cubix

    _cubeRotation = None;

    glutSwapBuffers();
}

void initialize()
{
	glMatrixMode(GL_PROJECTION);												// select projection matrix
	glViewport(0, 0, _screenWidth, _screenHeight);									// set the viewport											
	glLoadIdentity();															// reset projection matrix
	gluPerspective(45.0f, 1.0f, 0.1f, 10.0f);		// set up a perspective projection matrix
	glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
	glShadeModel(GL_SMOOTH);

	glClearDepth(1.0f);														// specify the clear value for the depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);						// specify implementation-specific hints
	glClearColor(0.17, 0.24, 0.31, 1.0);											// specify clear values for the color buffers			
	glLineWidth(5);
}


void key(unsigned char key, int x_cord, int y_cord) {
	
    switch (key)
    {
    case 'b':
        _cubeRotation = iBack;
        break;
    case 'B':
        _cubeRotation = Back;
        break;
    case 'c':
    case 'C':
        verticalPos -= .1;
        break;
    case 'd':
        _cubeRotation = iDown;
        break;
    case 'D':
        _cubeRotation = Down;
        break;
    case 'f':
        _cubeRotation = iFront;
        break;
    case 'F':
        _cubeRotation = Front;
        break;
    case 'l':
        _cubeRotation = iLeft;
        break;
    case 'L':
        _cubeRotation = Left;
        break;
    case 'q':
    case 'Q':
    case 27:
        exit(0);
        break;
    case 'r':
        _cubeRotation = iRight;
        break;
    case 'R':
        _cubeRotation = Right;
        break;
    case 's':
    case 'S':
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    case 't':
    case 'T':
        verticalPos = 0;
        eyeRotation = 0;
        gazeRotation = 0;
        zoomFactor = 1.0;
        break;
    case 'u':
        _cubeRotation = iUp;
        break;
    case 'U':
        _cubeRotation = Up;
        break;
    case 'v':
    case 'V':
        verticalPos += .1;
        break;
    case 'w':
    case 'W':
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    case 'x':
    case 'X':
        //do counterclockwise rotation about gaze vector
        gazeRotation += 0.0174532925; //+ 1 degree in radians
        break;
    case 'z':
    case 'Z':
        //do counterclockwise rotation about gaze vector
        gazeRotation -= 0.0174532925;
        break;
    default:
        _cubeRotation = None;
        break;
    }

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT) {
		eyeRotation += 1;
	}

	if (key == GLUT_KEY_RIGHT) {
		eyeRotation -= 1;
	}

	if (key == GLUT_KEY_UP) {
		zoomFactor -= 0.1;
	}

	if (key == GLUT_KEY_DOWN) {
		zoomFactor += 0.1;
	}

	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	//read control file
	//readControl(argv[1]);
	//loadObj("stanfordModels/F16.obj");
	//setMaxBounds();
	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(_screenWidth, _screenHeight);					// set window size
	glutCreateWindow("Rubik's Cube");								// create Window
	/* handle window re-size event */
	glutReshapeFunc(reshape_CB);

	glutDisplayFunc(display);									// register Display Function
	//glutIdleFunc(display);									// register Idle Function
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKeys);								// register Keyboard Handler
	initialize();
	glutMainLoop();												// run GLUT mainloop
	return 0;
}
