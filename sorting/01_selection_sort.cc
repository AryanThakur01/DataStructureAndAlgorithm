#include <iostream>

using namespace std;

inline void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

void selectionSort(int ar[], int n){
  for(int i = 0; i < n-1; i++){
    int min = i;
    for(int j = i+1; j < n; j++)
      if(ar[j] < ar[min]) min = j;
    swap(ar[min], ar[i]);
  }
}

int main(){
  int n;
  int ar[n];

  cin >> n;
  for(int i = 0; i<n; i++)
    cin >> ar[i];

  selectionSort(ar, n);

  for(int i = 0; i<n; i++)
    cout << ar[i] << "\t";
  return 0;
}
