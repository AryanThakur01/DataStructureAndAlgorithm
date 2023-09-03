#include <iostream>

using namespace std;

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

void bubbleSort(int arr[], int n){
  for(int i = 0; i < n-1; i++){
    bool swapping = false;
    for(int j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapping = true;
      }
    }
    if(!swapping) return;
  }
}

int main(){
  int n;
  int ar[n];

  cin>>n;
  for(int i = 0; i< n; i++)
    cin >> ar[i];

  bubbleSort(ar, n);

  for(int i = 0; i< n; i++)
    cout  << ar[i] << "\t";

  return 0;
}
