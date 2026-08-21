class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        map<int, int> dis;
        for (int i = 0; i < drones.size(); i++) {
            int d =
                (abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]));
            if (d <= drones[i][2]) {
                dis[i] = d;
            }
        }
        if (dis.size() == 0)
            return -1;
        int mind = INT_MAX, ans= 0;
        for (int i = 0; i < drones.size(); i++) {
            if (dis.find(i) != dis.end())
            {
                if(dis[i] < mind)
                {
                    ans = i;
                    mind = dis[i];
                }
            }
        }
        return ans;
    }
};