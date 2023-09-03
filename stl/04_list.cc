#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l;
  list<int> copyList(l);
  list<int> l2(100, 2);

  l.push_back(1);
  l.push_back(1);
  l.push_front(2);
  l.push_front(2);

  for (int i : l)
    cout << i;
  cout << endl;

  l.erase(l.begin());
  for (int i : l)
    cout << i;
  cout << endl;

  cout << "Size: " << l.size() << endl;
  return 0;
}
