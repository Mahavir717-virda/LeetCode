class Solution {
public:
    bool possible(vector<int> &bloomDay, int bDay, int m, int k)
    {
        int cnt = 0, no_of_bu = 0;
        for(int i  = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= bDay)
            {
                cnt++;
            }
            else
            {
                no_of_bu += (cnt / k);
                cnt = 0;
            }
        }

        no_of_bu += (cnt / k);

        if(no_of_bu >= m)
            return true;

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end()), 
        high = *max_element(bloomDay.begin(), bloomDay.end());

        int min_time = 0;
        while(low <= high)
        {
            int mid =low + (high - low) / 2;

            if(possible(bloomDay,mid,m,k))
            {
                min_time = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            } 
        }

        return min_time;
    }
};