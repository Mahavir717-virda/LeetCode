class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int lastseen = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(cnt == 0)
            {
                cnt = 1;
                lastseen = nums[i];
            }
            else if(nums[i] == lastseen)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        return lastseen;
    }
};