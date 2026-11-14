class Solution {
public:
    int strStr(string haystack, string needle) {
        int cnt = -1;
        int n = haystack.length(), m = needle.length();

        for (int i = 0; i < n; i++) {
            string s = haystack.substr(i, m);
            int j = 0;
            bool found = false;
            while (j < m) {
                if (needle[j] == s[j]) {
                    j++;
                    found = true;
                } else {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                cnt = i;
                break;
            }
        }
        return cnt;
    }
};