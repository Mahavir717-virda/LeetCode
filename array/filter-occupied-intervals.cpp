class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        int n = occupiedIntervals.size();

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        for (int i = 0; i < n; i++) {
            if (ans.empty() || occupiedIntervals[i][0] > ans.back()[1] + 1) {
                ans.push_back(occupiedIntervals[i]);
            } else {
                ans.back()[1] = max(occupiedIntervals[i][1], ans.back()[1]);
            }
        }

        vector<vector<int>> res;

        for (auto& it : ans) {
            int l = it[0];
            int r = it[1];

            if (r < freeStart || l > freeEnd) {
                res.push_back({l, r});
                continue;
            }

            if (l < freeStart) {
                res.push_back({l, freeStart - 1});
            }
            if (r > freeEnd) {
                res.push_back({freeEnd + 1, r});
            }
        }
        return res;
    }
};