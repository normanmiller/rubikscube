#include "3DCube.h"

void drawCubes()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    #pragma region Center Cubes

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

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_right + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_center_left + 3);

    glDrawArrays(GL_QUADS, 0, 24);

#pragma endregion

    #pragma region Corner Cubes

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

    #pragma endregion

    #pragma region Edge Cubes

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_FD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_LD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_BD + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RU + 3);

    glDrawArrays(GL_QUADS, 0, 24);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), cube_edge_RD + 3);

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

    #pragma endregion

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}