#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int st[], int MAX, int *top, int value) {
  if (*top >= MAX)
    return; // stack overflow condition assuming stack never overflows
  st[++(*top)] = value;
}
int pop(int st[], int *top) {
  if (*top == -1)
    return -1; // Makes no sense in the case of assuming stack never overflows
  return st[(*top)--];
}

int strTop(int st[], int top) {
  if (top == -1)
    return -1;
  return st[top];
}

int stringToSum(char str[], int stk[], int *top, int stkMax) {
  int sum = 0;
  int length = strlen(str);
  int toggler = 0;

  int i = 0;
  if (length == 1)
    return atoi(str);

  while (i < length - 1) {
    if (str[i] == ')') {
      if (strTop(stk, *top) == 1)
        toggler = !toggler;
      pop(stk, top);
      i++;
    } else if (str[i] != '(' && str[i + 1] != '(') {
      sum += atoi(&str[i]) * pow(-1, toggler);
      i++;
      while (str[i] >= '0' && str[i] <= '9')
        i++;
    } else {
      if (str[i] == '-') {
        toggler = !toggler;
        push(stk, stkMax, top, 1);
        i += 2;
      } else {
        while (str[i] < '0' || str[i] > '9') {
          if (str[i] == '(')
            push(stk, stkMax, top, 0);
          i++;
        }
      }
    }
  }
  return sum;
}

int main() {
  int top = -1;
  char arr[][100] = {"12+11-(5+7-(9+8)-5)", "-(5+7-(12+11))+55", "555",
                     "1+(1-((9)))"};

  int MAX = 50;
  int st[MAX]; // Assuming maximum depth of the string to be 50
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    printf("%s=%d", arr[i], stringToSum(arr[i], st, &top, MAX));
    printf("\n");
  }
  return 0;
}
