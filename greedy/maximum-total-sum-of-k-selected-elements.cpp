class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = 0;
        int n = nums.size(),cnt = 0;

        for(int i = 0; i < n; i++)
            {
                if(cnt == k)
                    break;
                if(mul > 0)
                {
                    sum += (1LL * nums[i] * mul);
                    cnt++;
                    mul--;
                }
                else
                {
                    sum += nums[i];
                    cnt++;
                }
            }
        return sum;
    }
};