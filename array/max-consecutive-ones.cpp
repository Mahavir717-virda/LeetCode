class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, n =  nums.size(),max1 = 0;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 1)
            {
                cnt++;
                max1 = max(cnt,max1);
            } 
            else
            {
                cnt = 0;
            }
        }

        return max1;
    }
};