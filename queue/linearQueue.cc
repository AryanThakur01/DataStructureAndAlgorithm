#include <iostream>

using namespace std;

class LinearQueue {
  int size = 10;
  int q[10];
  int front = -1;
  int rear = -1;

public:
  void enqueue(int value) {
    if (rear >= size - 1) {
      cout << "Queue Overflow" << endl;
      return;
    } else if (front == -1) {
      q[++front] = value;
      rear++;
    } else {
      q[++rear] = value;
    }
  }
  int dequeue() {
    if (front == -1) {
      cout << "Queue Underflow" << endl;
      return -1;
    }
    int returnValue = q[front++];
    if (front > rear) {
      front = -1;
      rear = -1;
    }
    return returnValue;
  }
  void displayQueue() {
    if (front == -1)
      return;
    for (int i = front; i <= rear; i++)
      cout << q[i] << " ";
    cout << endl;
  }
};

int main() {
  LinearQueue q;
  q.displayQueue();
  q.enqueue(11);
  q.enqueue(21);
  q.enqueue(24);
  q.displayQueue();
  q.dequeue();
  q.dequeue();
  q.displayQueue();
  q.dequeue();
  q.dequeue();

  return 0;
}
