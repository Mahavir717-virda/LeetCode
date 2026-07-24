class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                temp.push_back(nums[j]);
                mp[nums[j]]++;

                if (mp.find(target) != mp.end()) {
                    if (mp[target] > (temp.size() / 2)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};