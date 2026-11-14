class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(target - numbers[i]) != mp.end())
            {
                ans.push_back(mp[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                break;
            }
            mp[numbers[i]] = i;
        }

        return ans;
    }
};