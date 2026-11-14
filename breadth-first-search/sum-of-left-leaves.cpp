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
    int sum = 0;
    void LeftLeaves(TreeNode* node, bool isLeft)
    {
        if(!node)
            return;

        if(isLeft and node and !node->left and !node->right)
        {
            sum += node->val;
        }

        LeftLeaves(node->left, true);
        LeftLeaves(node->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        LeftLeaves(root, false);
        return sum;
    }
};