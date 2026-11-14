class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int max_ele = *max_element(nums.begin(), nums.end());

        for(auto it : nums)
        {
            moves += (max_ele - it);
        }

        return moves;
    }
};