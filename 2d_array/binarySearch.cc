#include <iomanip>
#include <iostream>

using namespace std;

class MatrixFunctions {
public:
  int find(int mat[][4], int value) {
    int row = 3;
    int col = 4;

    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start <= end) {
      int element = mat[mid / col][mid % col];
      if (element == value)
        return 1;
      else if (element < value)
        start = mid + 1;
      else
        end = mid - 1;

      mid = start + (end - start) / 2;
    }

    return 0;
  }
};

int main() {
  int row = 3;
  int arr[row][4];
  MatrixFunctions f;
  cout << "Input The matrix in sorted order: " << endl;
  int i = 0;
  for (int r = 0; r < row; r++)
    for (int c = 0; c < 4; c++)
      arr[r][c] = i++;
  // cin >> arr[r][c];

  cout << "Displaying The matrix:" << endl;
  int rowSum = 0;
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < 4; c++)
      cout << setw(4) << arr[r][c];
    cout << endl;
  }

  int key;
  cout << "Enter The Key To Search: ";
  cin >> key;
  f.find(arr, key);
  return 0;
}
