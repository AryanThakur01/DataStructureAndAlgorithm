#include <iostream>
#include <vector>

using namespace std;

int getPivot (int arr[], int size){
  int s = 0;
  int e = size - 1;

  int mid = s + (e-s)/2;
  while(s<e){
    if(arr[0] <= arr[mid])
      s = mid+1;

    else
      e = mid;

    mid = s + (e-s)/2;
  }

  return s;
}

int main () {
  int arr[] = {28, 18, 8, 7, 6, 5, 4, 3, 1};
  int size = 9;

  int pivot = getPivot(arr, size);
  cout << pivot << endl;

  return 0;
}
