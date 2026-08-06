class Solution {
public:
    int smallestNumber(int n, int t) {
        int y = INT_MAX;
        vector<int> ans;
        while (n <= 100) {
            int n1 = n;
            while (n1 > 0) {
                int temp = n % 10;
                ans.push_back(temp);
                n1 /= 10;
            }
            if (ans.size() == 1) {
                if (ans[0] % t == 0) {
                    y = min(y, n);
                }
            } else if (ans.size() == 2) {
                int x = ans[0] * ans[1];
                if (x % t == 0) {
                    y = min(y, n);
                }
            } else {
                int x = ans[0] * ans[1] * ans[2];
                if (x % t == 0) {
                    y = min(y, n);
                }
            }
            n++;
        }

        return y;
    }
};