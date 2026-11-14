#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> mp;

        for (int i = 0; i <= n - k; i++) {
            
            set<int> s;
            
            for (int j = i; j < i + k; j++) {
                s.insert(nums[j]);
            }

            for (int num : s) {
                mp[num]++;
            }
        }

        int mis = -1;

        for (auto it : mp) {
            if (it.second == 1) {
                mis = max(mis, it.first);
            }
        }

        return mis;
    }
};
