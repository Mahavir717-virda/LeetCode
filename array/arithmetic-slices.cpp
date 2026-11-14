class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int cnt = 0, n = nums.size(), prev_diff = nums[1] - nums[0];
        int result = 0;
        for(int i = 1; i < n - 1; i++)
        {
            int curr_diff = nums[i + 1] - nums[i];

            if(prev_diff == curr_diff)
                cnt++;
            else
            {
                prev_diff = curr_diff;
                cnt = 0;
            }

            result += cnt;
        }

        return result;
    }
};