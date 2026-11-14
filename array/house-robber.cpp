class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        if(nums.size() == 1)
            return nums[0];

        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {

            //   Here As we can see that we have only 2 choice either we will rob the houce or we will skip it.
            //   So for that we need a dp state which will remember the best result so far of the robbery 

            //  if we want to rob the house then we will take the house by 1 diff
            int rob = dp[i - 2] + nums[i];

            //   if we want to skip the house then the last best result will be the best 
            int skip = dp[i - 1];

            dp[i] = max(rob, skip);
        }

        return dp[nums.size() - 1];
    }
};