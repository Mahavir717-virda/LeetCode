class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        int n = prices.size();
        int m = discounts.size();
        double minp = 0.0;
        int rem = 0;
        for (int i = 0; i < n; i++) {
            if (i < m) {
                minp += (double)(prices[i] * (100 - discounts[i])) / 100;
            } else {
                minp += prices[i];
            }
        }

        return minp;
    }
};