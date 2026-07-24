class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s1 = (nums.size() * (nums.size() + 1)) / 2;
        int s2=0;

        for(auto it : nums)
        {
            s2 += it;
        }

        return s1 - s2;
    }
};