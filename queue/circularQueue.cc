#include <iostream>

using namespace std;

class CircularQueue {
  int size = 5;
  int q[5];
  int front = -1;
  int rear = -1;

public:
  void enqueue(int value) {
    if (front == -1) {
      q[++front] = value;
      rear++;
    } else if ((rear + 1) % size == front)
      cout << "Queue Overflow";
    else {
      rear = (rear + 1) % size;
      q[rear] = value;
    }
  }
  int dequeue() {
    if (front == -1) {
      cout << "Queue Underflow";
      return -1;
    }
    int ret = q[front];
    if (front == rear) {
      rear = -1;
      front = -1;
      return ret;
    }
    front = (front + 1) % size;
    return ret;
  }
  void display() {
    if (front == -1) {
      cout << "Empty Queue";
      return;
    }
    int s = front, e = rear;
    while (s != e) {
      cout << q[s] << " ";
      s = (s + 1) % size;
    }
    cout << q[e] << endl;
  }
};

int main() {
  CircularQueue q;
  q.enqueue(101);
  q.enqueue(101);
  q.display();

  q.dequeue();
  q.display();
  return 0;
}
