class Solution {
public:
    int residuePrefixes(string s) {
        int cnt = 0;
        unordered_set<char> str;

        for (int i = 0; i < s.length(); i++) {
            str.insert(s[i]);
            int len = i + 1;
            if (str.size() == (len % 3)) {
                cnt++;
            }
        }

        return cnt;
    }
};