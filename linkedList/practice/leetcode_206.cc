#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *it1 = nullptr;
    ListNode *it2 = head;
    ListNode *it3 = head;
    while (it3 != nullptr) {
      it3 = it3->next;
      it2->next = it1;
      it1 = it2;
      it2 = it3;
    };
    return it1;
  }
};

int main() { return 0; }
