class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> bulbcount;
        vector<int> ans;

        for (int i = 0; i < bulbs.size(); i++) {
            bulbcount[bulbs[i]]++;
        }

        for (auto it : bulbcount) {
            if (it.second % 2 != 0) {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};