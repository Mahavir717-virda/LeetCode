class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() == 0)
            return {-1,-1};
        vector<int> ans(2, -1);
        int n = nums.size();

        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                j = mid - 1;   
            }
            else if (nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        cout << ans[0];

        if (ans[0] == -1) return ans; 

        i = ans[0], j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                i = mid + 1;   
            }
            else if (nums[mid] < target)

                i = mid + 1;
            else
                j = mid - 1;
        }

        return ans;
    }
};
