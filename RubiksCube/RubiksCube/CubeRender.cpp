#include "CubeRender.h"

class Permutation;

Tuple3d::Tuple3d()
{
}
Tuple3d::~Tuple3d()
{
}

Tuple3d::Tuple3d(int x, int y, int z){
    this->x = (double)x;
    this->y = (double)y;
    this->z = (double)z;
}

Tuple3d::Tuple3d(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Tuple3d::CopyTuple3d(Tuple3d p){
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

Cell::Cell()
{
}

Cell::Cell(Tuple3d loc, Tuple3d norm, int color)
{
    this->location = loc;
    this->normal = norm;
    this->color = color;
}

void Cell::CopyCell(Cell node){
    this->location.x = node.location.x;
    this->location.y = node.location.y;
    this->location.z = node.location.z;
    this->normal.x = node.normal.x;
    this->normal.y = node.normal.y;
    this->normal.z = node.normal.z;
    this->color = node.color;
}

int Cell::getColor(){
    return color;
}

void Cell::setLocation(Tuple3d p){
    this->location = p;
}

Tuple3d Cell::getLocation(){
    return this->location;
}

void Cell::setNormal(Tuple3d v){
    this->normal = v;
}

Tuple3d Cell::getNormal(){
    return this->normal;
}

static Tuple3d rotateZAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)round(p1.x * cos(radians) - p1.y * sin(radians));
    _tempTuple.y = (int)round(p1.x * sin(radians) + p1.y * cos(radians));
    _tempTuple.z = (int)p1.z;

    return _tempTuple;
}

static Tuple3d rotateXAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)p1.x;
    _tempTuple.y = (int)round(p1.y * cos(radians) - p1.z * sin(radians));
    _tempTuple.z = (int)round(p1.y * sin(radians) + p1.z * cos(radians));

    return _tempTuple;
}

static Tuple3d rotateYAxis(Tuple3d p1, double radians)
{
    Tuple3d _tempTuple;

    _tempTuple.x = (int)round(p1.z * sin(radians) + p1.x * cos(radians));
    _tempTuple.y = (int)p1.y;
    _tempTuple.z = (int)round(p1.z * cos(radians) - p1.x * sin(radians));

    return _tempTuple;
}

static Cell rotateNode(Cell n, int axis, double radians){
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
    return n;
}

void ApplyRotation(std::vector<Rotation> specifiedRotations)
{
    switch (specifiedRotations[specifiedRotations.size() - 1])
    {
    case Right:
        //Retrieve all faces that have an x at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == 1){
                cube[i] = rotateNode(cube[i], X_AXIS, -M_PI_2);
            }
        }
        break;
    case iRight:
        //Retrieve all faces that have an x at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == 1){
                cube[i] = rotateNode(cube[i], X_AXIS, M_PI_2);
            }
        }
        break;
    case Left:
        //Retrieve all faces that have an x at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == -1){
                cube[i] = rotateNode(cube[i], X_AXIS, -M_PI_2);
            }
        }
        break;
    case iLeft:
        //Retrieve all faces that have an x at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == -1){
                cube[i] = rotateNode(cube[i], X_AXIS, M_PI_2);
            }
        }
        break;
    case Front:
        //Retrieve all faces that have an z at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == 1){
                cube[i] = rotateNode(cube[i], Z_AXIS, -M_PI_2);
            }
        }
        break;
    case iFront:
        //Retrieve all faces that have an z at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == 1){
                cube[i] = rotateNode(cube[i], Z_AXIS, M_PI_2);
            }
        }
        break;
    case Back:
        //Retrieve all faces that have an z at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == -1){
                cube[i] = rotateNode(cube[i], Z_AXIS, -M_PI_2);
            }
        }
        break;
    case iBack:
        //Retrieve all faces that have an z at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == -1){
                cube[i] = rotateNode(cube[i], Z_AXIS, M_PI_2);
            }
        }
        break;
    case Up:
        //Retrieve all faces that have an y at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == 1){
                cube[i] = rotateNode(cube[i], Y_AXIS, -M_PI_2);
            }
        }
        break;
    case iUp:
        //Retrieve all faces that have an y at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == 1){
                cube[i] = rotateNode(cube[i], Y_AXIS, M_PI_2);
            }
        }
        break;
    case iDown:
        //Retrieve all faces that have an y at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == -1){
                cube[i] = rotateNode(cube[i], Y_AXIS, -M_PI_2);
            }
        }
        break;
    case Down:
        //Retrieve all faces that have an y at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == -1){
                cube[i] = rotateNode(cube[i], Y_AXIS, M_PI_2);
            }
        }
        break;
    case None:
        specifiedRotations.pop_back();
    default:
        break;
    }

    //Draw black cube inside for aesthetics
    DrawInnerCube();

    //Redraw cube according to updated movement
    for (int i = 0; i < 54; ++i)
    {
        convertToColor(cube[i].getColor());
        if (cube[i].getNormal().x == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().x == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        if (cube[i].getNormal().y == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().y == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        if (cube[i].getNormal().z == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().z == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glEnd();
            glFlush();
        }
    }
}

void ApplySolutionRotations(Rotation solutionRotation) {
    switch (solutionRotation)
    {
    case Right:
        //Retrieve all faces that have an x at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == 1){
                cube[i] = rotateNode(cube[i], X_AXIS, -M_PI_2);
            }
        }
        break;
    case iRight:
        //Retrieve all faces that have an x at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == 1){
                cube[i] = rotateNode(cube[i], X_AXIS, M_PI_2);
            }
        }
        break;
    case Left:
        //Retrieve all faces that have an x at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == -1){
                cube[i] = rotateNode(cube[i], X_AXIS, -M_PI_2);
            }
        }
        break;
    case iLeft:
        //Retrieve all faces that have an x at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().x == -1){
                cube[i] = rotateNode(cube[i], X_AXIS, M_PI_2);
            }
        }
        break;
    case Front:
        //Retrieve all faces that have an z at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == 1){
                cube[i] = rotateNode(cube[i], Z_AXIS, -M_PI_2);
            }
        }
        break;
    case iFront:
        //Retrieve all faces that have an z at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == 1){
                cube[i] = rotateNode(cube[i], Z_AXIS, M_PI_2);
            }
        }
        break;
    case Back:
        //Retrieve all faces that have an z at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == -1){
                cube[i] = rotateNode(cube[i], Z_AXIS, -M_PI_2);
            }
        }
        break;
    case iBack:
        //Retrieve all faces that have an z at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().z == -1){
                cube[i] = rotateNode(cube[i], Z_AXIS, M_PI_2);
            }
        }
        break;
    case Up:
        //Retrieve all faces that have an y at 1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == 1){
                cube[i] = rotateNode(cube[i], Y_AXIS, -M_PI_2);
            }
        }
        break;
    case iUp:
        //Retrieve all faces that have an y at 1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == 1){
                cube[i] = rotateNode(cube[i], Y_AXIS, M_PI_2);
            }
        }
        break;
    case iDown:
        //Retrieve all faces that have an y at -1
        //  And rotate 90* CW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == -1){
                cube[i] = rotateNode(cube[i], Y_AXIS, -M_PI_2);
            }
        }
        break;
    case Down:
        //Retrieve all faces that have an y at -1
        //  And rotate 90* CCW
        for (int i = 0; i < 54; ++i)
        {
            if (cube[i].getLocation().y == -1){
                cube[i] = rotateNode(cube[i], Y_AXIS, M_PI_2);
            }
        }
        break;
    case None:
    default:
        break;
    }

    //Draw black cube inside for aesthetics
    DrawInnerCube();

    //Redraw cube according to updated movement
    for (int i = 0; i < 54; ++i)
    {
        convertToColor(cube[i].getColor());
        if (cube[i].getNormal().x == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().x == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        if (cube[i].getNormal().y == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().y == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        if (cube[i].getNormal().z == 1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z + SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z + SPACER);
            glEnd();
            glFlush();
        }
        else if (cube[i].getNormal().z == -1)
        {
            glBegin(GL_QUADS);
            glNormal3d(cube[i].getNormal().x, cube[i].getNormal().y, cube[i].getNormal().z);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x - SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y - SPACER, cube[i].getLocation().z - SPACER);
            glVertex3d(cube[i].getLocation().x + SPACER, cube[i].getLocation().y + SPACER, cube[i].getLocation().z - SPACER);
            glEnd();
            glFlush();
        }
    }
}

void InitializeCube()
{
    for (int i = 0; i < 6; i++){
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

        switch (i)
        {
        case 1://bottom

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                *it = rotateNode(*it, X_AXIS, M_PI / 2);
            }
            break;

        case 2://back

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                *it = rotateNode(*it, X_AXIS, M_PI);
            }

            break;

        case 3://top

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                *it = rotateNode(*it, X_AXIS, -M_PI_2);
            }

            break;

        case 4://left

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                *it = rotateNode(*it, Y_AXIS, -M_PI_2);
            }

            break;

        case 5://right

            for (std::vector<Cell>::iterator it = cellVector.begin(); it < cellVector.end(); ++it)
            {
                *it = rotateNode(*it, Y_AXIS, M_PI_2);
            }

            break;
        }

        //Map face to cube structure
        for (int j = 0; j < 9; j++){
            cube[i * 9 + j] = cellVector[j];
        }
    }
}

void convertToColor(int val)
{
    switch (val)
    {
    case ORANGE:
        glColor3f(1, 0.5f, 0);
        break;
    case GREEN:
        glColor3f(0.1f, 0.66f, 0.1f);
        break;
    case RED:
        glColor3f(1, 0, 0);
        break;
    case BLUE:
        glColor3f(0.1f, 0.1f, 0.66f);
        break;
    case YELLOW:
        glColor3f(1, 1, 0);
        break;
    case WHITE:
        glColor3f(1, 1, 1);
        break;
    default:
        glColor3f(0, 0, 0);
        break;
    }
}

void DrawInnerCube()
{
    glColor3f(0, 0, 0);

    glBegin(GL_QUADS);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glVertex3f(-0.95f - SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, 0.95f + SPACER, -0.95 - SPACER);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glVertex3f(-0.95f - SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, 0.95 + SPACER);
    glVertex3f(0.95f + SPACER, -0.95f - SPACER, -0.95 - SPACER);
    glEnd();
    glFlush();
}