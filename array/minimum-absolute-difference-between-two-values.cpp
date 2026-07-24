class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        int min_diff=nums.size();

        bool found = false;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if ((nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1)) {
                    min_diff = min(min_diff,abs(i-j));
                    found = true;
                }
            }
        }
        if(!found) return -1;
        return min_diff;
    }
};