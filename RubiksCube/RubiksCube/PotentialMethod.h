#ifndef POTENTIALMETHOD_H
#define POTENTIALMETHOD_H

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
* Simple 3 double value wrapper class that can represent data in three dimensions.
* @author G Cope
*
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

class Cell{
    /*
    * Colors
    */
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
    RED = 0,
    GREEN = 1,
    WHITE = 2,
    BLUE = 3,
    ORANGE = 4,
    YELLOW = 5,
};

const static int X_AXIS = 1;
const static int Y_AXIS = 2;
const static int Z_AXIS = 3;
static int PAINT_BORDER = 10;
static int CUBE_SIZE = 20;
static float SPACER = 0.45f;

static Tuple3d rotateZAxis(Tuple3d, double);
static Tuple3d rotateXAxis(Tuple3d, double);
static Tuple3d rotateYAxis(Tuple3d, double);
static void rotateNode(Cell, int, double);

void CreateCube();
std::vector<Cell> InitializeCube(int);
void convertToColor(int);

#endif