class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length(), cnt = 0;
       
        stack <char> st;
        int i = 0;
        while(i < n)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' and !st.empty())
            {
                while(!st.empty() and st.top() == '(' and s[i] == ')')
                {
                    i++;
                    st.pop();
                }
                continue;
            }
            else
            {
                cnt++;
            }
            i++;
        }
        return cnt + st.size();
    }
};