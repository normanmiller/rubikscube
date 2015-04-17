#include<vector>
#include"Face.h"

using namespace std;

class neighborFace {
	public:
		int direction; // 0 - top, 1 - right, 2 - bottom - 3 - left
		Face* facePointer;

		vector<int> returnNeighborColors() {
			vector<int> neighborColors;
			int i;
			switch(direction) {
			case 0:
				for(i=0;i<3;i++) {
					neighborColors.push_back(facePointer->colors[0][i]);
				}
			break;
			case 1:
				for(i=0;i<3;i++) {
					neighborColors.push_back(facePointer->colors[i][2]);
				}
			break;
			case 2:
				for(i=0;i<3;i++) {
					neighborColors.push_back(facePointer->colors[2][i]);
				}
			break;
			case 3:
				for(i=0;i<3;i++) {
					neighborColors.push_back(facePointer->colors[i][0]);
				}
			break;
			}
			return neighborColors;
		}
};
