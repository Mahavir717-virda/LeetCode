class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL(height.size());
        vector<int> maxR(height.size());
        int n = height.size();
        maxL[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxL[i] = max(height[i], maxL[i - 1]);
        }
        maxR[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxR[i] = max(height[i], maxR[i + 1]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            if ((min(maxL[i], maxR[i]) - height[i]) < 0) {
                continue;
            } else {
                water += (min(maxL[i], maxR[i]) - height[i]);
            }
        }
        return water;
    }
};