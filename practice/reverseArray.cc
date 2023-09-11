#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int> &arr, int m) {
  int e = arr.size() - 1;
  int s = m + 1;
  while (s < e)
    swap(arr[s++], arr[e--]);
}

int main() {
  vector<int> arr = {10, 9, 8, 7, 6};
  for (auto i : arr)
    cout << i << " ";
  cout << endl;
  reverseArray(arr, 2);
  for (auto i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}
