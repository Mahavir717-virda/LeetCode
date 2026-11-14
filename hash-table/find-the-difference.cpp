class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1 = 0, n2 = 0;

        for (int i = 0; i < s.size(); i++) {
            n1 += s[i];
        }

        for (int i = 0; i < t.size(); i++) {
            n2 += t[i];
        }

        cout << n2 - n1;

        return n2 - n1;
    }
};