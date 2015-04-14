#include<vector>
#include"Face.h"
#include"neighborFace.h"

using namespace std;

enum Color { white, red, blue, orange, green, yellow};




class State {
	public:
		vector<Face*> faces;

		void setMainState() {
			faces.clear();
			for(int k = 0; k < 6; k++) {
			int i, j;
			int color = 0;
			Face* currentFace = new Face;
				for (j = 0; j<3; j++) {
					for (i = 0; i<3; i++) {
						currentFace->colors[i][j] = color;
					}
				}
			this->faces.push_back(currentFace);
			}

			//face 0(white) set neighbors
			neighborFace n0;
			n0.direction=0;
			n0.facePointer=faces[1]; //red faces its top to white
			faces[0]->neighbors.push_back(n0);	
			
			n0.direction=0;
			n0.facePointer=faces[2]; //blue faces its top to white
			faces[0]->neighbors.push_back(n0);	

			n0.direction=0;
			n0.facePointer=faces[3]; //orange faces its top to white
			faces[0]->neighbors.push_back(n0);

			n0.direction=0;
			n0.facePointer=faces[4]; //green faces its top to white
			faces[0]->neighbors.push_back(n0);

			//face 1(red) set neightbors
			n0.direction=0;
			n0.facePointer=faces[0]; //white faces its top to red
			faces[1]->neighbors.push_back(n0);	
			
			n0.direction=3;
			n0.facePointer=faces[2]; //blue faces its left to red
			faces[1]->neighbors.push_back(n0);	

			n0.direction=1;
			n0.facePointer=faces[4]; //green faces its right to red
			faces[1]->neighbors.push_back(n0);

			n0.direction=0;
			n0.facePointer=faces[5]; //yellow faces it top to red
			faces[1]->neighbors.push_back(n0);

			//face 2(blue) set neightbors
			n0.direction=3;
			n0.facePointer=faces[0]; //white faces its left to blue
			faces[2]->neighbors.push_back(n0);	
			
			n0.direction=1;
			n0.facePointer=faces[1]; //red faces its right to blue
			faces[2]->neighbors.push_back(n0);	

			n0.direction=3;
			n0.facePointer=faces[3]; //orange faces its left to blue
			faces[2]->neighbors.push_back(n0);

			n0.direction=1;
			n0.facePointer=faces[5]; //yellow faces it left to blue
			faces[2]->neighbors.push_back(n0);

			//face 3(orange) set neightbors
			n0.direction=2;
			n0.facePointer=faces[0]; //white faces its bottom to orange
			faces[3]->neighbors.push_back(n0);	
			
			n0.direction=1;
			n0.facePointer=faces[2]; //blue faces its right to ornage
			faces[3]->neighbors.push_back(n0);	

			n0.direction=3;
			n0.facePointer=faces[4]; //green faces its left to orange
			faces[3]->neighbors.push_back(n0);

			n0.direction=1;
			n0.facePointer=faces[5]; //yellow faces its bottom to blue
			faces[3]->neighbors.push_back(n0);

			//face 4(Green) set neightbors
			n0.direction=1;
			n0.facePointer=faces[0]; //white faces its right to green
			faces[4]->neighbors.push_back(n0);	
			
			n0.direction=3;
			n0.facePointer=faces[1]; //red faces its left to green
			faces[4]->neighbors.push_back(n0);	

			n0.direction=1;
			n0.facePointer=faces[3]; //orange faces its right to green
			faces[4]->neighbors.push_back(n0);

			n0.direction=3;
			n0.facePointer=faces[5]; //yellow faces its left to green
			faces[4]->neighbors.push_back(n0);

			//face 5(yellow) set neightbors
			n0.direction=2;
			n0.facePointer=faces[1]; //red faces its bottom to yellow
			faces[5]->neighbors.push_back(n0);	
			
			n0.direction=2;
			n0.facePointer=faces[2]; //blue faces its bottom to yellow
			faces[5]->neighbors.push_back(n0);	

			n0.direction=2;
			n0.facePointer=faces[3]; //orange faces its bottom to yellow
			faces[5]->neighbors.push_back(n0);

			n0.direction=2;
			n0.facePointer=faces[4]; //green faces its bottom to yellow
			faces[5]->neighbors.push_back(n0);
		}

		bool checkSolved() {
			vector<Face*>::iterator faceIter;
			for(faceIter = this->faces.begin(); faceIter != this->faces.end(); faceIter++) {
				int i, j;
				int color = (*faceIter)->colors[0][0];
				for (j = 0; j<3; j++) {
					for (i = 0; i<3; i++) {
						if ((*faceIter)->colors[i][j] != color) return false;
					}
				}
			}
			return true;
		}
}