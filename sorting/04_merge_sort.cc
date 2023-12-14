#include <iostream>

using namespace std;

// ========================= HELPER FUNCTIONS =========================
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);
// ====================================================================

// ========================= DRIVER FUNCTION ==========================
int main() {
  int n;
  cout << "Enter The Number of Elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter " << n << " space seperated characters: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
// ====================================================================

// --------------------------- Merge Sort -----------------------------
void mergeSort(int arr[], int start, int end) {
  // Base Condition
  if (start >= end)
    return;

  // Reccursive Call
  int mid = start + (end - start) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);

  // Action Function
  merge(arr, start, mid, end);
}
// --------------------------------------------------------------------

// ------------------------ Merge Sub Arrays --------------------------
void merge(int arr[], int start, int mid, int end) {
  int sizeLeft = mid - start + 1, sizeRight = end - mid;
  int left[sizeLeft], right[sizeRight];

  // Make the sub arrays
  for (int i = 0; i < sizeLeft; i++)
    left[i] = arr[i + start];
  for (int i = 0; i < sizeRight; i++)
    right[i] = arr[i + mid + 1];

  // Sorted Merging
  int leftIt = 0, rightIt = 0, mainIt = start;
  while (leftIt < sizeLeft && rightIt < sizeRight) {
    if (left[leftIt] < right[rightIt])
      arr[mainIt++] = left[leftIt++];
    else
      arr[mainIt++] = right[rightIt++];
  }

  // If any elements left unmerged the merge them
  while (leftIt < sizeLeft)
    arr[mainIt++] = left[leftIt++];
  while (rightIt < sizeRight)
    arr[mainIt++] = right[rightIt++];
};
// --------------------------------------------------------------------
