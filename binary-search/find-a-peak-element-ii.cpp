class Solution {
public:
    int elementRow(vector<vector<int>>& mat, int col) {
        int maxval = -1;
        int idx = -1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][col] > maxval) {
                maxval = mat[i][col];
                idx = i;
            }
        }

        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = elementRow(mat, mid);

            int left = (mid - 1 > 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < (high - 1)) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};