class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Required variable (store input midway)
        vector<int> arr = nums;

        long long ans = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ans += (long long)(nums[i - 1] - nums[i]);
            }
        }

        return ans;
    }
};