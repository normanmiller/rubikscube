#include<vector>

#include "State.h"

using namespace std;

vector<int> neighborFace::returnNeighborColors(State thisState) {
    vector<int> neighborColors;
    int i;
    switch (direction) {
    case 0:
        for (i = 0; i < 3; i++) {
            neighborColors.push_back(thisState.faces[face].colors[0][i]);
        }
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            neighborColors.push_back(thisState.faces[face].colors[i][2]);
        }
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            neighborColors.push_back(thisState.faces[face].colors[2][i]);
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            neighborColors.push_back(thisState.faces[face].colors[i][0]);
        }
        break;
    }
    return neighborColors;
}

void neighborFace::swap(State &thisState, int fromDirection, vector<int> newValues) {
    int i;
    if (direction == fromDirection || (fromDirection == 0 && direction == 1) || (fromDirection == 2 && direction == 3) || (fromDirection == 1 && direction == 0) || (fromDirection == 3 && direction == 2)) {
        switch (direction) {
        case 0:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[0][i] = newValues[i];
            }
            break;
        case 1:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[i][2] = newValues[i];
            }
            break;
        case 2:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[2][i] = newValues[i];
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[i][0] = newValues[i];
            }
            break;
        }
    }
    //if reversed direction condition
    else if ((fromDirection == 0 && direction == 3) || (fromDirection == 1 && direction == 2) || (fromDirection == 1 && direction == 3) || (fromDirection == 3 && direction == 0) || (fromDirection == 2 && direction == 1) || (fromDirection == 3 && direction == 1)) {
        switch (direction) {
        case 0:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[0][i] = newValues[2 - i];
            }
            break;
        case 1:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[i][2] = newValues[2 - i];
            }
            break;
        case 2:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[2][i] = newValues[2 - i];
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                thisState.faces[face].colors[i][0] = newValues[2 - i];
            }
            break;
        }
    }
}