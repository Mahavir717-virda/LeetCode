#define ll long long 
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        ll cnt = 0;
        int n = intervals.size();
        vector<int> start(n);
        for(int i = 0; i < n; i++)
        {
            // all the starts are sorted like,  start[0] <= start[1] always true
           start[i] = intervals[i][0];
        }

        for(int i = 0; i < n; i++)
        {
            // so we need to find that 
            // for current end how many pairs are overlapping using binary search
            int end = intervals[i][1];
            int idx = upper_bound(start.begin() + i + 1, start.end(), end) - start.begin();
            cnt += (idx - (i + 1));
        }
        
        return cnt;
    }
};