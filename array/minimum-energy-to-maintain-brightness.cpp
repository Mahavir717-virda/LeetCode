class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        long long ans = 0;
        long long num_bulb = (brightness + 3 - 1) / 3;

        long long tot_l = intervals[0][0];
        long long tot_r = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            long long curr_l = intervals[i][0];
            long long curr_r = intervals[i][1];

            if (curr_l <= tot_r) {
                tot_r = max(tot_r, curr_r);
            } else {
                ans += (tot_r - tot_l + 1);
                tot_l = curr_l;
                tot_r = curr_r;
            }
        }

        ans += (tot_r - tot_l + 1);

        ans *= num_bulb;
        return ans;
    }
};