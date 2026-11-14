class Solution {
public:
    vector<vector<int>> ans;
    vector<int> result;
    
    void comb(int k, int n, int idx, int sum) {
        if (result.size() == k and sum == n) {
            ans.push_back(result);
            return;
        }

        if (result.size() >= k || sum >= n || idx > 9) {
            return;
        }

        result.push_back(idx);
        comb(k, n, idx + 1, sum + idx);
        result.pop_back(); 

        comb(k, n, idx + 1, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > n)
            return {};
        
        comb(k, n, 1, 0); 
        return ans;
    }
};