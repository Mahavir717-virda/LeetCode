class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void PrintSubsets(int idx, vector<int>& nums) {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            PrintSubsets(i + 1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        PrintSubsets(0, nums);
        return ans;
    }
};