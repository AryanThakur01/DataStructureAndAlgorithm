#include <iostream>
#include <utility>
using namespace std;

typedef struct node {
  int data;
  node *left;
  node *right;
  node() : data(0), left(nullptr), right(nullptr){};
  node(int val) : data(val), left(nullptr), right(nullptr){};
  node(int val, node *l, node *r) : data(val), left(l), right(r){};
} node;

// ----------------------------- HELPER FUNCTIONS -----------------------------
void heapify(int arr[], int i, int n);
void heapSort(int arr[], int n);
void display(int arr[], int n);
// ----------------------------------------------------------------------------

// ============================= DRIVER FUNCTION ==============================
int main() {
  int n = 0;
  cout << "Enter the number of elements: ";
  cin >> n;

  // Input The array
  int arr[n];
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  display(arr, n);

  heapSort(arr, n);

  display(arr, n);
  return 0;
}
// ========================== FUNCTION DEFINITIONS ============================
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, i, n); // arr, i, n
  }
  display(arr, n);
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    n--;
    heapify(arr, 0, n);
    display(arr, n);
  }
}
void heapify(int arr[], int i, int n) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (i >= n / 2 || left >= n)
    return;

  // cout << n << " " << left << " " << right << endl;
  if (right >= n) {
    if (arr[left] < arr[i])
      swap(arr[i], arr[left]);
  } else {
    if (arr[left] < arr[i] && arr[left] <= arr[right])
      swap(arr[i], arr[left]);
    else if (arr[right] < arr[i] && arr[right] <= arr[left])
      swap(arr[i], arr[right]);
  }
  heapify(arr, i + 1, n);
};
void display(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
// ============================================================================
