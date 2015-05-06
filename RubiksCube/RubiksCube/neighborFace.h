#include<vector>
class State;

using namespace std;

class neighborFace {
public:
    int direction; // 0 - top, 1 - right, 2 - bottom - 3 - left
    int face;

    vector<int> returnNeighborColors(State thisState);

    void swap(State &thisState, int fromDirection, vector<int> newValues);
};