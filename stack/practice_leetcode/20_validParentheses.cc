#include <iostream>
using namespace std;
class Solution {
public:
  int push(int arr[], int value, int &top, int MAX) {
    if (top >= MAX) {
      cout << "Stack Overflow";
      return -1;
    }
    arr[++(top)] = value;
    return top;
  }

  int pop(int arr[], int &top) {
    if (top < 0) {
      cout << "Nothing To Pop";
      return -1;
    }
    return arr[top--];
  }

  int checkParenthesis(char paren) {
    switch (paren) {
    case '(':
      return 1;
    case '{':
      return 2;
    case '[':
      return 3;
    case ')':
      return -1;
    case '}':
      return -2;
    case ']':
      return -3;
    }
    return -1;
  }

  bool isValid(string s) {
    int MAX = 10000;
    int top = -1;
    int st[MAX];
    string testPar = s;
    int sLen = testPar.size();
    int flag = 0;
    for (int i = 0; i < sLen; i++) {
      int parenValue = checkParenthesis(testPar[i]);
      if (top < 0) {
        if (parenValue < 0) {
          flag = 1;
          break;
        }
        push(st, parenValue, top, MAX);
      }

      else if (parenValue > 0)
        push(st, parenValue, top, MAX);

      else if (parenValue < 0 && !(parenValue + st[top]))
        pop(st, top);

      else {
        flag = 1;
        break;
      }
    }
    if (top == -1 && !flag)
      return true;
    else
      return false;
  }
};

int main() { return 0; }
