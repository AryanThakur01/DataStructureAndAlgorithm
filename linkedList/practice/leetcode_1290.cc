#include <iostream>

using namespace std;
typedef struct ListNode {
  int val;
  ListNode *next;
} node;

// Conversion from binary to decimal
int getDecimalValue(struct ListNode *);
void insert(node **, int);
void display(node *);

int main() {
  struct ListNode *head = nullptr;
  insert(&head, 1);
  insert(&head, 0);
  insert(&head, 1);
  // for (int i = 0; i < 11; i++)
  //   insert(&head, i % 2);
  display(head);
  cout << getDecimalValue(head) << endl;
  return 0;
}

// push in
void insert(node **head, int val) {
  if (*head == nullptr) {
    *head = new node;
    (*head)->val = val;
    (*head)->next = nullptr;
    return;
  }
  node *it = nullptr;
  it = *head;
  while (it->next != nullptr)
    it = it->next;
  node *temp = nullptr;
  temp = new node;
  temp->val = val;
  it->next = temp;
  temp->next = nullptr;
};

// let me see
void display(node *it) {
  while (it != nullptr) {
    cout << it->val << "|-->";
    it = it->next;
  }
  cout << endl;
}

// Convert binary to decimal
int getDecimalValue(struct ListNode *head) {
  // variables
  int dec = 0;
  int multiplier = 1;
  node *it = head;
  it = it->next; // cuz multiplier is 1, i.e for first binary digit

  // counting the number of digits
  while (it != nullptr) {
    multiplier *= 2;
    it = it->next;
  }

  it = head;
  while (it != nullptr) {
    dec += multiplier * it->val;
    multiplier /= 2;
    it = it->next;
  }
  return dec;
}
