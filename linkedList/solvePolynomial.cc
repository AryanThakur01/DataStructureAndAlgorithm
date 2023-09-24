#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int coeff;
  int power;
  node *next;
} node;

void insert(int coeff, int power, node **head) {
  node *temp = nullptr;
  temp = (node *)malloc(sizeof(node));
  temp->coeff = coeff;
  temp->power = power;
  if (*head == nullptr) {
    temp->next = nullptr;
    *head = temp;
    return;
  }
  temp->next = *head;
  *head = temp;
}

node *coeffAndPowFinder(char polynomial[]) {
  node *tempPol = nullptr;
  int l1 = strlen(polynomial);
  int i = 0;
  while (i < l1) {
    int power = 1;
    int coeff = 1;
    int num = atoi(&polynomial[i]);
    if (num == 0) {
      if (polynomial[i] == 'x')
        i++;
      else if (polynomial[i] == '+')
        i += 2;
      else if (polynomial[i] == '-') {
        coeff = -1;
        i += 2;
      }
    } else {
      coeff = num;
      i++;
      while (i < l1 && polynomial[i] >= '0' && polynomial[i] <= '9')
        i++;
      if (i == l1)
        power = 0;
      else if (polynomial[i] == 'x')
        i++;
      else
        power = 0;
    }
    if (i < l1 && polynomial[i] == '^') {
      power = atoi(&polynomial[++i]);
      i++;
    }
    // skip all the power digits
    while (i < l1 && polynomial[i] != '+' && polynomial[i] != '-')
      i++;
    insert(coeff, power, &tempPol);
  }
  return tempPol;
}

int main() {
  char p1[] = "3x^4+2x^3-x^2+11";
  char p2[] = "2x^3-x-12";

  // Declaring the the LL for the polynomials to be added
  node *head_p1 = nullptr;
  node *head_p2 = nullptr;
  node *sum = nullptr;

  // Just called the coeffiecient finder for the two given polynomials
  head_p1 = coeffAndPowFinder(p1);
  head_p2 = coeffAndPowFinder(p2);

  // Add The Polynomials
  node *it_1;
  node *it_2;
  it_1 = head_p1;
  it_2 = head_p2;
  while (it_1 != nullptr && it_2 != nullptr) {
    int p1 = it_1->power, p2 = it_2->power;
    if (p1 < p2) {
      insert(it_1->coeff, p1, &sum);
      it_1 = it_1->next;
    } else if (p1 > p2) {
      insert(it_2->coeff, p2, &sum);
      it_2 = it_2->next;
    } else {
      insert(it_1->coeff + it_2->coeff, p1, &sum);
      it_2 = it_2->next;
      it_1 = it_1->next;
    }
  }
  it_1 = (it_1 == nullptr) ? it_2 : it_1;
  while (it_1 != nullptr) {
    insert(it_1->coeff, it_1->power, &sum);
    it_1 = it_1->next;
  }
  free(it_1), free(it_2), free(head_p1), free(head_p2);

  node *iSum;
  iSum = sum;
  while (iSum != nullptr) {
    printf("+(%dx^%d)", iSum->coeff, iSum->power);
    iSum = iSum->next;
  }

  return 0;
}
