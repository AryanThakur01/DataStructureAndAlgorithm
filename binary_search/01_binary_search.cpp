#include<iostream>

using namespace std;

int binarySearch(int arr[], int size, int key){
  int start = 0;
  int end = size - 1;
  int mid = start - (start - end)/2;
  while(start<=end){
    if(arr[mid]>key)
      end = mid - 1;
    else if(arr[mid]<key)
      start = mid + 1;
    else
      return mid;
    mid = start - (start - end)/2;
  }
  return -1;
}

int main(){
  int arr[10] = {1, 2, 5, 6, 7, 10, 55, 121, 123, 333};
  int a = binarySearch(arr, 10, 55);
  if(a != -1){
    cout<< "Index: "<<arr[a] << "\n";
    cout<< "Value: "<<a;
  }
  return 0;
}
