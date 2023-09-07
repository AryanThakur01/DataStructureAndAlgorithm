#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int merged[m + n];
    int p1 = 0, p2 = 0;
    for (int i = 0; i < m + n; i++) {
      if (p1 >= m)
        merged[i] = nums2[p2++];
      else if (p2 >= n)
        merged[i] = nums1[p1++];
      else if (nums1[p1] < nums2[p2])
        merged[i] = nums1[p1++];
      else
        merged[i] = nums2[p2++];
    }
    for (int i = 0; i < m + n; i++)
      nums1[i] = merged[i];
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  Solution s;
  s.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
  for (auto i : nums1)
    cout << i << " ";
  return 0;
}
