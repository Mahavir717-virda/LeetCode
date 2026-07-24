class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> s;
        int m = n;
        while(m > 0)
            {
            s.push_back(m % 2);
                m /= 2;
            }
        reverse(s.begin(), s.end());
        int x = s.size(),cnt = 0;
        for(int i = 1; i < x; i++)
            {
                if(s[i] == 1 && s[i-1] == 1)
                {
                    cnt++;
                }
            }
        if (cnt == 1) return true;

        return false;
    }
};