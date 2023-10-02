/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    bool moveMid = 0;
    ListNode *it = head;
    ListNode *mid = head;
    while (it != nullptr) {
      if (moveMid)
        mid = mid->next;

      moveMid = !moveMid;
      it = it->next;
    }
    return mid;
  }
};
