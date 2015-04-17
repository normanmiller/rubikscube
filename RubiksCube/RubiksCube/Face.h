#include<vector>

class Face {
	public:
		
		int colors[3][3];
		std::vector<neighborFace> neighbors;
};
