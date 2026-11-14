class Solution {
public:
    bool IsTargetSum(TreeNode* node, int targetSum, int currSum) {
        if (!node) return false;

        currSum += node->val;

        if (!node->left && !node->right) {
            return currSum == targetSum;
        }

        return IsTargetSum(node->left, targetSum, currSum) || 
               IsTargetSum(node->right, targetSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return IsTargetSum(root, targetSum, 0);
    }
};
