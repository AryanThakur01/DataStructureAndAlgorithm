#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int s = 0;
    int e = 1;
    while (s < n && e < n) {
      if (nums[s] == 0) {
        if (nums[e] != 0) {
          swap(nums[s], nums[e]);
          s++;
        }
        e++;
      } else {
        s++;
        e++;
      }
    }
  }
};

// SnowBall Method
class Solution2 {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int snowBallSize = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        snowBallSize++;
      } else if (snowBallSize > 0) {
        int t = nums[i];
        nums[i] = 0;
        nums[i - snowBallSize] = t;
      }
    }
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution s;
  s.moveZeroes(nums);
  for (auto i : nums)
    cout << i << " ";
  return 0;
}
