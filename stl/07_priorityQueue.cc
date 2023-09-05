#include <functional>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  // MAX HEAP
  priority_queue<int> maxi;

  maxi.push(1);
  maxi.push(2);
  maxi.push(5);
  maxi.push(9);

  int n = maxi.size();
  for (int i = 0; i < n; i++) {
    cout << maxi.top() << " ";
    maxi.pop();
  }
  cout << endl;

  // MIN HEAP
  priority_queue<int, vector<int>, greater<int>> mini;

  mini.push(4);
  mini.push(2);
  mini.push(1);
  mini.push(3);

  n = mini.size();
  for (int i = 0; i < n; i++) {
    cout << mini.top() << " ";
    mini.pop();
  }
  cout << endl;

  // Empty As Fuck
  cout << "Is Empty: " << mini.empty() << endl;
  cout << "Is Empty: " << maxi.empty() << endl;

  return 0;
}
