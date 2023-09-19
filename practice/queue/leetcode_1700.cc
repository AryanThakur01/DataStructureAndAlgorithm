#include <iostream>
#include <vector>

using namespace std;

// Optimized Solution
class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int len = students.size();
    int preferenceCounter[2] = {0};
    for (int i = 0; i < len; i++)
      preferenceCounter[students[i]]++;
    for (int i = 0; i < len; i++) {
      if (preferenceCounter[sandwiches[i]])
        preferenceCounter[sandwiches[i]]--;
      else
        break;
    }
    return preferenceCounter[0] + preferenceCounter[1];
  }
};
// Solution Implementation using queue
// class Solution {
// public:
//   void enqueue(int q[], int &fr, int &re, int value, int size) {
//     if (fr == -1 && re == -1) {
//       q[++re] = value;
//       ++fr;
//       return;
//     }
//     re = (re + 1) % size;
//     q[re] = value;
//   }
//   int dequeue(int q[], int &front, int &rear, int size) {
//     if (front == rear) {
//       int ans = q[rear];
//       rear = -1;
//       front = -1;
//       return ans;
//     }
//     int ans = q[front];
//     front = (front + 1) % size;
//     return ans;
//   }
//   int countStudents(vector<int> &students, vector<int> &sandwiches) {
//     int i = 0;
//     int len = sandwiches.size();
//     int q[len];
//     int front = -1;
//     int rear = -1;
//     int top = 0;
//     while (i < len) {
//       if (sandwiches[top] == students[i])
//         top++;
//       else
//         enqueue(q, front, rear, students[i], len);
//
//       i++;
//     }
//     int end = rear;
//     while (top < len) {
//       if (q[front] == sandwiches[top]) {
//         dequeue(q, front, rear, len);
//         top++;
//         end = rear;
//       } else if (front == end)
//         break;
//       else {
//         int temp = dequeue(q, front, rear, len);
//         enqueue(q, front, rear, temp, len);
//       }
//     }
//     return len - top;
//   }
// };
int main() {
  vector<int> std = {1, 1, 1, 0, 0, 1};
  vector<int> sandwitch = {1, 0, 0, 0, 1, 1};
  Solution sol;
  cout << sol.countStudents(std, sandwitch);
  return 0;
}
