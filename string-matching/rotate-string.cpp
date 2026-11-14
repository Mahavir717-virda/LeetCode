class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string new_s = s + s;

        return new_s.contains(goal);
    }
};