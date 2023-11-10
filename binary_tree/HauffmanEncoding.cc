#include <iostream>
#include <queue>

using namespace std;

struct node {
  int freq;
  char letter;
  node *left, *right;
  node(int f, char l) : freq(f), letter(l), left(nullptr), right(nullptr){};
};

struct compare {
  bool operator()(node *a, node *b) { return a->freq > b->freq; }
};

void getEncoding(node *root, string code) {
  if (root == nullptr)
    return;
  else if (root->letter != '$')
    cout << root->letter << " : " << code << endl;
  getEncoding(root->left, code + '0');
  getEncoding(root->right, code + '1');
}

void hauffmanEncoding() {
  priority_queue<node *, vector<node *>, compare> pq;
  pq.push(new node(55, 'a'));
  pq.push(new node(20, 'b'));
  pq.push(new node(12, 'c'));
  pq.push(new node(25, 'd'));
  pq.push(new node(30, 'e'));
  pq.push(new node(8, 'f'));
  while (pq.size() > 1) {
    node *left = pq.top();
    pq.pop();
    node *right = pq.top();
    pq.pop();
    node *root = new node(left->freq + right->freq, '$');
    root->left = left;
    root->right = right;
    pq.push(root);
  }
  string code = "";
  getEncoding(pq.top(), code);
  return;
}

int main() {
  hauffmanEncoding();
  return 0;
}
