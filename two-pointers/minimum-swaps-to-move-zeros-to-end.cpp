class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == 0)
                cnt++;

        for(int i = 0;i<n-cnt;i++)
            if(nums[i] == 0)  ans++;
        return ans;
    }
};