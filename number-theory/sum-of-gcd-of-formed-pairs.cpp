class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixgcd(nums.size());
        long long ans = 0;
        
        auto mxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
             mxi = max(mxi,nums[i]);
            
            prefixgcd[i] = gcd(mxi,nums[i]);
        }
        
        vector<int> fn_ans;
        
        sort(prefixgcd.begin(), prefixgcd.end());
        
        int x = 0, y = prefixgcd.size() - 1;
        int i = 0;
        
        while(x < y) {
            int mn = prefixgcd[x];
            int mx = prefixgcd[y];

            fn_ans.push_back(gcd(mn, mx));
            x++;
            y--;
            i++;
        }
        
        for (int i = 0; i < fn_ans.size(); i++) {
            ans += fn_ans[i];
        }
        
        return ans;
    }
};