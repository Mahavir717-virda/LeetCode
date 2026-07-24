class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int count1 = 0;
        int count0 = 0;
        for (char c : s) {
            if (c == '1') count1++;
            else count0++;
        }

        int res = count1;

        res = min(res, count0);

        if (count1 > 0) res = min(res, count1 - 1);
        else res = min(res, 1);

        
        if (n >= 2) {
            int flips = 0;
            if (s[0] == '0') flips++;
            if (s[n - 1] == '0') flips++;
            int mid1s = count1 - (s[0] == '1' ? 1 : 0) - (s[n - 1] == '1' ? 1 : 0);
            flips += mid1s;
            res = min(res, flips);
        }

        return res;
    }
};