class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = INT_MIN, height = 0;
        gain.insert(gain.begin() + 0, 0);

        for (auto it : gain) {
            height += it;
            altitude = max(altitude, height);
        }
        return altitude;
    }
};