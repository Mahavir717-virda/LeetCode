class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum_left(n, 0);
        vector<int> prefix_sum_right(n, 0);

        prefix_sum_left[0] = nums[0];
        prefix_sum_right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefix_sum_left[i] = nums[i] + prefix_sum_left[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            prefix_sum_right[i] = nums[i] + prefix_sum_right[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (prefix_sum_left[i] == prefix_sum_right[i])
                return i;
        }

        return -1;
    }
};