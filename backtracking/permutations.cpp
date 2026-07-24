class Solution {
public:

    void computePermu(vector<int> & ds, vector<int> & freq, vector<vector<int>> & ans, vector<int> & nums)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!freq[i])
            {
                freq[i]=1;
                ds.push_back(nums[i]);
                computePermu(ds,freq,ans,nums);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> freq(nums.size(),0);
        vector<int> ds;
        
        computePermu(ds,freq,ans,nums);
        return ans;
    }
};