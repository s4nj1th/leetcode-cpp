class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> trav;
    for (int i : inorderTraversal(root->left)) {
      trav.push_back(i);
    }

    trav.push_back(root->val);

    for (int i : inorderTraversal(root->right)) {
      trav.push_back(i);
    }

    return trav;
  }
};