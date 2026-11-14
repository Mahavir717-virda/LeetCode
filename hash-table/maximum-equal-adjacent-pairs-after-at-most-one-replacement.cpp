class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int paircnt = 0;

        map<pair<int, int>, int> mp;
        int base = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            if (a == b) {
                base++;
            } else {
                if (a > b)
                    swap(a, b);
                mp[{a, b}]++;
            }
        }

        int best = 0;
        for (auto it : mp) {
            best = max(best, it.second);
        }

        return base + best;
    }
};