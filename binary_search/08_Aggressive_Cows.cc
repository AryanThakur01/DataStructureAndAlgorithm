#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int> stalls, int k, int size, int testCase){
  int i = 0;
  int s = 0;
  int e = 1;
  k--;
  while(e < size){
    if(stalls[e]-stalls[s] >= testCase){
      s = e;
      e++;
      if(--k == 0)
        break;
    }
    else e++;
  }
  return k == 0 ? true : false; 
}

int aggressiveCows(vector<int> &stalls, int k){
  sort(stalls.begin(), stalls.end());
  int size = stalls.size();
  int s = 0;
  int e = stalls[size - 1] - stalls[0];
  int ans = -1;
  int mid = s + (e-s)/2;
  while(s <= e){
    if(isPossible(stalls, k, size, mid)){
      s = mid+1;
      ans = mid;
    }
    else
      e = mid -1;
    mid = s + (e-s)/2;
  }
  return ans;
}
int main(){
  vector<int> stalls = {0, 3, 4, 7, 10, 9};
  int k = 4;

  cout << aggressiveCows(stalls, k) << endl;

  return 0;
}
