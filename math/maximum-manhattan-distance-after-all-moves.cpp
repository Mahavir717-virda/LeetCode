class Solution {
public:
    int maxDistance(string moves) {
        int sum = 0;
        int xi = 0, yi = 0;
        int xj = 0, yj = 0;

        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L') {
                xj -= 1;
            } else if (moves[i] == 'R') {
                xj += 1;
            } else if (moves[i] == 'U') {
                yj += 1;
            } else if(moves[i] == 'D') {
                yj -= 1;
            }
            else
            {
                sum++;
            }
        }

        return abs(xi - xj) + abs(yi - yj) + sum;
    }
};