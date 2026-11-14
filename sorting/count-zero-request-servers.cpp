class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        //   We will first store the original index of the queries because the return answer is in the given order not in sorted order
        int q = queries.size();
        vector<pair<int, int>> timeIndex(q);  //   [ {queries[i] , originalIdx} ]
        for(int i = 0; i < q; i++)
        {
            timeIndex[i] = {queries[i], i};
        }
        ranges::sort(timeIndex);

        //  return array size of queries
        vector<int> ans(q);

        //   Sorting the logs on increasing order based on the logs time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int l = logs.size();
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        for (auto [time, idx]: timeIndex) {
            int start = time - x;
            int end = time;

            //   Sliding Window Approach
            //   First we will expand the window based on the ending time of query
            while (j < l and logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            //  Second we will shrink the window based on the start time , because we will eliminate the logs that has not been in the range
            while(i < l and logs[i][1] < start)
            {
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0) mp.erase(logs[i][0]);
                i++;
            }

            //  # of servers got 0 requests = n - (total unique servers)
            int result = n - mp.size();
            ans[idx] = result;
        }

        return ans;
    }
};