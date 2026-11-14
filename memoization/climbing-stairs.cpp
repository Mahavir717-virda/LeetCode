class Solution {
public:
    int memo[46];

    int down(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        if (memo[n] != -1) return memo[n];
        
        return memo[n] = down(n - 1) + down(n - 2);
    }

    int climbStairs(int n) {
        if (n <= 1) return n;
        
        memset(memo, -1, sizeof(memo));
        return down(n);
    }
};
