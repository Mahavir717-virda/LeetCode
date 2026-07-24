class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxbar = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < costs.size(); i++) {
            maxi = max(maxi, costs[i]);
        }
        vector<int> freq(maxi + 1);

        for (int i = 0; i < costs.size(); i++) {
            freq[costs[i]]++;
        }

        for (int i = 1; i <= maxi; i++) {
            if (freq[i] > 0) {
                int canBuy = min(freq[i], coins / i);
                maxbar += canBuy;
                coins -= canBuy * i;
            }

            if (coins < i)
                break;
        }

        return maxbar;
    }
};