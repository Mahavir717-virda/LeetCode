class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(arr.size());

            int maximum = -1;
            for (int j = n - 1; j >= 0 ; j--) {
                ans[j]=maximum;
                maximum = max(maximum, arr[j]);
            } 
        return ans;
    }
};