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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int max_width = INT_MIN;
        while (!q.empty()) {
            unsigned long long stidx = q.front().second;
            unsigned long long enidx = q.back().second;

            max_width = max(max_width, (int)(enidx - stidx + 1));

            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto node = q.front();
                q.pop();

                if (node.first->left)
                    q.push({node.first->left, 2 * node.second + 1});
                if (node.first->right)
                    q.push({node.first->right, 2 * node.second + 2});
            }
        }

        return max_width;
    }
};