class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, maxLen = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            if ((mp.find(nums[j]) == mp.end()) or mp[nums[j]] < k) {
                mp[nums[j]]++;
                j++;
            } else {
                mp[nums[j]]++;
                j++;
                while (i < j and mp[nums[j - 1]] > k) {
                    mp[nums[i]]--;
                    i++;
                }
            }

            maxLen = max(maxLen, j - i);
            cout << maxLen << " ";
        }

        return maxLen;
    }
};