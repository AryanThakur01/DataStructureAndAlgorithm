#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> d;

  // Push an element front or back
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  d.push_front(1);
  d.push_front(2);
  d.push_front(3);
  d.push_front(4);

  for (int i : d)
    cout << i << "\t";
  cout << endl;

  d.pop_back();
  d.pop_front();

  for (int i : d)
    cout << i << "\t";
  cout << endl;

  cout << "Front: " << d.front() << endl;
  cout << "Back: " << d.back() << endl;

  cout << "Is Empty: " << d.empty() << endl;

  d.erase(d.begin(), d.begin() + 1);
  for (int i : d)
    cout << i << "\t";
  cout << endl;

  return 0;
}
