class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return nums;

        vector<int> VE;

        // 1. First element is always valid
        VE.push_back(nums[0]);

        for (int i = 1; i < nums.size() - 1; i++) {
            // Check Condition 1: Strictly greater than every element to its left
            bool greaterThanAllLeft = true;
            for (int x = 0; x < i; x++) {
                if (nums[i] <= nums[x]) {
                    greaterThanAllLeft = false;
                    break;
                }
            }

            // Check Condition 2: Strictly greater than every element to its right
            bool greaterThanAllRight = true;
            for (int y = i + 1; y < nums.size(); y++) {
                if (nums[i] <= nums[y]) {
                    greaterThanAllRight = false;
                    break;
                }
            }

            // nums[i] is valid if either condition is true
            if (greaterThanAllLeft || greaterThanAllRight) {
                VE.push_back(nums[i]);
            }
        }

        // 3. Last element is always valid
        VE.push_back(nums[nums.size() - 1]);

        return VE;
    }
};