// Using the double pointers
#include <iostream>

using namespace std;

typedef struct node {
  int info;
  node *next;
} node;

void insertInLL(node **head, node **tail, int value) {
  node *temp = nullptr;
  temp = new node;
  temp->info = value;
  if ((*head) == nullptr) {
    (*head) = temp;
    (*tail) = temp;
  } else {
    temp->next = *head;
    *head = temp;
  }
  (*tail)->next = (*head);
}
void nRev(node **head, node **tail, int k) {
  if (k <= 1)
    return;
  node *s = nullptr;
  node *e = nullptr;
  s = *head;
  e = (*head)->next;
  int counter = 2;
  while (e != *head) {
    if (counter == k) {
      if (s == *head)
        *head = e;
    }
    e = e->next;
    counter++;
  }
}
void displayLL(node *head, node *tail) {
  node *it;
  it = head;
  cout << "|";
  while (it != tail) {
    cout << it->info << "|-->|";
    it = it->next;
  }
  cout << it->info << "|" << endl;
}

int main() {
  node *head = nullptr;
  node *tail = nullptr;
  int choice = 1;
  int index = 0;
  // while (choice) {
  //   int info;
  //   cout << index << ": ";
  //   cin >> info;
  //   insertInLL(&head, &tail, info);
  //   cout << "Enter 0 for exit, 1 to continue: ";
  //   cin >> choice;
  //   index++;
  // }
  insertInLL(&head, &tail, 101);
  insertInLL(&head, &tail, 231);
  insertInLL(&head, &tail, 207);
  insertInLL(&head, &tail, 999);
  nRev(&head, &tail, 3);
  displayLL(head, tail);
  return 0;
}
