class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combsum;
    void comb(int idx, vector<int>& c, vector<int>& combsum, int target) {
        if (idx == c.size()) {
            if (target == 0) {
                ans.push_back(combsum);
            }
                return;
        }

        if (c[idx] <= target) {
            combsum.push_back(c[idx]);
            comb(idx, c, combsum, target - c[idx]);
            combsum.pop_back();
        }

        comb(idx + 1, c, combsum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        comb(0, candidates, combsum, target);
        return ans;
    }
};