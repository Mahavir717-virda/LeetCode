class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, lastseen = -10001;
        for (int i = 0; i < nums.size(); i++) {
            if (lastseen == nums[i]) {
                cnt++;
            } else {
                lastseen = nums[i];
                cnt = 1;
            }

            if (cnt > 2) {
                i--;
                cnt--;
                nums.erase(nums.begin() + i);
            }
        }

        return nums.size();
    }
};