#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, string> m; // This is ordered map

  m[1] = "Aryan";
  m[2] = "Thakur";
  m[13] = "Programmer";
  m[5] = "Developer";

  m.insert({11, "Hacked"});

  // Before Erase
  for (auto i : m)
    cout << i.first << " : " << i.second << endl;
  cout << endl;

  m.erase(m.begin());

  // After Erase
  for (auto i : m)
    cout << i.first << " : " << i.second << endl;
  cout << endl;

  cout << "is 5 present?: " << m.count(5) << endl;

  // Insert, Erase, Find, Count has Complexity of O(log n)
  // For unordered map the complexity is O(1)

  auto it = m.find(5);
  cout << (*it).first << " : " << (*it).second;

  return 0;
}
