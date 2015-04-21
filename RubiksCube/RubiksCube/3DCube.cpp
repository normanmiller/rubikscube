#include "3DCube.h"

void cubeInteraction(Rotation cubeRotation)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /*glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();*/

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    switch (cubeRotation)
    {
        case Right:
            rightAngle += 90.0f;
            glRotatef(rightAngle, 1, 0, 0);
            drawRight();
            glRotatef(-rightAngle, 1, 0, 0);
            drawCoreZ();
            drawLeft();
            break;
        case iRight:
            rightAngle -= 90.0f;
            glRotatef(rightAngle, 1, 0, 0);
            drawRight();
            glRotatef(-rightAngle, 1, 0, 0);
            drawCoreZ();
            drawLeft();
            break;
        case Left:
            leftAngle -= 90.0f;
            glRotatef(leftAngle, 1, 0, 0);
            drawLeft();
            glRotatef(-leftAngle, 1, 0, 0);
            drawCoreZ();
            drawRight();
            break;
        case iLeft:
            leftAngle += 90.0f;
            glRotatef(leftAngle, 1, 0, 0);
            drawLeft();
            glRotatef(-leftAngle, 1, 0, 0);
            drawCoreZ();
            drawRight();
            break;
        case Front:
            frontAngle += 90.0f;
            glRotatef(frontAngle, 0, 0, 1);
            drawFront();
            glRotatef(-frontAngle, 0, 0, 1);
            drawCoreY();
            drawBack();
            break;
        case iFront:
            frontAngle -= 90.0f;
            glRotatef(frontAngle, 0, 0, 1);
            drawFront();
            glRotatef(-frontAngle, 0, 0, 1);
            drawCoreY();
            drawBack();
            break;
        case Back:
            backAngle += 90.0f;
            glRotatef(backAngle, 0, 0, 1);
            drawBack();
            glRotatef(-backAngle, 0, 0, 1);
            drawCoreY();
            drawFront();
            break;
        case iBack:
            backAngle -= 90.0f;
            glRotatef(backAngle, 0, 0, 1);
            drawBack();
            glRotatef(-backAngle, 0, 0, 1);
            drawCoreY();
            drawFront();
            break;
        case Up:
            upAngle += 90.0f;
            glRotatef(upAngle, 0, 1, 0);
            drawUp();
            glRotatef(-upAngle, 0, 1, 0);
            drawCoreX();
            drawDown();
            break;
        case iUp:
            upAngle -= 90.0f;
            glRotatef(upAngle, 0, 1, 0);
            drawUp();
            glRotatef(-upAngle, 0, 1, 0);
            drawCoreX();
            drawDown();
            break;
        case Down:
            downAngle += 90.0f;
            glRotatef(downAngle, 0, 1, 0);
            drawDown();
            glRotatef(-downAngle, 0, 1, 0);
            drawCoreX();
            drawUp();
            break;
        case iDown:
            downAngle -= 90.0f;
            glRotatef(downAngle, 0, 1, 0);
            drawDown();
            glRotatef(-downAngle, 0, 1, 0);
            drawCoreX();
            drawUp();
            break;
        case None:
        default:
            //TODO: Preserve current cube state
            break;
    }
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void drawFront()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawLeft()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawRight()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawBack()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawUp()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_top_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawDown()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_corner_bottom_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawCoreX()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FL + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FR + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LB + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RB + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawCoreY()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void drawCoreZ()
{
    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_core + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_front + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_back + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_up + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_down + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD + 3);

    glDrawArrays(GL_QUADS, 0, 24);
}

void rightTurnUpdate()
{
    //TODO: Rename cubes according to rotations
}

void iRightTurnUpdate()
{

}

void leftTurnUpdate()
{

}

void iLeftTurnUpdate()
{

}

void frontTurnUpdate()
{

}

void iFrontTurnUpdate()
{

}

void backTurnUpdate()
{

}

void iBackTurnUpdate()
{

}

void upTurnUpdate()
{

}

void iUpTurnUpdate()
{

}

void downTurnUpdate()
{

}

void iDownTurnUpdate()
{

}