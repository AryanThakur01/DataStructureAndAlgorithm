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
  int gcdCalculator(int a, int b) {
    int gcd = a < b ? a : b;
    while (gcd) {
      if (a % gcd == 0 && b % gcd == 0)
        return gcd;
      gcd--;
    }
    return 1;
  }
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if (head->next == nullptr)
      return head;
    ListNode *it = head;
    while (it->next != nullptr) {
      ListNode *next = it->next;
      int gcd = gcdCalculator(it->val, next->val);
      ListNode *newNode = new ListNode(gcd, next);
      it->next = newNode;
      it = next;
    }
    return head;
  }
};
