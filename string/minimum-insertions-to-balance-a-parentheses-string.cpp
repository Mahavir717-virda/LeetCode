class Solution {
public:
    int minInsertions(string s) {
        int insert = 0, cn = 0;
        for (auto ch : s) {
            if (ch == '(') {
                cn += 2;
                if (cn % 2 != 0) {
                    insert += 1;
                    cn -= 1;
                }
            } else if (ch == ')') {
                cn -= 1;
                if (cn < 0) {
                    insert += 1;
                    cn += 2;
                }
            }
        }

        return insert + cn;
    }
};