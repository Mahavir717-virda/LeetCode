class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long curr_gcd = 0;
            long long curr_lcm = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                
                if (prod > 1e9) break; 

                curr_gcd = gcd(curr_gcd, (long long)nums[j]);
                curr_lcm = lcm(curr_lcm, (long long)nums[j]);

                if (prod == curr_lcm * curr_gcd) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};