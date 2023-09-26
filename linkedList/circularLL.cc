#include <iostream>

using namespace std;

typedef struct node {
  int info;
  node *next;
} node;

// Class for the circular linked list
class circularLL {
private:
  node *head;
  node *tail;

public:
  circularLL() {
    head = nullptr;
    tail = nullptr;
  }
  void insertStart(int);
  int deleteStart();
  void insertEnd(int);
  int deleteEnd();
  void displayLL();
  ~circularLL();
};

// ------------------- DRIVER FUNCTION -------------------
int main() {
  circularLL numbers;
  numbers.insertStart(100);
  numbers.insertStart(200);
  numbers.insertStart(300);
  numbers.insertStart(400);
  numbers.displayLL();
  numbers.deleteStart();
  numbers.displayLL();
  numbers.insertEnd(500);
  numbers.insertEnd(600);
  numbers.insertEnd(700);
  numbers.displayLL();
  numbers.deleteEnd();
  numbers.deleteEnd();
  numbers.deleteEnd();
  numbers.deleteEnd();
  numbers.displayLL();
  return 0;
}
// -------------------------------------------------------

// -------------------------------------------------------
void circularLL::insertStart(int value) {
  node *temp = nullptr;
  temp = new node; // (node *)malloc(sizeof(node))
  temp->info = value;
  if (head == nullptr) {
    tail = temp;
    head = temp;
    head->next = head;
    return;
  }
  temp->next = head;
  head = temp;
  tail->next = head;
}
int circularLL::deleteStart() {
  if (head == nullptr) {
    cerr << "Linked List Underflow, Nothing to delete";
    return -1;
  }
  int deleted = head->info;
  if (head == head->next) {
    free(head);
    tail = nullptr;
    head = nullptr;
  } else {
    node *temp = nullptr;
    temp = head;
    head = head->next;
    tail->next = head;
    temp->next = nullptr;
    free(temp);
  }
  return deleted;
}
void circularLL::insertEnd(int val) {
  node *temp = nullptr;
  temp = new node; // (node *)malloc(sizeof(node))
  temp->info = val;
  if (tail == nullptr) {
    tail = temp;
    head = temp;
  } else {
    tail->next = temp;
    tail = tail->next;
  }
  tail->next = head;
}
int circularLL::deleteEnd() {
  if (tail == nullptr) {
    cerr << "Empty circular ll";
    return -1;
  }
  int deleted = tail->info;
  if (tail == tail->next) {
    free(tail);
    head = nullptr;
    tail = nullptr;
  } else {
    node *temp;
    temp = head;
    while (temp->next != tail)
      temp = temp->next;
    temp->next = head;
    tail->next = nullptr;
    free(tail);
    tail = temp;
  }
  return deleted;
}
void circularLL::displayLL() {
  if (head == nullptr) {
    cout << "Linked List Empty" << endl;
    return;
  }
  node *it = nullptr;
  it = head;
  cout << "|";
  while (it != tail) {
    cout << it->info << "|-->|";
    it = it->next;
  }
  cout << it->info << "|" << endl;
}
circularLL::~circularLL(){};
// -------------------------------------------------------
