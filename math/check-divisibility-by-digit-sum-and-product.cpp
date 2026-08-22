class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1, sum = 0;
        int m = n;
        while(m > 0)
        {
            int temp = m % 10;
            pro *= temp;
            sum += temp;
            m /= 10;
        }

        if(n % (pro + sum) == 0)
            return true;

        return false;
    }
};