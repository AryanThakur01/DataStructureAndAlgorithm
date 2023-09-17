#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int rows = matrix.size();
    int col = matrix[0].size();

    int r_start = 0;
    int r_end = rows;
    int c_start = 0;
    int c_end = col;

    int iter = 0;
    int total = rows * col;

    int sum = 0;

    while (iter < total) {
      for (int i = c_start; iter < total && i < c_end; i++) {
        ans.push_back(matrix[r_start][i]);
        iter++;
      }
      r_start++;
      for (int i = r_start; iter < total && i < r_end; i++) {
        ans.push_back(matrix[i][c_end - 1]);
        iter++;
      }
      c_end--;
      for (int i = c_end - 1; iter < total && i >= c_start; i--) {
        ans.push_back(matrix[r_end - 1][i]);
        iter++;
      }
      r_end--;
      for (int i = r_end - 1; iter < total && i >= r_start; i--) {
        ans.push_back(matrix[i][c_start]);
        iter++;
      }
      c_start++;
    }

    return ans;
  }
};

int main() {
  vector<vector<int>> mat;
  mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution sol;
  vector<int> ans = sol.spiralOrder(mat);
  for (auto i : mat) {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  for (auto i : ans)
    cout << i << " ";
  return 0;
}
