#include <iostream>

using namespace std;

typedef struct node {
  int info;
  node *next;
} node;

void insertion(int value, node *&head) {
  node *temp = nullptr;
  temp = new node;
  temp->info = value;
  if (head == nullptr) {
    temp->next = nullptr;
    head = temp;
    return;
  }
  temp->next = head;
  head = temp;
  return;
}

int main() {
  node *head = nullptr;
  // node *iter = nullptr;
  // insertion(100, head);
  // insertion(102, head);
  // iter = head;
  // while (iter != nullptr) {
  //   cout << iter->info << " ";
  //   iter = iter->next;
  // }
  return 0;
}
