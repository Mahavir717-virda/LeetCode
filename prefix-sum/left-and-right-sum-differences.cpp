class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size(), totalsum = 0;
        for (auto it : nums) {
            totalsum += it;
        }

        vector<int> ans;
        int leftsum = 0;

        for (int i = 0; i < n; i++) {
            totalsum -= nums[i]; //  This Willbe my Right Sum

            ans.push_back(abs(leftsum - totalsum));

            leftsum += nums[i]; //  This will be my Left Sum
        }
        return ans;
    }
};