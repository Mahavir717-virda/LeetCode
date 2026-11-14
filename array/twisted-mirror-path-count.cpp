class Solution {
public:
    int MOD = 1e9 + 7;
    int LEFT = 0;
    int UP = 1;
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>>& t) {

        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 and j == n - 1)
            return 1;

         // 3. MEMOIZATION CHECK (The missing critical piece)
        if (t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }

        if (grid[i][j] == 1) {
            if (cameFrom == 0) {
                return t[i][j][cameFrom] = solve(grid, i + 1, j, UP, t); // cameFrom left ,  direct towards down
            } else {
                return t[i][j][cameFrom] = solve(grid, i, j + 1, LEFT, t); //   cameFrom UP , direct towards right
            }
        }

        int totalPathCounts = 0;
        totalPathCounts =
            (totalPathCounts + solve(grid, i, j + 1, LEFT, t)) % MOD;
        totalPathCounts =
            (totalPathCounts + solve(grid, i + 1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = totalPathCounts;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //   We have to memoize this because of the very frequent cells visiting
        vector<vector<array<int, 2>>> t(m + 1, vector<array<int, 2 >> (n, {-1, -1}));
        return solve(grid, 0, 0, LEFT, t);
    }
};