class Solution {
public:
    vector<vector<int>> ans;
    vector<int> result;
    void subsets(int j, vector<int>& nums, vector<bool>& isVisited) {
        ans.push_back(result);
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> isVisited(nums.size(), false);
        subsets(0, nums, isVisited);
        return ans;
    }
};