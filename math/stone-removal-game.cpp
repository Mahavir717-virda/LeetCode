class Solution {
public:
    bool canCurrentPlayerWin(int stonesLeft, int stonesToTake) {
        if (stonesLeft < stonesToTake) {
            return false;
        }
        
        return !canCurrentPlayerWin(stonesLeft - stonesToTake, stonesToTake - 1);
    }

    bool canAliceWin(int n) {
        return canCurrentPlayerWin(n, 10);
    }
};
