// Painter's Partition Problem
// href: https://www.codingninjas.com/studio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
#include<iostream>
#include<vector>

using namespace std;

bool isPaintingPossible(vector<int> boards, int workers, int size, int testCase){
  int i = 0;
  int sum = 0;
  while(i<size){
    if(boards[i] > testCase) return false;
    sum += boards[i];
    if(sum >testCase){
      if(--workers == 0)
        return false;
      sum = boards[i];
    }
    i++;
  }
  return true;
}

int findLargestMinDistance(vector<int> &boards, int workers){
  int n = boards.size();
  int s = 0;
  int e = 0;
  for (int i = 0; i<n ; i++) e += boards[i];
  int mid = s + (e-s)/2;
  int ans = -1;
  while(s<e){
    if(isPaintingPossible(boards, workers, n, mid)){
      ans = mid;
      e = mid;
    }
    else
      s = mid+1;
    mid = s + (e-s)/2;
  }
  return ans;
}

int main () {
  vector<int> boards = {10, 20, 30, 40};
  int workers = 2;

  int MinimumLargestDist = findLargestMinDistance(boards, workers);
  cout << "The largest distance minimized to is: " << MinimumLargestDist;
  return 0;
}
