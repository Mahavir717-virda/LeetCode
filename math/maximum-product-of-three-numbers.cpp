class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        return (nums[nums.size() - 1]*nums[nums.size() - 2]*nums[nums.size() - 3]);
    }
};