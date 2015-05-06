#include<vector>
#include<iostream>
#include<random>
#include<ctime>
#include"Face.h"
#include"neighborFace.h"

using namespace std;

class Permutation {
public:
    int face;
    int direction;
};

class State {
public:
    vector<Face> faces;

    void setMainState() {
        faces.clear();
        int color = 0;
        for (int k = 0; k < 6; k++) {
            int i, j;
            Face currentFace;
            for (j = 0; j < 3; j++) {
                for (i = 0; i < 3; i++) {
                    currentFace.colors[i][j] = color;
                }
            }
            color++;
            this->faces.push_back(currentFace);
        }

        //face 0(white) set neighbors
        neighborFace n0;

        n0.direction = 0;
        n0.face = 1; //red faces its top to white
        faces[0].neighbors.push_back(n0);

        n0.direction = 0;
        n0.face = 2; //blue faces its top to white
        faces[0].neighbors.push_back(n0);

        n0.direction = 0;
        n0.face = 3; //orange faces its top to white
        faces[0].neighbors.push_back(n0);

        n0.direction = 0;
        n0.face = 4; //green faces its top to white
        faces[0].neighbors.push_back(n0);

        //face 1(red) set neightbors
        n0.direction = 3;
        n0.face = 0; //white faces its left to red
        faces[1].neighbors.push_back(n0);

        n0.direction = 1;
        n0.face = 4; //green faces its right to red
        faces[1].neighbors.push_back(n0);

        n0.direction = 3;
        n0.face = 5;//yellow faces its left to red
        faces[1].neighbors.push_back(n0);

        n0.direction = 3;
        n0.face = 2; //blue faces its left to red
        faces[1].neighbors.push_back(n0);

        //face 2(blue) set neightbors
        n0.direction = 2;
        n0.face = 0; //white faces its bottom to blue
        faces[2].neighbors.push_back(n0);

        n0.direction = 1;
        n0.face = 1; //red faces its right to blue
        faces[2].neighbors.push_back(n0);

        n0.direction = 0;
        n0.face = 5; //yellow faces its top to blue
        faces[2].neighbors.push_back(n0);

        n0.direction = 3;
        n0.face = 3; //orange faces its left to blue
        faces[2].neighbors.push_back(n0);

        //face 3(orange) set neightbors
        n0.direction = 1;
        n0.face = 0; //white faces its right to orange
        faces[3].neighbors.push_back(n0);

        n0.direction = 1;
        n0.face = 2; //blue faces its right to ornage
        faces[3].neighbors.push_back(n0);

        n0.direction = 1;
        n0.face = 5; //yellow faces its right to orange
        faces[3].neighbors.push_back(n0);

        n0.direction = 3;
        n0.face = 4; //green faces its left to orange
        faces[3].neighbors.push_back(n0);

        //face 4(Green) set neightbors
        n0.direction = 0;
        n0.face = 0; //white faces its top to green
        faces[4].neighbors.push_back(n0);

        n0.direction = 1;
        n0.face = 3; //orange faces its right to green
        faces[4].neighbors.push_back(n0);

        n0.direction = 2;
        n0.face = 5; //yellow faces its bottom to green
        faces[4].neighbors.push_back(n0);

        n0.direction = 3;
        n0.face = 1; //red faces its left to green
        faces[4].neighbors.push_back(n0);

        //face 5(yellow) set neightbors

        n0.direction = 2;
        n0.face = 4; //green faces its bottom to yellow
        faces[5].neighbors.push_back(n0);

        n0.direction = 2;
        n0.face = 3; //orange faces its bottom to yellow
        faces[5].neighbors.push_back(n0);

        n0.direction = 2;
        n0.face = 2; //blue faces its bottom to yellow
        faces[5].neighbors.push_back(n0);

        n0.direction = 2;
        n0.face = 1; //red faces its bottom to yellow
        faces[5].neighbors.push_back(n0);
    }

    bool checkSolved() {
        vector<Face>::iterator faceIter;
        for (faceIter = this->faces.begin(); faceIter != this->faces.end(); faceIter++) {
            int i, j;
            int color = (*faceIter).colors[0][0];
            for (j = 0; j < 3; j++) {
                for (i = 0; i < 3; i++) {
                    if ((*faceIter).colors[i][j] != color) return false;
                }
            }
        }
        return true;
    }

    void applyPermutation(Permutation currentPermutation) {
        Face currentFace = faces[currentPermutation.face];
        vector<vector<int>> faceData;

        //retrieve data from neighboring faces
        for (int i = 0; i < 4; i++) {
            vector<int> currentFaceData = currentFace.neighbors[i].returnNeighborColors(*this);
            faceData.push_back(currentFaceData);
        }
        //clockwise turn
        if (currentPermutation.direction == 1) {
            currentFace.neighbors[2].swap(*this, currentFace.neighbors[3].direction, faceData[3]);
            currentFace.neighbors[1].swap(*this, currentFace.neighbors[2].direction, faceData[2]);
            currentFace.neighbors[0].swap(*this, currentFace.neighbors[1].direction, faceData[1]);
            currentFace.neighbors[3].swap(*this, currentFace.neighbors[0].direction, faceData[0]);

            /*int temp = faces[currentPermutation.face].neighbors[3].direction;
            faces[currentPermutation.face].neighbors[3].direction = faces[currentPermutation.face].neighbors[2].direction;
            faces[currentPermutation.face].neighbors[2].direction = faces[currentPermutation.face].neighbors[2].direction;
            faces[currentPermutation.face].neighbors[1].direction = faces[currentPermutation.face].neighbors[0].direction;
            faces[currentPermutation.face].neighbors[0].direction = temp;*/

            //transpose
            for (int i = 0; i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    int temp = currentFace.colors[i][j];
                    currentFace.colors[i][j] = currentFace.colors[j][i];
                    currentFace.colors[j][i] = temp;
                }
            }
            //reverse columns
            for (int i = 0; i < 3; ++i) {
                int temp = currentFace.colors[i][2];
                currentFace.colors[i][2] = currentFace.colors[i][0];
                currentFace.colors[i][0] = temp;
            }

            faces[currentPermutation.face] = currentFace;
        }
        //counter clockwise turn
        else {
            currentFace.neighbors[0].swap(*this, currentFace.neighbors[3].direction, faceData[3]);
            currentFace.neighbors[1].swap(*this, currentFace.neighbors[0].direction, faceData[0]);
            currentFace.neighbors[2].swap(*this, currentFace.neighbors[1].direction, faceData[1]);
            currentFace.neighbors[3].swap(*this, currentFace.neighbors[2].direction, faceData[2]);

            /*int temp = faces[currentPermutation.face].neighbors[0].direction;
            faces[currentPermutation.face].neighbors[0].direction = faces[currentPermutation.face].neighbors[1].direction;
            faces[currentPermutation.face].neighbors[1].direction = faces[currentPermutation.face].neighbors[2].direction;
            faces[currentPermutation.face].neighbors[2].direction = faces[currentPermutation.face].neighbors[3].direction;
            faces[currentPermutation.face].neighbors[3].direction = temp;*/

            //transpose
            for (int i = 0; i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    int temp = currentFace.colors[i][j];
                    currentFace.colors[i][j] = currentFace.colors[j][i];
                    currentFace.colors[j][i] = temp;
                }
            }
            //reverse rows

            for (int i = 0; i < 3; ++i) {
                int temp = currentFace.colors[2][i];
                currentFace.colors[2][i] = currentFace.colors[0][i];
                currentFace.colors[0][i] = temp;
            }
            faces[currentPermutation.face] = currentFace;
        }
    }

    void printCube() {
        cout << "   " << faces[0].colors[0][0] << faces[0].colors[0][1] << faces[0].colors[0][2] << endl;
        cout << "   " << faces[0].colors[1][0] << faces[0].colors[1][1] << faces[0].colors[1][2] << endl;
        cout << "   " << faces[0].colors[2][0] << faces[0].colors[2][1] << faces[0].colors[2][2] << endl;

        cout << faces[1].colors[0][0] << faces[1].colors[0][1] << faces[1].colors[0][2] <<
            faces[2].colors[0][0] << faces[2].colors[0][1] << faces[2].colors[0][2] <<
            faces[3].colors[0][0] << faces[3].colors[0][1] << faces[3].colors[0][2] <<
            faces[4].colors[0][0] << faces[4].colors[0][1] << faces[4].colors[0][2] << endl;

        cout << faces[1].colors[1][0] << faces[1].colors[1][1] << faces[1].colors[1][2] <<
            faces[2].colors[1][0] << faces[2].colors[1][1] << faces[2].colors[1][2] <<
            faces[3].colors[1][0] << faces[3].colors[1][1] << faces[3].colors[1][2] <<
            faces[4].colors[1][0] << faces[4].colors[1][1] << faces[4].colors[1][2] << endl;

        cout << faces[1].colors[2][0] << faces[1].colors[2][1] << faces[1].colors[2][2] <<
            faces[2].colors[2][0] << faces[2].colors[2][1] << faces[2].colors[2][2] <<
            faces[3].colors[2][0] << faces[3].colors[2][1] << faces[3].colors[2][2] <<
            faces[4].colors[2][0] << faces[4].colors[2][1] << faces[4].colors[2][2] << endl;

        cout << "   " << faces[5].colors[0][0] << faces[5].colors[0][1] << faces[5].colors[0][2] << endl;
        cout << "   " << faces[5].colors[1][0] << faces[5].colors[1][1] << faces[5].colors[1][2] << endl;
        cout << "   " << faces[5].colors[2][0] << faces[5].colors[2][1] << faces[5].colors[2][2] << endl;

        cout << endl
            ;
    }

    void scrambleCube() {
        default_random_engine rand;
        rand.seed(time(0));
        uniform_int_distribution<int> numberPermutations(1, 50);
        uniform_int_distribution<int> face(0, 5);
        uniform_int_distribution<int> direction(0, 1);
        vector<Permutation> permutations;

        int noPerm = numberPermutations(rand);
        noPerm = 5;
        int randFace;
        int randDirection;
        while (noPerm > 0) {
            randFace = face(rand);
            randDirection = direction(rand);
            Permutation newPerm;
            newPerm.face = randFace;
            newPerm.direction = randDirection;
            permutations.push_back(newPerm);
            noPerm--;
        }

        vector<Permutation>::iterator permIter;

        for (permIter = permutations.begin(); permIter != permutations.end(); permIter++) {
            printCube();
            applyPermutation((*permIter));
        }
    }
};