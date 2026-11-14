class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(auto it : nums)
        {
            if(it > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = it;
            }
            else if(it > max2)
            {
                max3 = max2;
                max2 = it;
            }
            else if(it > max3)
            {
                max3 = it;
            }

            if(min1 > it)
            {
                min2 = min1;
                min1 = it;
            }
            else if(min2 > it)
            {
                min2 = it;
            }
        }

        int op1 = max1 * max2 * max3;
        int op2 = min1 * min2 * max1;

        return max(op1, op2);
    }
};