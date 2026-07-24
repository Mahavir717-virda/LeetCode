class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0, j = s.length() - 1;
        bool found = false;
        int idx = 0;

        while (i <= j) {
            if (s[i] == s[j]) {
                idx = min(i, j);
                found = true;
                return idx;
            }
            i++;
            j--;
        }

        if (!found)
            return -1;

        return idx;
    }
};