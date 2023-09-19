#include <iostream>

using namespace std;

class MyStack {
private:
  int size;
  int top = -1;
  int *stack = nullptr;

public:
  MyStack(int size) {
    this->size = size;
    stack = new int[size];
    if (stack == nullptr)
      cout << "Memory Allocation Failed";
  }
  void MyStack_push(int value) {
    if (top >= size) {
      cerr << "*** Memory Allocation Failed for value: " << value;
      return;
    }
    stack[++top] = value;
    return;
  }
  int MyStack_pop() {
    if (top == -1) {
      cout << "Nothing to pop";
      return -1;
    }
    return stack[top--];
  }
  int MyStack_top() {
    if (top == -1) {
      cout << "Stack Empty";
      return -1;
    }
    return stack[top];
  }
  bool MyStack_isEmpty() { return (top == -1 ? 1 : 0); }
  ~MyStack() { delete[] stack; }
};

int main() {
  MyStack st(10);
  st.MyStack_push(100);
  return 0;
}
