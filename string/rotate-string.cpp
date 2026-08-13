class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() == 1 && goal.size() == 1)
        {
            if(s != goal)
            {
                return false;
            }
        }
        while (true) {
            int i = 1, j = s.size();

            char c = s[0];
            while (i < s.size()) {
                s[i - 1] = s[i];
                i++;
            }

            s[s.size() - 1] = c;

            if(s == goal)
            {
                return true;
            }
        }
        return false;
    }
};