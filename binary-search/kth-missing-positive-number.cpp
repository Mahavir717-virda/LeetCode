class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> mp(arr.begin(),arr.end());
        int cnt = 0;

        for (int i = 1; ; i++) {
            if(mp.find(i) == mp.end())
            {
                cnt++;
                if(cnt == k)
                    return i;
            }
        }
    }
};