class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;

        int i = 0, j = 0;
        string ans1 = "";
        string ans2 = "";

        while (i < s1.size() and j < s2.size()) {
            if (s1[i] != s2[j]) {
                ans1 += s1[i];
                ans2 += s2[j];
            } else {
                if (ans1.size() != 0) {
                    ans.push_back({ans1, ans2});
                }

                ans1.clear();
                ans2.clear();
            }

            i++;
            j++;
        }

        // Handle a mismatch segment ending at the last index
        if (!ans1.empty()) {
            ans.push_back({ans1, ans2});
        }

        return ans;
    }
};