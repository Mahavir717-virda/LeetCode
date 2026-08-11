class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> s;
        for(auto it : nums)
            s.insert(it);

        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                sum += nums[i];
            } else break;
        }
        int missing = sum;
        
        for(int i = missing; ; i++)
        {
            if(s.find(i) == s.end())
            {
                return i;
            }
        }
    }
};