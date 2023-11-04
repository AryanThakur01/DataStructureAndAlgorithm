#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

class Solution {
  TreeNode *copy = nullptr;

public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    if (cloned->left != nullptr)
      left = getTargetCopy(original, cloned->left, target);
    if (cloned->right != nullptr)
      right = getTargetCopy(original, cloned->right, target);
    if (left->val == target->val)
      copy = left;
    if (right->val == target->val)
      copy = right;
    return copy;
  }
};
