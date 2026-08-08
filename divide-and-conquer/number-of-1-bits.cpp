class Solution {
public:
    int hammingWeight(int n) {
        int cnt1 = 0;

        while(n > 0)
        {
            if(n % 2 == 1)
                cnt1++;
            
            n/=2;
        }

        return cnt1;
    }
};