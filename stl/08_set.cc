#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> s;

  s.insert(5);
  s.insert(5);
  s.insert(2);
  s.insert(2);
  s.insert(9);
  s.insert(9);
  s.insert(9);
  s.insert(0);
  s.insert(0);

  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;

  set<int>::iterator iter = s.begin();
  iter++;

  s.erase(iter);

  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;

  cout << "5 is in set?: " << s.count(5) << endl;

  set<int>::iterator iter_2 = s.find(5);
  cout << "Value present at iter_2: " << *iter_2 << endl;

  for (auto it = iter_2; it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  return 0;
}
