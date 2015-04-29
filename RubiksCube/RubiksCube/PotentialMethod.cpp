#include "PotentialMethod.h"

Tuple3d::Tuple3d()
{
}
Tuple3d::~Tuple3d()
{
}

/**
* Constructs a new tuple based upon int values.
* @param x
* @param y
* @param z
*/

Tuple3d::Tuple3d(int x, int y, int z){
    this->x = (double)x;
    this->y = (double)y;
    this->z = (double)z;
}

/**
* Constructs a new Tuple3d.
* @param x
* @param y
* @param z
*/

Tuple3d::Tuple3d(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
* Constructs a new Tuple3d object based upon the parameter. object.
* @param p
*/

void Tuple3d::CopyTuple3d(Tuple3d p){
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

/**
* Class used to represent a colored cell on a Rubik's Cube.
* @author G Cope
*
*/

Cell::Cell()
{
}

/**
* Constructs a new cell with location, a surface normal norm, and color.
* @param loc
* @param norm
* @param color one of RED, GREEN, ...ORANGE, YELLOW.
*/

Cell::Cell(Tuple3d loc, Tuple3d norm, int color)
{
    this->location = loc;
    this->normal = norm;
    this->color = color;
}

/**
* Deep copies the parameter node.
* @param node
*/

void Cell::CopyCell(Cell node){
    this->location.x = node.location.x;
    this->location.y = node.location.y;
    this->location.z = node.location.z;
    this->normal.x = node.normal.x;
    this->normal.y = node.normal.y;
    this->normal.z = node.normal.z;
    this->color = node.color;
}

/**
* Retrieves the color value.
* @return
*/

int Cell::getColor(){
    return color;
}

/**
* Sets the location
* @param p
*/

void Cell::setLocation(Tuple3d p){
    this->location = p;
}

/**
* Retrieves the location.
* @return
*/

Tuple3d Cell::getLocation(){
    return this->location;
}

/**
* Sets the normal
* @param v
*/

void Cell::setNormal(Tuple3d v){
    this->normal = v;
}

/**
* Retrieves the normal.
* @return
*/

Tuple3d Cell::getNormal(){
    return this->normal;
}

/**
* Rotates around the Z axis by radians
* @param p1
* @param radians
* @return
*/

static Tuple3d rotateZAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)round(p1.x * cos(radians) - p1.y * sin(radians));
    _tempTuple.y = (int)round(p1.x * sin(radians) + p1.y * cos(radians));
    _tempTuple.z = (int)p1.z;

    return _tempTuple;
}

/**
* Rotates around the X axis by radians
* @param p1
* @param radians
* @return
*/

static Tuple3d rotateXAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)p1.x;
    _tempTuple.y = (int)round(p1.y * cos(radians) - p1.z * sin(radians));
    _tempTuple.z = (int)round(p1.y * sin(radians) + p1.z * cos(radians));

    return _tempTuple;
}

/**

* Rotates the Tuple3d around the Y axis by radians.

* @param p1

* @param radians

* @return

*/

static Tuple3d rotateYAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)round(p1.z * sin(radians) + p1.x * cos(radians));
    _tempTuple.y = (int)p1.y;
    _tempTuple.z = (int)round(p1.z * cos(radians) - p1.x * sin(radians));

    return _tempTuple;
}

static void rotateNode(Cell n, int axis, double radians){
    switch (axis){
    case X_AXIS:
        n.setLocation(rotateXAxis(n.getLocation(), radians));
        n.setNormal(rotateXAxis(n.getNormal(), radians));
        break;
    case Y_AXIS:
        n.setLocation(rotateYAxis(n.getLocation(), radians));
        n.setNormal(rotateYAxis(n.getNormal(), radians));
        break;
    case Z_AXIS:
        n.setLocation(rotateZAxis(n.getLocation(), radians));
        n.setNormal(rotateZAxis(n.getNormal(), radians));
        break;
    }
}

void CreateCube()
{
    Cell cube[54];

    for (int i = 0; i < 6; i++){
        std::vector<Cell> cellVector;

        cellVector = InitializeCube(i);

        switch (i){
        case 1://bottom

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                rotateNode(*it, X_AXIS, M_PI / 2);
            }

            break;

        case 2://back

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                rotateNode(*it, X_AXIS, M_PI);
            }

            break;

        case 3://top

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                rotateNode(*it, X_AXIS, -M_PI_2);
            }

            break;

        case 4://left

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                rotateNode(*it, Y_AXIS, -M_PI_2);
            }

            break;

        case 5://right

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                rotateNode(*it, Y_AXIS, M_PI_2);
            }

            break;
        }

        for (int j = 0; j < 9; j++){
            cube[i * 9 + j] = cellVector[j];
        }
    }

    //get all candidates
    std::vector<Cell> cells;

    for (int i = 0; i < 54; ++i)
    {
        if (cube[i].getLocation().x == -1){
            cells.push_back(cube[i]);
        }
    }

    for (std::vector<Cell>::iterator it = cells.begin(); it < cells.end(); ++it)
    {
        rotateNode(*it, X_AXIS, M_PI_2);
    }

    for (std::vector<Cell>::iterator it = cells.begin(); it < cells.end(); ++it)
    {
        convertToColor((*it).getColor());
        glBegin(GL_QUADS);
        glNormal3d((*it).getNormal().x, (*it).getNormal().y, (*it).getNormal().z);
        glVertex3d((*it).getLocation().x - SPACER, (*it).getLocation().y + SPACER, (*it).getLocation().z + SPACER);
        glVertex3d((*it).getLocation().x - SPACER, (*it).getLocation().y - SPACER, (*it).getLocation().z + SPACER);
        glVertex3d((*it).getLocation().x + SPACER, (*it).getLocation().y - SPACER, (*it).getLocation().z + SPACER);
        glVertex3d((*it).getLocation().x + SPACER, (*it).getLocation().y + SPACER, (*it).getLocation().z + SPACER);
        glEnd();
        glFlush();
    }
}

std::vector<Cell> InitializeCube(int i)
{
    std::vector<Cell> cellVector;

    //initialize as front face
    for (int j = -1; j <= 1; j++){
        for (int k = -1; k <= 1; k++){
            Tuple3d* _tempTuple1 = new Tuple3d(j, k, 1);
            Tuple3d* _tempTuple2 = new Tuple3d(0, 0, 1);
            Cell* _tempCell = new Cell(*_tempTuple1, *_tempTuple2, i);
            cellVector.push_back(*_tempCell);
        }
    }

    return cellVector;
}
/**
* Converts the parameter to a color.
* @param val The int constant of a Rubik's Cube cell color
* @return A Color object.
* @throws IllegalArgumentException if val does not represent a color
*/

void convertToColor(int val)
{
    switch (val){
    case WHITE:
        glColor3f(1, 1, 1);
        break;
    case GREEN:
        glColor3f(0.1f, 0.66f, 0.1f);
        break;
    case ORANGE:
        glColor3f(1, 0.5f, 0);
        break;
    case BLUE:
        glColor3f(0.1f, 0.1f, 0.66f);
        break;
    case RED:
        glColor3f(1, 0, 0);
        break;
    case YELLOW:
        glColor3f(1, 1, 0);
        break;
    default:
        glColor3f(0, 0, 0);
        break;
    }
}