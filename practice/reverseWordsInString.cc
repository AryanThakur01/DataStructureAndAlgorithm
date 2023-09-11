#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  void reverse(string &str) {
    int s = 0;
    int e = 0;
    string rev = "";
    for (int i = 0; i < str.length(); i++) {

      if (str[i] == ' ')
        e = i - 1;

      else if (i == str.length() - 1)
        e = i;

      while (e > s) {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        e--, s++;
      }

      if (str[i] == ' ') {
        s = i + 1;
        e = s;
      }
    }
  }
};

int main() {
  string s;
  cout << "Enter The string: ";
  getline(cin, s);

  Solution sol;

  sol.reverse(s);
  cout << s;

  return 0;
}
