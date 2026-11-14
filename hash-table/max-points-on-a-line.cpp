class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<double, int> mp;
            for (int j = i + 1; j < n; j++) {

                double slope;

                if (points[j][0] == points[i][0])
                    slope = 1e9;
                else
                    slope = (double)(points[j][1] - points[i][1]) /
                            (points[j][0] - points[i][0]);

                mp[slope]++;
            }

            for (auto it : mp) {
                ans = max(ans, it.second + 1);
            }
        }

        return ans;
    }
};