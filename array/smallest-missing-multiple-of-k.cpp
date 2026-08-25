class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int cnt = 1;
        int sm = k;
        unordered_map<int,int> mp;
        for(auto it : nums)
        {
            mp[it]++;
        }

        if(mp.find(k) == mp.end())
            return k;

        for(auto it : mp)
        {
            if(it.first % k == 0)
            {
                cnt++;
            }
        }

        return k * cnt;


    }
};