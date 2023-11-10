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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
  int sum = 0;
  int deepest = 0;

public:
  void sumCalculator(TreeNode *root, int level) {
    if (root == nullptr)
      return;
    if (level > deepest) {
      deepest = level;
      sum = 0;
      sum += root->val;
    } else if (level == deepest)
      sum += root->val;
    sumCalculator(root->right, level + 1);
    sumCalculator(root->left, level + 1);
  }
  int deepestLeavesSum(TreeNode *root) {
    sumCalculator(root, 0);
    return sum;
  }
};
