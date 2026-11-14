class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long maxsum = 0.0;
        vector<long long> ans;
        for(auto it : nums)
        {
            ans.push_back(1LL * it * it);
        }

        ranges::sort(ans);

        for(int i = 0; i < ans.size(); i++)
        {
            if(i < ans.size() / 2)
            {
                maxsum -= ans[i];
            }
            else
            {
                maxsum += ans[i];
            }
        }

        return maxsum;
    }
};