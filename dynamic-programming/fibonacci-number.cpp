class Solution {
public:

    int fibo(int n, vector<int> &memo)
    {
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;

        if(memo[n - 1] != -1)
            return memo[n - 1];

        return memo[n - 1] = fibo(n - 1, memo) + fibo(n - 2, memo);
    }
    int fib(int n) {
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;
            
      vector<int> memo(n , -1);
      memo[0] = 0;
      memo[1] = 1;

      return fibo(n, memo);
    }
};