class Solution {
public:
    int longestAwesome(string s) {
        vector<int> first_seen(1024, -2); 
        first_seen[0] = -1; 
        
        int mask = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';
            mask ^= (1 << digit); 
            
            if (first_seen[mask] != -2) {
                max_len = max(max_len, i - first_seen[mask]);
            } else {
                first_seen[mask] = i; 
            }
            
            
            for (int d = 0; d < 10; d++) {
                int next_mask = mask ^ (1 << d);
                if (first_seen[next_mask] != -2) {
                    max_len = max(max_len, i - first_seen[next_mask]);
                }
            }
        }
        
        return max_len;
    }
};
