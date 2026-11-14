/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

     int min_diff = INT_MAX;
    TreeNode* prev = NULL;
    void dfs(TreeNode* root)
    {
        if(root->left) dfs(root->left);

        if(prev) min_diff = min(root->val - prev->val, min_diff);
        prev = root;
        
        if(root->right) dfs(root->right);
    
    }

    int minDiffInBST(TreeNode* root) {
          dfs(root);

        return min_diff;
    }
};