class Solution {
public:
    double solve(int p, int i, int j, vector<vector<double>>& memo) {
        if (i < 0 || j < 0 || i < j) { //   i < j invalid
            return 0.0;
        }

        if (i == 0 and j == 0) {
            return p;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        //   champagne will come from left and right glasses
        //   and the amount will be (upper glass amount - 1) because it will
        //   take 1 for it self and then half-half will be gone on both sides so
        //   divide by 2
        double left_up = (solve(p, i - 1, j - 1, memo) - 1) / 2;
        double right_up = (solve(p, i - 1, j, memo) - 1) / 2;

        //  for invalid indicices it will return 0 and calculation will return
        //  -0.5 we have to handle it so
        // if either of upper is negative make them 0
        if (left_up < 0.0) {
            left_up = 0.0;
        }

        if (right_up < 0.0) {
            right_up = 0.0;
        }

        return memo[i][j] = left_up + right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(query_row + 1,
                                    vector<double>(query_glass + 1, -1.0));
        return min(1.0, solve(poured, query_row, query_glass, memo));
    }
};