// Allocate Books
// href: https://www.codingninjas.com/studio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int chapters, int days, vector<int>& time, long long maxTime){
  long long countedMax = 0;
  for (int i = 0; i < chapters; i++) {
    if(time[i] > maxTime) return false;
    countedMax += time[i];
    if(countedMax > maxTime){
      if(!--days)
        return false;
      countedMax = time[i];
    }
  }
  return true;
}

long long ayushGivesNinjatest(int days, int chapters, vector<int> time) 
{
  long long s = 0;
  long long e = 0;
  for (int i = 0; i < chapters; i++) {
    e += time[i];
  }
  long long mid = s + (e-s)/2;
  long long minMax = 0;
  while(s <= e){
    if(isPossible(chapters, days, time, mid)){
      minMax = mid;
      e = mid - 1;
    }
    else{
      s = mid + 1;
    }
    mid = s + (e-s)/2;
  }
  return minMax;
}

int main(){
  int n = 6;
  int days = 3;
  vector<int> time = {30, 20, 10, 40, 5, 45};

  int timePerDay = ayushGivesNinjatest(n, days, time);
  cout << timePerDay;
  return 0;
}
