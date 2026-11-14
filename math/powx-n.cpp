class Solution {
public:
    double CalcPow(double x, long long N) {
        if (N == 0)
            return 1.0;

        if (N % 2 == 0) {
            return CalcPow(x * x, N / 2);
        } else {
            return x * CalcPow(x, N - 1);
        }
    }
    double myPow(double x, int n) {
        double ans = 1.0;
        bool isNegative = false;
        long long N = n;
        if (N < 0) {
            isNegative = true;
            N = (long long)-N;
        }

        ans = CalcPow(x, N);

        if (isNegative)
            return 1 / ans;

        return ans;
    }
};