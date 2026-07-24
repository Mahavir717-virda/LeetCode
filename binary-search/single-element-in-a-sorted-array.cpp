class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size();

        int ans = nums[0];
        for(int i = 1; i < j; i++)
        {
            ans = ans ^ nums[i];
        }

        cout << ans;

        return ans;
    }
};