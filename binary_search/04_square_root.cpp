#include<iostream>

using namespace std;

int floorSqrt(int n)
{
  if(n <= 1) return n;
  int s = 0;
  int e = n;
  int mid = s + (e-s)/2;
  while(s<e){
    if(mid*mid == n) return mid;

    else if(mid*mid < n) s = mid + 1;

    else e = mid;

    mid = s + (e-s)/2;
  }
  return s-1;
}

int main () {
  int n;
  cin >> n;

  int sqrt = floorSqrt(n);
  cout << sqrt << endl;
  
  return 0;
}
