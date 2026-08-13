class Solution {
public:
    bool rotateString(string s, string goal) {
        int cnt = 0;
        while (cnt > s.size() * 2) {
            int i = 1, j = s.size();

            char c = s[0];
            while (i < s.size()) {
                s[i -1] = s[i];
                i++;
            }

            s[s.size() - 1] = c;

            if(s == goal)
            {
                return true;
            }
            cnt++;
        }
        return false;
    }
};