class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        vector<int> answer(nums.size(),0);
        if(nums.size() <= 1) return answer;

        for(int i = 0;i<nums.size()-1;i++)
            {
                for(int j = i+1;j<nums.size();j++)
                    {
                        if(nums[i] % 2 != 0)
                        {
                            if(nums[j] % 2 == 0)
                            {
                                answer[i]++;
                            }
                        }
                        else
                        {
                            if(nums[j] % 2 != 0)
                            {
                                answer[i]++;
                            }
                        }
                    }
            }

        return answer;

        
    }
};