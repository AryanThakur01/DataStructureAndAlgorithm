#include <iostream>

using namespace std;

void insertionSort(int ar[], int n){
  for(int i = 1; i < n; i++){
    int temp = ar[i];
    int j = i-1;
    for(j = i-1; j >= 0; j--){
      if(ar[i] < ar[j])
        ar[i] = ar[j];
      else
        break;
    }
    ar[j+1] = temp;
  }
}

int main(){
  int n;
  int ar[n];

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> ar[i];

  insertionSort(ar, n);

  for(int i = 0; i < n; i++)
    cout << ar[i] << "\t";

  return 0;
}
