class Solution {
public:
    int fromfront(vector<int>& nums, int min, int max) {
        int cnt = 0, n = nums.size();
        bool fmin = false, fmax = false;
        for (int i = 0; i < n; i++) {
            cnt++;

            if (nums[i] == min) {
                fmin = true;
            } else if (nums[i] == max) {
                fmax = true;
            }

            if (fmin and fmax)
                return cnt;
        }

        return cnt;
    }
    int fromback(vector<int>& nums, int min, int max) {
        int cnt = 0, n = nums.size();
        bool fmin = false, fmax = false;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;

            if (nums[i] == min) {
                fmin = true;
            } else if (nums[i] == max) {
                fmax = true;
            }

            if (fmin and fmax)
                return cnt;
        }

        return cnt;
    }
    int fromboth(vector<int>& nums, int min, int max) {
        int lcnt = 0, rcnt = 0, n = nums.size();
         for (int i = 0; i < n; i++) {
            lcnt++;
            if (nums[i] == min || nums[i] == max) {
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            rcnt++;
            if (nums[i] == min || nums[i] == max) {
                break;
            } 
        }

        return lcnt + rcnt;
    }
    int minimumDeletions(vector<int>& nums) {

        if (nums.size() == 1)
            return 1;

        if (nums.size() == 2)
            return 2;

        auto minele = *min_element(nums.begin(), nums.end());
        auto maxele = *max_element(nums.begin(), nums.end());

        int frontcnt = fromfront(nums, minele, maxele);
        int backcnt = fromback(nums, minele, maxele);
        int bothcnt = fromboth(nums, minele, maxele);

        return min({frontcnt, backcnt, bothcnt});
    }
};