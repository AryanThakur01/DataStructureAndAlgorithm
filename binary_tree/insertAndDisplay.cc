#include <iostream>
using namespace std;

struct node {
  struct node *left;
  int val;
  struct node *right;
  node() : val(0), left(nullptr), right(nullptr){};
  node(int v) : val(v), left(nullptr), right(nullptr){};
  node(int v, node *l, node *r) : val(v), left(l), right(r){};
};
class BinaryTree {
private:
  node *root;
  int level = 0;
  void createTree() {}
  void preOrder(node *n);
  void inOrder(node *n);
  void postOrder(node *n);

public:
  BinaryTree();
  void showTree();
};

// ====================== DRIVER FUNCTION ===========================
int main() {
  BinaryTree b;
  b.showTree();
  return 0;
}
// ==================================================================

BinaryTree::BinaryTree() {
  node *newNode = new node(1);
  root = newNode;
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(8);
  root->right->right = new node(5);
  root->right->left = new node(6);
}

void BinaryTree::postOrder(node *n) {
  if (n == nullptr)
    return;
  postOrder(n->left);
  postOrder(n->right);
  cout << n->val << " ";
};
void BinaryTree::inOrder(node *n) {
  if (n == nullptr)
    return;
  inOrder(n->left);
  cout << n->val << " ";
  inOrder(n->right);
};
void BinaryTree::preOrder(node *n) {
  if (n == nullptr)
    return;
  cout << n->val << " ";
  preOrder(n->left);
  preOrder(n->right);
};
void BinaryTree::showTree() {
  cout << "Pre-Order: ";
  preOrder(root);
  cout << endl << "In-Order: ";
  inOrder(root);
  cout << endl << "Post-Order: ";
  postOrder(root);
}
