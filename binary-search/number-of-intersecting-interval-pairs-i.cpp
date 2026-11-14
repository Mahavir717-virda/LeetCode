class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0, n = intervals.size();

        for (int i = 0; i < n; i++) {
            int prevstart = intervals[i][0];
            int prevend = intervals[i][1];

            for (int j = i + 1; j < n; j++) {
                int currstart = intervals[j][0];
                int currend = intervals[j][1];
                if (currstart == prevstart || currstart == prevend) {
                    cnt++;
                } else if (prevend >= currstart) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};