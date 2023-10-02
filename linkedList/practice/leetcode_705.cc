#include <iostream>

using namespace std;

class MyHashSet {
private:
  struct Node {
    int key;
    Node *next;
    Node(int k) : key(k), next(nullptr) {}
  };

  Node *head = nullptr;

public:
  MyHashSet() {}

  void add(int key) {
    if (!contains(key)) {
      Node *newNode = new Node(key);
      newNode->next = head;
      head = newNode;
    }
  }

  void remove(int key) {
    if (head == nullptr)
      return;

    if (head->key == key) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *current = head;
    while (current->next != nullptr) {
      if (current->next->key == key) {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        return;
      }
      current = current->next;
    }
  }

  bool contains(int key) {
    Node *current = head;
    while (current != nullptr) {
      if (current->key == key)
        return true;
      current = current->next;
    }
    return false;
  }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() { return 0; }
