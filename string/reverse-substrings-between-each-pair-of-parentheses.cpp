class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>> st;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i], i});
            }
            else if(s[i] == ')')
            {
                auto [ par, idx ] = st.top();
                st.pop();

                int start = idx, end = i;
                while(start < end)
                {
                    if(s[start] != '(')
                    {
                        if(s[end] != ')')
                        {
                           swap(s[start], s[end]);
                           start++; end--;
                        }
                        else
                        {
                            end--;
                        }         
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }

        string ans = "";
        for(auto ch : s)
        {
            if(ch != '(' and ch != ')')
            {
                ans += ch;
            }
        }
        return ans;
    }
};