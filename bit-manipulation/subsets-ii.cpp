class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> Finalans;
    vector<int> result;

    void subsets(int j, vector<int>& nums, vector<bool>& isVisited) {
        ans.insert(result);
        for (int i = j; i < nums.size(); i++) {
            if (!isVisited[i]) {
                result.push_back(nums[i]);
                isVisited[i] = true;
                subsets(i + 1, nums, isVisited);
                result.pop_back();
                isVisited[i] = false;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> isVisited(nums.size(), false);
        ranges::sort(nums);
        subsets(0, nums, isVisited);

        for (auto it : ans) {
            Finalans.push_back(it);
        }

        return Finalans;
    }
};