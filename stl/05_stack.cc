#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<string> s;

  s.push("Hello");
  s.push("World");
  s.push("-2023");

  cout << "Top Element: " << s.top() << endl;

  s.pop();
  cout << "Top Element: " << s.top() << endl;

  cout << "Size Of Stack: " << s.size() << endl;
  cout << "Stack Is Empty?: " << s.empty() << endl;

  return 0;
}
