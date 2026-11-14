class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;

        int j = 0, n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];

            while(sum >= target)
            {
                len = min(len , i - j + 1);
                sum -= nums[j];
                j++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};