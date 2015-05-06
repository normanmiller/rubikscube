#ifndef CUBERENDER_H
#define CUBERENDER_H

#include <stdlib.h>
#include <glut.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <math.h>

#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923

/**
* Components of the graphics in our project inspired from G Cope's Java Open Source examples:
* http://www.algosome.com/articles/rubiks-cube-computer-simulation.html
* http://www.algosome.com/articles/rubiks-cube-computer-visualize.html
*/

class Tuple3d {
public:

    Tuple3d();
    ~Tuple3d();
    Tuple3d(int, int, int);
    Tuple3d(double, double, double);

    void CopyTuple3d(Tuple3d);

    double x;
    double y;
    double z;
};

class Cell
{
public:

    Cell();
    Cell(Tuple3d, Tuple3d, int);
    void CopyCell(Cell);

    int getColor();
    void setLocation(Tuple3d);
    Tuple3d getLocation();
    void setNormal(Tuple3d);
    Tuple3d getNormal();

private:
    int color;
    Tuple3d location;
    Tuple3d normal;
};

typedef enum Color
{
    ORANGE = 0,
    GREEN = 1,
    RED = 2,
    BLUE = 3,
    YELLOW = 4,
    WHITE = 5,
};

typedef enum Rotation
{
    None = 0,
    Right = 1,
    iRight = 2,
    Front = 3,
    iFront = 4,
    Left = 5,
    iLeft = 6,
    Back = 7,
    iBack = 8,
    Down = 9,
    iDown = 10,
    Up = 11,
    iUp = 12,
};

const static int X_AXIS = 1;
const static int Y_AXIS = 2;
const static int Z_AXIS = 3;
static int PAINT_BORDER = 10;
static int CUBE_SIZE = 20;
static float SPACER = 0.47f;

static Cell cube[52];

static Tuple3d rotateZAxis(Tuple3d, double);
static Tuple3d rotateXAxis(Tuple3d, double);
static Tuple3d rotateYAxis(Tuple3d, double);
static Cell rotateNode(Cell, int, double);

void ApplyRotation(std::vector<Rotation>);
void ApplySolutionRotations(Rotation);
void InitializeCube();
void convertToColor(int);
void DrawInnerCube();

#endif