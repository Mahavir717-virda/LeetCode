class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int cnt = 1;
        int sm = k;
        set<int> s;
        for(auto it : nums)
        {
            s.insert(it);
        }

        if(s.find(k) == s.end())
            return k;

        for(auto it : s)
        {
            if(it % k == 0)
            {
                cnt++;
            }
        }

        return k * cnt;


    }
};