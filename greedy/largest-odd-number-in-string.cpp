class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        long long temp = 0;
        for (int i = 0; i < num.size(); i++) {
            long long n = num[i] - '0';
            temp = (temp * 10) + n;
        }
        long long maxnum = INT_MIN;
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