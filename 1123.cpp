class Solution {
  pair<TreeNode *, int> dfs(TreeNode *root) {
    if (!root)
      return {nullptr, 0};

    pair<TreeNode *, int> l = dfs(root->left);
    pair<TreeNode *, int> r = dfs(root->right);

    if (l.second > r.second) {
      return {l.first, l.second + 1};
    }

    if (r.second > l.second) {
      return {r.first, r.second + 1};
    }

    return {root, l.second + 1};
  }

public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).first; }
};