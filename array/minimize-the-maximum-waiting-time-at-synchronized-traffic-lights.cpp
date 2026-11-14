class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int penalty = 0;
        int maxt = *max_element(lights.begin(), lights.end());
        for (int i = 0; i < arrivalTime.size(); i++) {
            long long r = (long long)arrivalTime[i] % period;

            if (r >= maxt) {
                int current_wait = period - r;
                penalty = max(penalty, current_wait);
            }
        }
        // Greedy approach
        // for (int i = 0; i < arrivalTime.size(); i++) {
        //     int j = 0;
        //     long long c = arrivalTime[i];
        //     long long r = c % period;
        //     int car_best_wait = INT_MAX;
        //     while (j < lights.size()) {
        //         int current_light_wait = 0;
        //         if (r >= lights[j]) {
        //             current_light_wait = period - r;
        //         } else {
        //             current_light_wait = 0;
        //         }
        //         car_best_wait = min(car_best_wait, current_light_wait);
        //         j++;
        //     }
        //     penalty = max(car_best_wait, penalty);
        // }

        return penalty;
    }
};