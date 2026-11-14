class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text2.length(), y = text1.length();
        // Vector handles memory on the heap and initializes everything to 0
        vector<vector<int>> L(x + 1, vector<int>(y + 1, 0));

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (text2[i - 1] == text1[j - 1]) {
                    L[i][j] = 1 + L[i - 1][j - 1];
                } else {
                    L[i][j] = max(L[i][j - 1], L[i - 1][j]);
                }
            }
        }
        
        return L[x][y];
    }
};
