class Solution {
public:
    long long find_time(vector<int>& piles, int hourly) {
        long long total_time = 0;
        for (int i = 0; i < piles.size(); i++) {
            total_time += (piles[i] + hourly - 1) / hourly;
        }

        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_piles = max_element(piles.begin(), piles.end());
        int low = 1, high = *max_piles, ans = INT_MAX;
        long long req_time;
        while (low <= high) {
            int mid = (high + low) / 2;
            req_time = find_time(piles, mid);

            if (req_time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};