class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;

        for(int x : nums1) freq[x]++;
        for(int x : nums2) freq[x]--;

        int diff = 0;

        for(auto &p : freq) {
            if(p.second % 2 != 0) return -1;
            diff += abs(p.second);
        }

        return diff / 4;
    }
};