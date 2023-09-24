#include <iostream>
#include <stack>
#include <string>

using namespace std;

class postfixEval {
public:
  float caculate(string);
  float operate(char, float, float);
};

float postfixEval::operate(char opeator, float val_1, float val_2) {
  switch (opeator) {
  case '+':
    return val_1 + val_2;
  case '-':
    return val_1 - val_2;
  case '*':
    return val_1 * val_2;
  case '/':
    return val_1 / val_2;
  default:
    return -1;
  }
}
float postfixEval::caculate(string s) {
  float ans = 0;
  int len = s.length();
  stack<float> st;
  for (int i = 0; i < len; i++) {
    if (s[i] >= '0' && s[i] <= '9')
      st.push(s[i] - '0');
    else {
      float operand_1 = st.top();
      st.pop();
      float operand_2 = st.top();
      st.pop();
      st.push(operate(s[i], operand_2, operand_1));
    }
  }
  return st.top();
}

int main() {
  string s = "149*+9/";
  postfixEval cal;
  cout << cal.caculate(s);
  return 0;
}
