class Solution {
public:
    long long maximumValue(int n, int s, int m) {
      if (n == 1) return s;          // no moves possible, answer is just s
        
        long long k = n / 2;           // number of "up" moves reaching the last peak
        return (long long)s + (k - 1) * (long long)(m - 1) + m;
    }
};