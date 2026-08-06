class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true)
        {
            int n1 = n;
            int product = 1;
            while(n1 > 0)
            {
                product *= (n1 % 10);
                n1/=10;
            }

            if(product % t == 0)
            {
                return n;
            }
            n++;
        }
    }
};