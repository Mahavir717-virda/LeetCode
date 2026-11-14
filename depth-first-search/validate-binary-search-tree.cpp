class Solution {
public:
    // Change parameter types to long long to handle INT_MIN/INT_MAX nodes
    bool valid(TreeNode* root, long long left, long long right) {
        if (!root)
            return true;

        // BST properties must be strictly greater than left and strictly less than right
        if (root->val <= left || root->val >= right)
            return false;

        return (valid(root->left, left, root->val) &&
                valid(root->right, root->val, right));
    }
    
    bool isValidBST(TreeNode* root) {
        // Pass the absolute minimum and maximum 64-bit bounds
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
