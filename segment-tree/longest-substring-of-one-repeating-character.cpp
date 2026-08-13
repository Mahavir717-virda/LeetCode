class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        vector<int> lengths;

        int n = s.size();

        for (int i = 0; i < queryCharacters.size(); i++) {
            if (n == 1) {
                lengths.push_back(1);
                continue;
            }
            char queryChar = queryCharacters[i];
            int queryCharIdx = queryIndices[i];

            s[queryCharIdx] = queryChar;

            int length = 1;  // length is 1 for any one char
            int low = 0, high = 1;
            char c = s[0];
            while (high < s.size()) {
                if (c == s[high]) {
                    length = max(length, high - low + 1);
                    high++;
                } else {
                    c = s[high];
                    low = high;
                    high++;
                }
            }

            lengths.push_back(length);
        }
        return lengths;
    }
};