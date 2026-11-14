class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int max_cnt = 0, depth = 0;    
        int n = s.size();   
        for(int i = 0; i < n; i++)
        {
           if(s[i] == '(')
           {
              depth++;
              max_cnt = max(max_cnt, depth);
           }
           else if(s[i] == ')')
           {
            depth--;
           }
        }

        return max_cnt; 
    }
};