// Capacity of the vector doubles every time any element is pushed in the vector
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> v;

  // Initialized with some value
  vector<int> a(5, 1);
  for (int i : a)
    cout << i << "\t";
  cout << endl;

  // Copy Vector
  vector<int> copyVector(a);

  // Capacity Check of the vector
  cout << "Capacity: " << v.capacity() << endl;
  v.push_back(1);
  cout << "Capacity: " << v.capacity() << endl;
  v.push_back(2);
  cout << "Capacity: " << v.capacity() << endl;
  v.push_back(3);
  cout << "Capacity: " << v.capacity() << endl;

  // Size of the vector
  cout << "Size: " << v.size() << endl;

  // Element at a specific index in vector
  cout << "Element at 1: " << v.at(1) << endl;

  // First And Last Element
  cout << "First element: " << v.front() << endl;
  cout << "Last element: " << v.back() << endl;

  // Pop The Elements of the array
  cout << "Array Before Pop: ";
  for (int i : v)
    cout << i << "\t";
  cout << endl;

  v.pop_back();

  cout << "Array After Pop: ";
  for (int i : v)
    cout << i << "\t";
  cout << endl;

  // Clear the vector
  cout << "Size before clearing the array: " << v.size() << endl;
  v.clear();
  cout << "Size before clearing the array: " << v.size() << endl;

  return 0;
}
