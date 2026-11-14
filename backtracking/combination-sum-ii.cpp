class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void combsum(int idx, vector<int> &c, vector<int> &ds, vector<bool> &visited , int target, int sum)
    {
        if(sum > target)
            return;

        if(sum == target)
        {
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i < c.size(); i++)
        {
            if(i > idx and c[i] == c[i - 1]) continue;   //   This logic that i had to see because,   if i have sorted the array than the same elements will be togather than it is easy to avoid the duplicates from above condition
            if(!visited[i])
            {
                visited[i] = true;
                ds.push_back(c[i]);
                sum += c[i];
                combsum(i + 1, c, ds, visited, target, sum);
                sum -= c[i];
                ds.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        combsum(0, candidates, ds, visited, target, 0);
        return ans;
    }
};