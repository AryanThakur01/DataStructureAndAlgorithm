// Coding Ninjas: Search In Rotated Sorted Array
// Link: https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0
#include <iostream>
#include <vector>

using namespace std;

int getPivotElement(vector<int> & arr, int size){
  int s = 0;
  int e = size-1;

  int mid = s + (e-s)/2;
  while(s<e){
    if(arr[0] <= arr[mid])
      s = mid+1;

    else
      e = mid;

    mid = s+(e-s)/2;
  }
  return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key){
  int mid = s + (e-s)/2;

  while(s<=e){
    if(arr[mid] == key)
      return mid;
    else if(arr[mid] < key)
      s = mid + 1;
    else 
      e = mid - 1;
    mid = s + (e-s)/2;
  }
  return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
  int pivot = getPivotElement(arr, n);
  cout << pivot << endl;
  if(k> arr[0])
    return binarySearch(arr, 0, pivot-1, k);
  else if(k < arr[0])
    return binarySearch(arr, pivot, n-1, k);
  return 0;
}

int main(){
  vector<int> arr = {2, 4, 8, 1};

  int size = arr.size();
  int k = 1;
  int pos = findPosition(arr, size, k);
  cout << pos << "\t" << arr[pos];



  return 0;
}
