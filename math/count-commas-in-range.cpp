class Solution {
public:
    long long countCommas(int n) {
        int dummy = n;
        int carry, cnt = 0;
        while (dummy > 0) {
            cnt++;
            dummy /= 10;
        }

            int num_cnt = 0;
        if (cnt <= 3)
            return 0;
        else {
            long long i = 1000;
            while (i <= n) {
                    num_cnt++;
                    i++;
            }
        }

        return num_cnt;
    }
};