class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        bool found = false;
        int minSum = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                int size = j - i + 1;
                if(size >= l and size <= r and sum > 0)
                {
                    found = true;
                    minSum = min(minSum, sum);
                }
            }
        }

        if(!found)
            return -1;

        return minSum;
    }
};