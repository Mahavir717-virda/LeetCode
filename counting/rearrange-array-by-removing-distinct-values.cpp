class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        while (true) {
            bool op = false;
            for (auto it : mp) {
                if (it.second > 0) {
                    ans.push_back(it.first);
                    mp[it.first]--;
                    op = true;
                }
            }

            if(!op)
            {
                break;
            }
        }

        return ans;
    }
};