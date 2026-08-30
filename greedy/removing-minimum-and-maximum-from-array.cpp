class Solution {
public:
    int fromfront(vector<int>& nums, int min, int max) {
        int cnt = 0, n = nums.size();
        bool fmin = false, fmax = false;
        for (int i = 0; i < n; i++) {
            if (fmin and fmax)
                return cnt;

            if (nums[i] == min) {
                fmin = true;
                cnt++;
            } else if (nums[i] == max) {
                fmax = true;
                cnt++;
            } else
                cnt++;
        }

        return cnt;
    }
    int fromback(vector<int>& nums, int min, int max) {
        int cnt = 0, n = nums.size();
        bool fmin = false, fmax = false;
        for (int i = n - 1; i >= 0; i--) {
            if (fmin and fmax)
                return cnt;

            if (nums[i] == min) {
                fmin = true;
                cnt++;
            } else if (nums[i] == max) {
                fmax = true;
                cnt++;
            } else
                cnt++;
        }

        return cnt;
    }
    int fromboth(vector<int>& nums, int min, int max) {
        int cnt = 0, n = nums.size();
        bool fmin = false, fmax = false;
        int i = 0, j = n - 1;
        while (i < j) {
            if (fmin and fmax)
                return cnt;
            // from left check min or max
            if (nums[i] == min) {
                fmin = true;
                cnt++;
            } else if (nums[i] == max) {
                fmax = true;
                cnt++;
            }
            // from right check min or max
            if (nums[j] == min) {
                fmin = true;
                cnt++;
            } else if (nums[j] == max) {
                fmax = true;
                cnt++;
            }
            cnt++;
            i++;
            j--;
        }
        return cnt;
    }
    int minimumDeletions(vector<int>& nums) {

        if(nums.size() == 1)
            return 1;
        
        if(nums.size() == 2)
            return 2;

        auto minele = *min_element(nums.begin(), nums.end());
        auto maxele = *max_element(nums.begin(), nums.end());

        int frontcnt = fromfront(nums, minele, maxele);
        int backcnt = fromback(nums, minele, maxele);
        int bothcnt = fromboth(nums, minele, maxele);

        return min({frontcnt, backcnt, bothcnt});
    }
};