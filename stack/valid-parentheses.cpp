class Solution {
public:
    bool isValid(std::string s) {
        unordered_map<char, char> bracket_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
              };

        stack<char> st;

        for (char ch : s) {
            if (bracket_map.count(ch)) {   //   here if the closing bracket appear than check the below condition 
                if (st.empty() || st.top() != bracket_map[ch]) { //   Here we will check that 
                    //   1.   Stack should not be empty if it is empty than it means you have a character that it`s corresponding character is not there in stack ,  it means it is not a valid parantheses
                    return false;
                }
                st.pop();  //  if the top of stack and current bracket will be matched than it will be popped from the stack
            } else {
                st.push(ch);   //  if the opening bracket will appear than it will be pushed onto stack
            }
        }

        return st.empty();  //   if the stack will be empty than it is a valid parantheses
    }
};
