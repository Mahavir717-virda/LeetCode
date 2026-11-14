class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        long long ans = 0;
        bool isNagative = false;

        if (x < 0) {
            temp = -temp;
            isNagative = true;
        }

        while (temp > 0) {
            int rem = temp % 10;
            ans = (ans * 10) + rem;
            temp /= 10;
        }

        if (isNagative) {
            ans = -ans;
        }

       if (ans < -2147483648 || ans > 2147483647) {
            return 0;
        }

        return (int)ans;
    }
};