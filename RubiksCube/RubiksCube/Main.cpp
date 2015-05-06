#include <stdlib.h>
#include <glut.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <math.h>
#include <list>

#include "State.h"
#include "CubeRender.h"

using namespace std;

int _screenWidth = 800;
int _screenHeight = 600;

int rotationRepeatCounter = 0;
vector<Rotation>::iterator solutionIter;

vector<Rotation> userInputRotations;
vector<Rotation> solutionRotations;

bool toggleSolutionRender = false;

/*camera vertical position */
GLdouble verticalPos = 0.0;
GLfloat focalPoint = 0.0;
/*starting gaze rotation angle*/
GLdouble gazeRotation = 0.0;
GLfloat eyeRotation = 0.0;
GLfloat aspect = 1.0f;
GLfloat zoomFactor = 1.0f;

// this struct is to allow the algorithms to keep track of the series of moves that lead them to the given state from the starting position.
//This allows the program to return a sequence of moves that will solve a given cube
struct permutationState{
    vector<Permutation> permutation;
    State state;
};

//generate a vector containing the 12 permutations of the cube.  All permutations apply from every state
vector<Permutation> allPossible() {
    vector<Permutation> p;
    for (int face = 0; face < 6; face++){
        for (int direction = 0; direction < 2; direction++)
        {
            Permutation p1;
            p1.direction = direction;
            p1.face = face;
            p.push_back(p1);
        }
    }
    return p;
}

permutationState solveBFS(State currentState) {
    list<permutationState> stateVector;
    vector<Permutation> p = allPossible();
    permutationState currentPermutationState;
    vector<Permutation>::iterator pIter;
    currentPermutationState.state = currentState;

    do {
        for (pIter = p.begin(); pIter != p.end(); pIter++) {
            permutationState pState = currentPermutationState;
            pState.state.applyPermutation((*pIter));
            pState.permutation.push_back((*pIter));
            if (pState.state.checkSolved()) return pState;
            stateVector.push_back(pState);
        }

        currentPermutationState = stateVector.front();
        stateVector.pop_front();
    } while (stateVector.size() > 0);
}

bool solveDFS(permutationState &currentPermutationState, int Depth) {
    if (Depth >= 27) return false;
    vector<Permutation> p = allPossible();
    vector<Permutation>::iterator pIter;

    //generating the child states
    for (pIter = p.begin(); pIter != p.end(); pIter++) {
        permutationState pState = currentPermutationState;
        pState.state.applyPermutation((*pIter));
        pState.permutation.push_back((*pIter));
        if (pState.state.checkSolved()) {
            currentPermutationState = pState;
            return true;
        }
        if (solveDFS(pState, Depth + 1)) {
            currentPermutationState = pState;
            return true;
        }
    }
    return false;
}

//depth limited depth first search
bool DLS(permutationState &currentPermutationState, int Depth) {
    if (Depth == 0) return false;
    vector<Permutation> p = allPossible();
    vector<Permutation>::iterator pIter;

    //generating the child states
    for (pIter = p.begin(); pIter != p.end(); pIter++) {
        permutationState pState = currentPermutationState;
        pState.state.applyPermutation((*pIter));
        pState.permutation.push_back((*pIter));
        if (pState.state.checkSolved()) {
            currentPermutationState = pState;
            return true;
        }
        if (DLS(pState, Depth - 1)) {
            currentPermutationState = pState;
            return true;
        }
    }
    return false;
}

permutationState solveIDDFS(permutationState startState) {
    int i;
    permutationState goalState;
    for (i = 1; !DLS(startState, i); i++) {}
    return startState;
}

/*
int checkLayers(State currentState) {
vector<Face>::iterator faceIter;
for (faceIter = currentState.faces.begin(); faceIter != currentState.faces.end(); faceIter++) {
//check colors
int color = (*faceIter).colors[0][0];

for (int j = 0; j<3; j++) {
for (int i = 0; i<3; i++) {
if ((*faceIter).colors[i][j] != color) return false;
}
}
vector<vector<int>> neighborColors;

for (int i = 0; i < 4; i++) {
vector<int> currentFaceData =(*faceIter).neighbors[i].returnNeighborColors(currentState);
neighborColors.push_back(currentFaceData);
}

for (int i = 0; i < 4; i++) {
color = neighborColors[i][0];
for (int j = 0; j < 3; j++) {
if (color != neighborColors[i][j]) return false;
}
}

//check neighbors
}
return true;
}

permutationState firstLayer(State currentState) {
vector<Permutation> p = allPossible();

list<permutationState> stateVector;
permutationState currentPermutationState;
vector<Permutation>::iterator pIter;
currentPermutationState.state = currentState;

do {
for (pIter = p.begin(); pIter != p.end(); pIter++) {
permutationState pState = currentPermutationState;
pState.state.applyPermutation((*pIter));
pState.permutation.push_back((*pIter));
if (checkLayers(pState.state)) return pState;
stateVector.push_back(pState);
}

currentPermutationState = stateVector.front();
stateVector.pop_front();
} while (stateVector.size() > 0);
}

permutationState sideSolve(permutationState CPS) {
}

void layerSolve(State currentState){
//apply BFS and check each face for a correct solution at each node until it finds a solved face
permutationState layersSolved = firstLayer(currentState);

//apply side swaps in a BFS appraoch until it finds the second layer is built
permutationState sidesSolved = sideSolve(layersSolved);
//build a cross on the top layer by applying the cross building moves in BFS approach

//swap corners
}*/

Permutation ConvertRotationToPermutation(Rotation rotation) {
    Permutation permutation;
    switch (rotation) {
    case Right:
        permutation.face = 0;
        permutation.direction = 1;
        break;
    case iRight:
        permutation.face = 0;
        permutation.direction = 0;
        break;
    case Left:
        permutation.face = 5;
        permutation.direction = 1;
        break;
    case iLeft:
        permutation.face = 5;
        permutation.direction = 0;
        break;
    case Front:
        permutation.face = 3;
        permutation.direction = 1;
        break;
    case iFront:
        permutation.face = 3;
        permutation.direction = 0;
        break;
    case Back:
        permutation.face = 1;
        permutation.direction = 1;
        break;
    case iBack:
        permutation.face = 1;
        permutation.direction = 0;
        break;
    case Up:
        permutation.face = 2;
        permutation.direction = 1;
        break;
    case iUp:
        permutation.face = 2;
        permutation.direction = 0;
        break;
    case Down:
        permutation.face = 4;
        permutation.direction = 1;
        break;
    case iDown:
        permutation.face = 4;
        permutation.direction = 0;
        break;
    case None:
    default:
        break;
    }

    return permutation;
}

vector<Rotation> ConvertPermutationVectorToRotationVector(vector<Permutation> permutation) {
    vector<Rotation> rotationVector;

    for (vector<Permutation>::iterator iter = permutation.begin(); iter < permutation.end(); ++iter) {
        switch ((*iter).face)
        {
        case 0:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iRight);
            }
            else {
                rotationVector.push_back(Right);
            }
            break;
        case 1:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iBack);
            }
            else {
                rotationVector.push_back(Back);
            }
            break;
        case 2:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iUp);
            }
            else {
                rotationVector.push_back(Up);
            }
            break;
        case 3:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iFront);
            }
            else {
                rotationVector.push_back(Front);
            }
            break;
        case 4:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iDown);
            }
            else {
                rotationVector.push_back(Down);
            }
            break;
        case 5:
            if ((*iter).direction == 0) {
                rotationVector.push_back(iLeft);
            }
            else {
                rotationVector.push_back(Left);
            }
            break;
        }
    }

    return rotationVector;
}

void applyStateRotations() {
    permutationState mainPState;
    vector<Rotation>::iterator rIter;
    vector<Permutation> permutationVector;
    vector<Permutation>::iterator pIter;
    mainPState.state.setMainState();
    for (rIter = userInputRotations.begin(); rIter != userInputRotations.end(); rIter++) {
        if ((*rIter) == None) continue;
        Permutation newPerm = ConvertRotationToPermutation((*rIter));
        permutationVector.push_back(newPerm);
    }
    for (pIter = permutationVector.begin(); pIter != permutationVector.end(); pIter++) {
        mainPState.state.applyPermutation((*pIter));
    }
    mainPState.state.printCube();
    mainPState = solveIDDFS(mainPState);
    mainPState.state.printCube();

    solutionRotations = ConvertPermutationVectorToRotationVector(mainPState.permutation);
    solutionIter = solutionRotations.begin();
    toggleSolutionRender = true;
}

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

    if (!toggleSolutionRender) {
        ApplyRotation(userInputRotations);
    }
    else {
        ApplySolutionRotations(*solutionIter);
        ++solutionIter;
    }

    //Redundancy checker - clears last 4 entries if they are all the same move
    if (rotationRepeatCounter == 3)
    {
        userInputRotations.pop_back();
        userInputRotations.pop_back();
        userInputRotations.pop_back();
        userInputRotations.pop_back();
        rotationRepeatCounter = 0;
    }

    userInputRotations.push_back(None);

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

    InitializeCube();
    userInputRotations.push_back(None);
}

void key(unsigned char key, int x_cord, int y_cord) {
    switch (key)
    {
    case 'b':
        if (userInputRotations[userInputRotations.size() - 1] == iBack)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iBack);
        break;
    case 'B':
        if (userInputRotations[userInputRotations.size() - 1] == Back)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Back);
        break;
    case 'c':
    case 'C':
        verticalPos -= .2;
        break;
    case 'd':
        if (userInputRotations[userInputRotations.size() - 1] == iDown)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iDown);
        break;
    case 'D':
        if (userInputRotations[userInputRotations.size() - 1] == Down)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Down);
        break;
    case 'f':
        if (userInputRotations[userInputRotations.size() - 1] == iFront)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iFront);
        break;
    case 'F':
        if (userInputRotations[userInputRotations.size() - 1] == Front)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Front);
        break;
    case 'l':
        if (userInputRotations[userInputRotations.size() - 1] == iLeft)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iLeft);
        break;
    case 'L':
        if (userInputRotations[userInputRotations.size() - 1] == Left)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Left);
        break;
    case 'q':
    case 'Q':
    case 27:
        exit(0);
        break;
    case 'r':
        if (userInputRotations[userInputRotations.size() - 1] == iRight)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iRight);
        break;
    case 'R':
        if (userInputRotations[userInputRotations.size() - 1] == Right)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Right);
        break;
    case 's':
    case 'S':
        applyStateRotations();
    case 't':
    case 'T':
        verticalPos = 0;
        eyeRotation = 0;
        gazeRotation = 0;
        zoomFactor = 1.0;
        break;
    case 'u':
        if (userInputRotations[userInputRotations.size() - 1] == iUp)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(iUp);
        break;
    case 'U':
        if (userInputRotations[userInputRotations.size() - 1] == Up)
        {
            rotationRepeatCounter++;
        }
        else rotationRepeatCounter = 0;
        userInputRotations.push_back(Up);
        break;
    case 'v':
    case 'V':
        verticalPos += .2;
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