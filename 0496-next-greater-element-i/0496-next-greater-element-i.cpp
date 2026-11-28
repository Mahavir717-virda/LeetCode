class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++) {
            int idx = -1;
            for (int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j])
                {
                    idx = j;
                    break;
                }
            }
            bool found = false;
            for (int j = idx + 1; j < m; j++) {
                if (nums1[i] < nums2[j]) {
                    found = true;
                    ans.push_back(nums2[j]);
                    break;
                }
            }

            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};