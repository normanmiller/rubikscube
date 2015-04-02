
#include <GL/glut.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <math.h>

using namespace std;

float red = 0.0;
float green = 0.0;
float blue = 1.0;


GLfloat vertices[] = {
	0, 0, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1,
	0, 1, 1, 1, 1, 1,

	0, 0, 1, 1, 0, 0,
	0, 1, 1, 1, 0, 0,
	0, 1, 0, 1, 0, 0,
	0, 0, 0, 1, 0, 0,

	0, 0, 1, 0, 0, 0,
	1, 0, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,

	0, 1, 1, 0, 1, 0,
	1, 1, 1, 0, 1, 0,
	1, 1, 0, 0, 1, 0,
	0, 1, 0, 0, 1, 0,

	0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0,

	1, 1, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0,
	1, 0, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 0
};


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

	glEnable(GL_DEPTH_TEST);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), vertices);
	glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), vertices + 3);

	glDrawArrays(GL_QUADS, 0, 24);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glFlush();

	glutSwapBuffers();


}

void initialize()
{
	glMatrixMode(GL_PROJECTION);												// select projection matrix
	glViewport(0, 0, 640, 640);									// set the viewport											
	glLoadIdentity();															// reset projection matrix
	gluPerspective(45.0f, 1.0f, 0.1f, 10.0f);		// set up a perspective projection matrix
	glMatrixMode(GL_MODELVIEW);													// specify which matrix is the current matrix
	glShadeModel(GL_SMOOTH);

	glClearDepth(1.0f);														// specify the clear value for the depth buffer
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);						// specify implementation-specific hints
	glClearColor(0.5, 0.5, 0.5, 1.0);											// specify clear values for the color buffers			
	glLineWidth(5);
}


void key(unsigned char key, int x_cord, int y_cord) {
	//move up view vector
	if (key == 'c' || key == 'C') {

		verticalPos -= .01;

	}

	if (key == 'v' || key == 'V') {

		verticalPos += .01;

	}

	if (key == 'd' || key == 'D') {

	}


	if (key == 'Q' || key == 'q' || key == 27) {
		exit(0); //hard exit
	}

	if (key == 'R' || key == 'r') {
		//reset initial values
		verticalPos = 0;
		eyeRotation = 0;
		gazeRotation = 0;
		zoomFactor = 1.0;
	}
	//solid fill
	if (key == 's' || key == 'S') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//wireframe
	if (key == 'w' || key == 'W') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}


	if (key == 'x') {
		//do counterclockwise rotation about gaze vector
		gazeRotation += 0.0174532925; //+ 1 degree in radians

	}
	if (key == 'z') {
		//do counterclockwise rotation about gaze vector
		gazeRotation -= 0.0174532925;

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
	//check command line inputs
	if (argc != 2) {
		cout << "Usage viewer controlFile" << endl;
		exit(1);
	}
	//read control file
	//readControl(argv[1]);
	//loadObj("stanfordModels/F16.obj");
	//setMaxBounds();
	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(640, 640);					// set window size
	glutCreateWindow("Viewer");								// create Window
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
