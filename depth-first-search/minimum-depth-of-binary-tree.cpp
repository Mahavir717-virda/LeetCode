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
    int depth = INT_MAX;
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        Mindepth(root, 1);
        return depth;
    }

    bool isLeaf(TreeNode* node)
    {
        return ( (node != nullptr) 
        and( node->left == nullptr )
        and (node->right == nullptr) );
    }
    void Mindepth(TreeNode* node, int height)
    {
        if(!node)
            return;
        
        if(isLeaf(node))
        {
            depth = min(depth, height);
        }

        Mindepth(node->left, height + 1);
        Mindepth(node->right, height + 1);
    }
};