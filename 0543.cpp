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
private:
    int ans = 0;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        ans = max(ans, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};
