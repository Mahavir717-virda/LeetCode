class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        st.push(0);
        int i = 0, n = s.size();
        for(auto c : s)
        {   
            if(c == '(')
            {
                st.push(0);
            }
            else
            {
                int first_inner = st.top();
                st.pop();

                int second_inner = st.top();
                st.pop();

                st.push(second_inner + max(2 * first_inner, 1));
            }
        }
        return st.top();
    }
};