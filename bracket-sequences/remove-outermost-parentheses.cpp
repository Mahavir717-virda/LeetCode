class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else
                {
                    st.push(s[i]);
                    ans+=s[i];
                }
            }
            else
            {
                char c = st.top();
                st.pop();
                if(st.empty())
                {
                    continue;
                }
                else
                {
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};