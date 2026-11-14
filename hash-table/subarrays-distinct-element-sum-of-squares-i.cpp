class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(int i =0;i < n; i++)
        {
            set<int> s;
            for(int j = i; j < n; j++)
            {
                for(int z = i; z <= j; z++)
                {
                    s.insert(nums[z]);
                }
                sum += pow(s.size(), 2);
            }
        }
        
        return sum;
    }
};