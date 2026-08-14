class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0, j = 0;
        int maxlen = 0;
        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;

            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};