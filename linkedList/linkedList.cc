#include <iostream>

using namespace std;

typedef struct node {
  int info;
  node *next;
} node;

// Operate on the start of the list (insert/delete/display)
class operateStart {
private:
  node *head = nullptr;

public:
  void insertStart(int);
  int deleteStart();
  void displayLL();
};

// Operate at the end of the list (insert/delete/display)
class operateEnd {
private:
  node *head = nullptr;
  node *tail = nullptr;

public:
  void insertAtEnd(int);
  int deleteEnd();
  void displayLL();
};

// --------------- DRIVER FUNCTION ----------------
int main() {
  // insert/delete start
  operateStart ll1;
  ll1.insertStart(101);
  ll1.insertStart(202);
  ll1.insertStart(303);
  ll1.insertStart(404);
  cout << "For Operation From The Start Of LL" << endl;
  ll1.displayLL();
  int del = ll1.deleteStart();
  cout << "DELETED VALUE-------> " << del << endl;
  ll1.displayLL();

  cout << endl << endl;
  // insert/delete end
  operateEnd ll2;
  cout << "For Operation From The End Of LL" << endl;
  ll2.insertAtEnd(111);
  ll2.insertAtEnd(222);
  ll2.insertAtEnd(333);
  ll2.displayLL();
  ll2.deleteEnd();
  ll2.deleteEnd();
  ll2.deleteEnd();
  ll2.displayLL();
  return 0;
}

// --------------- START OPERATION FUNCTIONS ----------------
// Insertion At The Start
void operateStart::insertStart(int value) {
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

// Deletion From The Start
int operateStart::deleteStart() {
  if (head == nullptr) {
    cout << "Nothing to delete" << endl;
    return -1;
  }
  int deleted = head->info;

  node *temp = nullptr;
  temp = new node;
  temp = head;
  head = head->next;
  temp->next = nullptr;
  delete temp;

  return deleted;
}

// Display all the elements of the linked list
void operateStart::displayLL() {
  node *iter = nullptr;
  iter = head;
  while (iter != nullptr) {
    cout << iter->info << " ";
    iter = iter->next;
  }
  cout << endl;
};

// ----------------------------------------------------------

// --------------------- END OPERATION FUNCTIONS ------------------------
// Insertion At The Last
void operateEnd::insertAtEnd(int value) {
  node *temp = nullptr;
  temp = new node;
  temp->info = value;
  temp->next = nullptr;
  if (head == nullptr) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

// Deletion From The End
int operateEnd::deleteEnd() {
  if (tail == nullptr) {
    cout << "Nothing to delete" << endl;
    return -1;
  }

  int deleted = tail->info;
  if (tail == head) {
    free(head);
    head = nullptr;
    tail = nullptr;
    return deleted;
  }
  node *iter;
  iter = head;
  while (iter->next != tail) {
    iter = iter->next;
  }
  iter->next = nullptr;
  free(tail);
  tail = iter;

  return deleted;
}

// Display all the elements of the linked list
void operateEnd::displayLL() {
  node *iter = nullptr;
  iter = head;
  while (iter != nullptr) {
    cout << iter->info << " ";
    iter = iter->next;
  }
  cout << endl;
};
// ----------------------------------------------------------
