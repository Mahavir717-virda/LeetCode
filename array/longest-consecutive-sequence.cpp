class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty())
            return 0;

        int longest = 1;
        unordered_set<int> s;
        for (auto it : nums)
            s.insert(it);

        for (auto it : s) {
            if (s.find(it - 1) == s.end()) {
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};