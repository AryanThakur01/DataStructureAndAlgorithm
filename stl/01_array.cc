#include <iostream>
#include <array>

using namespace std;

int main(){
  array<int, 5> arr = {1, 3, 4, 5, 6};
  int size = arr.size();

  // Accessing array element using the standard methods
  cout << "Accessing Array elements using the standard method: " << arr[0] << endl;

  cout << "Element At index 2: " << arr.at(1) << endl;
  cout << "Array empty or not: " << arr.empty() << endl;
  cout << "First element: " << arr.front() << endl;
  cout << "Last element: " << arr.back() << endl;
  return 0;
}
