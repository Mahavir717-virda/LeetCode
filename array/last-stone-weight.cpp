class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[0];

        int n = stones.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i == 0)
            {
                ans = stones[0];
                break;
            }
            sort(stones.begin(), stones.end());
            int j = i - 1;
            if (stones[i] != stones[j] && j >= 0) {
                stones[j] = stones[i] - stones[j];
            }
            else
                stones[j] = 0;
        }

        return ans;
    }
};