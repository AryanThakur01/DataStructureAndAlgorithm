#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int s = 0;
    int e = col - 1;
    int mid = s + (e - s) / 2;

    int i = 0;
    while (i < row) {
      while (s < e) {
        if (matrix[row][mid] == target)
          return true;
        if (matrix[row][mid] > target)
          e = mid;
        else
          s = mid + 1;
        mid = s + (e - s) / 2;
      }
      i++;
    }
    return false;
  }
};

int main() { return 0; }
