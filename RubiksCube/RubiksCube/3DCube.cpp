#include "3DCube.h"

void drawCubes()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center + 3);

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

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_1);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_1 + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_2);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_2 + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}