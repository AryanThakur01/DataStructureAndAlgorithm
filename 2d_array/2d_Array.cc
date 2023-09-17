#include <iomanip>
#include <iostream>

using namespace std;

class MatrixFunctions {
public:
  int find(int mat[][4], int value) {
    // Can Write the linear search function here
    return 0;
  }
};

int main() {
  int row = 3;
  int arr[row][4];
  MatrixFunctions f;
  cout << "Input The matrix in sorted order: " << endl;
  for (int r = 0; r < row; r++)
    for (int c = 0; c < 4; c++)
      cin >> arr[r][c];

  cout << "Displaying The matrix:" << endl;
  int rowSum = 0;
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < 4; c++) {
      cout << setw(4) << arr[r][c];
      rowSum += arr[r][c];
    }
    cout << setw(4) << "|" << rowSum;
    cout << endl;
    rowSum = 0;
  }

  int key;
  cout << "Enter The Key To Search: ";
  cin >> key;
  f.find(arr, key);
  return 0;
}
