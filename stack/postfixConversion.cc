#include <iostream>
using namespace std;

class prefixToPostFix {
private:
  char stack[101];
  int size;
  int top = -1;

public:
  prefixToPostFix();
  string convert(string);
  int checkParams(char c);
  ~prefixToPostFix();
};

prefixToPostFix::prefixToPostFix() {}

prefixToPostFix::~prefixToPostFix() {}
int prefixToPostFix::checkParams(char c) {
  switch (c) {
  case '(':
    return 0;
  case '+':
    return 1;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 2;
  case '%':
    return 2;
  default:
    return -1;
  }
};
string prefixToPostFix::convert(string s) {
  int l = s.length();
  int i = 0;
  string ans = "";
  while (i < l) {
    if (s[i] >= 'a' && s[i] <= 'z')
      ans += s[i];
    else {
      if (top == -1)
        stack[++top] = s[i];
      else {
        if (s[i] == '(') {
          stack[++top] = s[i];
        } else if (s[i] == ')') {
          while (stack[top] != '(')
            ans += stack[top--];
          top--;
        } else if (checkParams(s[i]) > checkParams(stack[top]))
          stack[++top] = s[i];
        else {
          while (top != -1 && (checkParams(stack[top]) >= checkParams(s[i])))
            ans += stack[top--];
          stack[++top] = s[i];
        }
      }
    }
    i++;
  }
  while (top != -1)
    ans += stack[top--];
  return ans;
};

int main() {
  string s = "a+(b/c-d)*(e%f)";
  prefixToPostFix solution;
  cout << solution.convert(s);
  return 0;
}
