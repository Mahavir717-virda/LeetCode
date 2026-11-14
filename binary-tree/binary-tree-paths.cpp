/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void AllPaths(TreeNode* node, string str) {
        if (!node)
            return;

        if (node and !node->left and !node->right) {
            str += to_string(node->val);
            ans.push_back(str);
        }

        str += to_string(node->val);
        str += "->";
        AllPaths(node->left, str);
        AllPaths(node->right, str);

        str.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        AllPaths(root, "");
        return ans;
    }
};