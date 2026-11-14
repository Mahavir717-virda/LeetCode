class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        if (n == 1)
            return 0;

        int maxg = 0;
        vector<int> left_match(n);
        vector<int> right_match(n);

        int idx1 = 0;
        for (int i = 0; i < n; i++) {
            while (idx1 < m && station[idx1] != skill[i]) {
                idx1++;
            }
            left_match[i] = idx1;
            idx1++;
        }

        int idx2 = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (idx2 >= 0 && station[idx2] != skill[i]) {
                idx2--;
            }
            right_match[i] = idx2;
            idx2--;
        }

        for (int i = 1; i < n; i++) {
            int current_gap = right_match[i] - left_match[i - 1];
            maxg = max(maxg, current_gap);
        }

        return maxg;
    }
};
