    class Solution {
    public:
        unordered_set<string> ans;

        void GenerateValidString(int idx, int removeClose, int removeOpen,
                                int openCount, string &str, string& s) {
            if (idx == s.size()) {
                if (removeClose == 0 && removeOpen == 0 && openCount == 0) {
                    ans.insert(str);
                }
                return;
            }

            if (s[idx] == '(') {
                // remove if the there is any opening bracket count
                if (removeOpen > 0) {
                    GenerateValidString(idx + 1, removeClose, removeOpen - 1,
                                        openCount, str, s);
                }

                // Otherwise keep it
                str.push_back('(');

                GenerateValidString(idx + 1, removeClose, removeOpen, openCount + 1,
                                    str, s);

                str.pop_back();

            }
            //   if it is a character than we just push it to current answer
            else if (s[idx] >= 'a' and s[idx] <= 'z') {
                str.push_back(s[idx]);
                
                GenerateValidString(idx + 1, removeClose, removeOpen, openCount,
                                    str, s);

                str.pop_back();

            }

            else if (s[idx] == ')') {
                // remove if the there is any closing bracket count
                if (removeClose > 0) {
                    GenerateValidString(idx + 1, removeClose - 1, removeOpen,
                                        openCount, str, s);
                }

                //  Keep closing if there is any opened paranthesis exist
                if (openCount > 0) {
                    str.push_back(')');

                    GenerateValidString(idx + 1, removeClose, removeOpen,
                                        openCount - 1, str, s);

                    str.pop_back();
                }
            }
        }
        vector<string> removeInvalidParentheses(string s) {
            stack<char> st;
            int cnt = 0;

            int i = 0;
            while (i < s.size()) {
                if (s[i] == '(') {
                    st.push(s[i]);
                } else if (s[i] == ')') {
                    if (!st.empty()) {
                        // Found a valid matching pair, remove the opening one
                        st.pop();
                    } else {
                        // No matching opening parenthesis, this closing one is
                        // invalid
                        cnt++;
                    }
                }
                i++;
            }
                string str = "";
            GenerateValidString(0, cnt, st.size(), 0, str, s);
            vector<string> all_string;

            for (auto& it : ans) {
                all_string.push_back(it);
            }

            return all_string;
        }
    };