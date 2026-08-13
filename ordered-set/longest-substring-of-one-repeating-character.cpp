class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        vector<int> lengths;

        int n = s.size();

        for (int i = 0; i < queryCharacters.size(); i++) {
            int length = 0;
            char queryChar = queryCharacters[i];
            int queryCharIdx = queryIndices[i];

            s[queryCharIdx] = queryChar;

            int low = 0, high = 1;

            char c = s[0];
            while (high < s.size()) {
                if (c == s[high]) {
                    high++;
                    length = max(length, high - low);
                } else {
                    c = s[high];
                    low = high;
                }
            }

            lengths.push_back(length);
        }
        return lengths;
    }
};