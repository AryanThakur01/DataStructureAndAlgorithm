#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(3);
  v.push_back(3);
  v.push_back(4);
  v.push_back(7);
  v.push_back(8);

  // Binary Search
  cout << "Binary Search 3: " << binary_search(v.begin(), v.end(), 3) << endl;
  cout << "Lower Bound 3: " << lower_bound(v.begin(), v.end(), 3) - v.begin()
       << endl;
  cout << "Upper Bound 3: " << upper_bound(v.begin(), v.end(), 3) - v.begin()
       << endl;

  cout << endl;

  int a = 3;
  int b = 5;

  // Maximum - Minimum
  cout << "max(3, 5): " << max(a, b) << endl;
  cout << "min(3, 5): " << min(a, b) << endl;
  cout << endl;

  // Swap
  cout << "a: " << a << " b: " << b << endl;
  swap(a, b);
  cout << "a: " << a << " b: " << b << endl;
  cout << endl;

  // String Algorithms
  string s = "abst";
  cout << "Before reversing: " << s << endl;
  reverse(s.begin(), s.end());
  cout << "Before reversing: " << s << endl;
  cout << endl;

  cout << "Array Before Rotating: ";
  for (auto i : v)
    cout << i << " ";
  cout << endl;

  rotate(v.begin(), v.begin() + 3, v.end()); // Rotate

  cout << "Array After Rotating: ";
  for (auto i : v)
    cout << i << " ";
  cout << endl;

  cout << "Array After Sorting: ";

  // Sorting - Based on Intro Sort: Quick Sort + Heap Sort + Insertion Sort
  sort(v.begin(), v.end());

  for (auto i : v)
    cout << i << " ";
  cout << endl;

  return 0;
}
