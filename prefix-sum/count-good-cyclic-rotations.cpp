class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        map<pair<long long, long long>, int> mp;

        long long leftsum = 0, rightsum = 0;
         for (int i = 0; i < n / 2; i++) {
                leftsum += (long long)(nums[i]);
                rightsum += (long long)(nums[(n / 2) + i]);
            }

        int left = 0, right = n / 2;
        while (left < (n / 2) and right < n)  {
            mp[{leftsum, rightsum}]++;
            mp[{rightsum, leftsum}]++;

            leftsum -= nums[left];
            rightsum += nums[left];
            left++; 

            rightsum -= nums[right];
            leftsum += nums[right];
            right++;
        }

        int cnt = 0;
        for (auto it : mp) {
            if(it.first.first > it.first.second)
            {
                cnt+=it.second;
            }
        }

        return cnt;
    }
};