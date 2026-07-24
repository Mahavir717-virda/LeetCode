class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        int ans = INT_MAX;

        while(i <= j)
        {
            if(nums[i] < ans)
                ans = nums[i];
                
            if(nums[j] < ans)
                ans = nums[j];
            
            i++, j--;
        }

        return ans;
    }
};