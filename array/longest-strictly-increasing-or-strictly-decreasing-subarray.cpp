class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        // Increasing array
        int i = 0, j = 1, max_len_in = 1, prev = nums[0];
        while (j < n) {
            if (prev < nums[j]) {
                prev = nums[j];
                j++;
            } else {
                prev = nums[j];

                i = j;
                j = j + 1;
            }
            max_len_in = max(max_len_in, j - i);
        }

        // Decresing array
        i = 0, j = 1, prev = nums[0];
        int max_len_dec = 1;
        while (j < n) {
            if (prev > nums[j]) {
                prev = nums[j];
                j++;
            } else {
                prev = nums[j];
                i = j;
                j = j + 1;
            }
            max_len_dec = max(max_len_dec, j - i);
        }

        return max(max_len_in, max_len_dec);
    }
};