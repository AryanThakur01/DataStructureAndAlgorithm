#include <iostream>
using namespace std;

void merge(int[], int, int, int);
void mergeSort(int[], int, int);
int main() {
  int size = 10;
  int arr[] = {-1, 1, 5, 3, 2, 0, 11, 12, 13, -10};
  for (int i = 0; i < 10; i++)
    cout << arr[i] << " ";
  cout << endl;

  mergeSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  return 0;
}

void mergeSort(int arr[], int s, int e) {
  if (s >= e)
    return;
  int mid = s + (e - s) / 2;

  mergeSort(arr, s, mid);
  mergeSort(arr, mid + 1, e);
  merge(arr, s, e, mid);
};

void merge(int arr[], int s, int e, int mid) {
  int s1 = mid - s + 1, s2 = e - mid;
  int arr1[s1], arr2[s2];

  // make the sub arrays
  for (int i = 0; i < s1; i++)
    arr1[i] = arr[s + i];
  for (int i = 0; i < s2; i++)
    arr2[i] = arr[mid + i + 1];

  // Merge the 2 arrays
  int i = 0, j = 0, k = s;
  while (i < s1 && j < s2) {
    if (arr1[i] < arr2[j])
      arr[k++] = arr1[i++];
    else
      arr[k++] = arr2[j++];
  }
  while (i < s1)
    arr[k++] = arr1[i++];
  while (j < s2)
    arr[k++] = arr2[j++];
}
