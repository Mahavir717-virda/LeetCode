class Solution {
public:
    bool IsSafe(vector<string>& board, int row, int col, int n) {
        // Col Wise
        for (int i = 0; i < row; i++) { if (board[i][col] == 'Q') return false; }
        // Left Upper
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { if (board[i][j] == 'Q') return false; }
        // Right Upper
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) { if (board[i][j] == 'Q') return false; } 
        return true;
    }
    void solve(int row, vector<string>& board, int n,
               vector<vector<string>>& solutions) {
        // Base Case
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (IsSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n, solutions);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solve(0, board, n, solutions);
        return solutions;
    }
};  