class Solution {
  TreeNode *oldN = nullptr;
  bool isValid = true;

  void inord(TreeNode *root) {
    if (root == nullptr)
      return;

    inord(root->left);
    if (oldN != nullptr && oldN->val >= root->val) {
      isValid = false;
      return;
    }
    oldN = root;
    inord(root->right);
    return;
  }

public:
  bool isValidBST(TreeNode *root) {
    inord(root);
    return isValid;
  }
};