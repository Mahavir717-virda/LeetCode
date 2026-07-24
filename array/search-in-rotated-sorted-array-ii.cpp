class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        
        while(i <= j)
        {
            if(nums[i] == target)
                return true;
            else if(nums[j] == target)
                return true;
            else
                i++; j--;
        }

        return false;
    }
};