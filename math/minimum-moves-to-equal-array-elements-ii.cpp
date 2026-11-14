class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ranges::sort(nums);
        int moves = 0;
        int mid_ele_idx = nums.size() / 2;


        int eq = nums[mid_ele_idx];

        for(auto it : nums)
        {
            moves += abs(eq - it);
        }
        
        return moves;
    }
}; 