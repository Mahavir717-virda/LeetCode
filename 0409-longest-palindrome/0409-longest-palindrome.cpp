class Solution {
public:
    int longestPalindrome(string s) {
        int max_len = 0;

        int n = s.size();
        int i = 0, j = n - 1;

        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        bool hasOdd = false;
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                max_len += it.second;
            } else {
                max_len += it.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            max_len += 1;
        }
        return max_len;
    }
};