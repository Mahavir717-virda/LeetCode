class Solution {
public:
    vector<int> ans;
    void dfs(int curr, int n)
    {
        if(curr > n)
            return;
        
        ans.push_back(curr);
        curr *= 10;
        for(int i = 0; i < 10; i++)
            dfs(curr + i,n);
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++)
            dfs(i, n);
        return ans;
    }
};