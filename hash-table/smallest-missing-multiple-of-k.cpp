class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int cnt = 1;
        set<int> s;
        for(auto it : nums)
        {
            s.insert(it);
        }

        while(true)
        {
            if(s.find(cnt * k) == s.end())
            {
                return k * cnt;
            }
            cnt++;
        }
    }
};