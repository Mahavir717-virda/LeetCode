class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;
    void backtrack(int num, int n, int k)
    {
        if(comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }

        for(int i = num; i <= n; i++)
        {
            comb.push_back(i);
            backtrack(i + 1, n , k);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n , k);
        return ans;
    }
};