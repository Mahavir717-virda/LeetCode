class Solution {
public:
    vector<string> ans;
    void backtrack(string current, int opening_par, int closing_par , int n)
    {
        if(current.length() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        if(opening_par < n)
        {
            current += "(";
            backtrack(current, opening_par + 1, closing_par, n);
            current.pop_back();
        }
        
        if(closing_par < opening_par){
            current += ')';
            backtrack(current, opening_par, closing_par + 1, n);
            current.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0, 0, n);
        return ans;
    }
};