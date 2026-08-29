class Solution {
public:
    double calc(double x, int n, int cnt) {
        if (cnt > n) {
            return 1.0;
        }

        return x * calc(x, n, cnt+1);
    }
    double myPow(double x, int n) {
        long long N = n;

        if(N < 0)
        {
           N = -N;
           double ans = calc(x,N,1);
           ans = 1 / ans;
           return ans;
        }

        return calc(x,N,1);
    }
};