class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> ans;

    void CountNodes(TreeNode* node) {
        if (!node) return;
        mp[node->val]++;
        CountNodes(node->left);
        CountNodes(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        CountNodes(root);
        
        int max_freq = 0;
        for (auto it : mp) {
            max_freq = max(max_freq, it.second);
        }
        
        for (auto it : mp) {
            if (it.second == max_freq) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
