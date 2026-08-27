class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int temp = 0;
        for (int i = 0; i < num.size(); i++) {
            int n = num[i] - '0';
            temp = (temp * 10) + n;
        }
        int maxnum = INT_MIN;
        while (temp > 0) {
            if (temp % 2 != 0) {
                maxnum = max(maxnum, temp);
            }
            temp /= 10;
        }
        if (maxnum == INT_MIN)
            return "";

        return to_string(maxnum);
    }
};