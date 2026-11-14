class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> days(n, 0);
        stack<pair<int,int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && (temperatures[i] > s.top().first)) {
                int stemp = s.top().first;
                int sidx = s.top().second;
                s.pop();
                days[sidx] = i - sidx;
            }

            s.push({temperatures[i], i});
        }

        return days;
    }
};