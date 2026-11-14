#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s1;
        
        for (int it : asteroids) {
            bool destroyed = false;
            
            while (!s1.empty() && s1.top() > 0 && it < 0) {
                if (s1.top() < abs(it)) {
                    s1.pop(); 
                    continue;
                } else if (s1.top() == abs(it)) {
                    s1.pop(); 
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; 
                    break;
                }
            }
            
            if (!destroyed) {
                s1.push(it);
            }
        }
        
        vector<int> ans;
        while (!s1.empty()) {
            ans.push_back(s1.top());
            s1.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
