#include <iostream>
using namespace std;

class infixToPrefix {
private:
  char stack[101];
  int size;
  int top = -1;

public:
  infixToPrefix();
  string convert(string);
  int checkParams(char);
  void reverseString(string &);
  ~infixToPrefix();
};

infixToPrefix::infixToPrefix() {}

infixToPrefix::~infixToPrefix() {}
void infixToPrefix::reverseString(string &str) {
  int s = 0;
  int e = str.length() - 1;
  while (s < e) {
    char temp = str[s];
    str[s] = str[e];
    str[e] = temp;
    s++, e--;
  }
}
int infixToPrefix::checkParams(char c) {
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
string infixToPrefix::convert(string s) {
  reverseString(s);
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
  reverseString(ans);
  return ans;
};

int main() {
  string s = "a+b/c-d*e";
  infixToPrefix solution;
  cout << "String Given: " << s << endl;
  cout << "Prefix Expression: " << solution.convert(s);
  return 0;
}
