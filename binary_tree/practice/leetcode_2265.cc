#include <iostream>
using namespace std;
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
  int valid = 0;

public:
  pair<int, int> isValid(TreeNode *root) {
    if (root == nullptr) {
      return make_pair(0, 0);
    }
    pair<int, int> left = isValid(root->left);
    pair<int, int> right = isValid(root->right);
    int sum = left.first + right.first + root->val;
    int nodes = left.second + right.second + 1;
    if (sum / nodes == root->val) {
      valid++;
    }
    return make_pair(left.first + right.first + root->val,
                     left.second + right.second + 1);
  }
  int averageOfSubtree(TreeNode *root) {
    isValid(root);
    return valid;
  }
};
