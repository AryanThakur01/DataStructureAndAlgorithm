// 852. Peak Index in a Mountain Array
// href: https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int e = arr.size()-1;
    int s = 0;
    for(int i = 0; i <= e; i++){
      int mid = s + (e-s)/2;
      if(arr[mid]>arr[mid+1] && arr[mid]> arr[mid-1])
        return mid;
      else if(arr[mid] > arr[mid-1])
        s = mid + 1;
      else
        e = mid;
    }
    return s;
  }
};

int main () {
  Solution s;
  vector<int> arr = {1, 3, 4, 6, 7, 9, 8, 6, 4, 3, 1};
  int peak = s.peakIndexInMountainArray(arr);
  cout << peak;
  return 0;
}
