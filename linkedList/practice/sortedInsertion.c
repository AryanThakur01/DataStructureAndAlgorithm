#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  int info;
  struct node *next;
} node;

typedef struct doublyNode {
  int info;
  struct doublyNode *next;
  struct doublyNode *prev;
} doublyNode;

void insert_L(node **, int);           // for linear linked list
void insert_CL(node **, node **, int); // for circular linked list
void insert_DLL(doublyNode **, int);
void insert_DCLL(doublyNode **, doublyNode **, int);

void displayLL(node *);
void displayCLL(node *);
void displayDLL(doublyNode *);
void displayDCLL(doublyNode *);

int main() {
  node *Lll = NULL;                           // Linear linked list
  node *Cll = NULL, *tail_Cll = NULL;         // Circular linked list
  doublyNode *Dll = NULL;                     // Doubly linked list
  doublyNode *DCll = NULL, *tail_DCll = NULL; // Doubly circular linked list

  int decision = 1;
  char optionList[][30] = {
      "0: Exit\n",
      "Insert\n",
      " 1: Singly linear\n",
      " 2: Singly circular\n",
      " 3: Doubly linear\n",
      " 4: Doubly Circular\n",
      " 1234: Auto random insertion\n",
      "Display\n",
      " 5: Singly linear\n",
      " 6: Singly circular\n",
      " 7: Doubly linear\n",
      " 8: Doubly Circular\n",
      " 5678: Display All\n",
  };
  for (int i = 0; i < sizeof(optionList) / 30; i++)
    printf("%s", optionList[i]);
  while (decision) {
    // printf("success ✓\n");
    // system("clear");
    int num;
    printf(":");
    scanf("%d", &decision);
    getchar();
    if (decision < 5 && decision > 0) {
      printf("Input: ");
      scanf("%d", &num);
      printf("Insertion = ✓\n");
    }
    switch (decision) {
    case 0:
      break;
    case 1:
      insert_L(&Lll, num);
      continue;
    case 2:
      insert_CL(&Cll, &tail_Cll, num);
      continue;
    case 3:
      insert_DLL(&Dll, num);
      continue;
    case 4:
      insert_DCLL(&DCll, &tail_DCll, num);
      continue;
    case 1234:
      for (int i = 10; i < 20; i++) {
        int num = (rand() % 10) - (rand() % 10);
        insert_L(&Lll, num);
        insert_CL(&Cll, &tail_Cll, num);
        insert_DLL(&Dll, num);
        insert_DCLL(&DCll, &tail_DCll, num);
      }
      continue;
    case 5:
      displayLL(Lll);
      continue;
    case 6:
      displayCLL(Cll);
      continue;
    case 7:
      displayDLL(Dll);
      continue;
    case 8:
      displayDCLL(DCll);
      continue;
    case 5678:
      displayLL(Lll);
      displayCLL(Cll);
      displayDLL(Dll);
      displayDCLL(DCll);
      continue;
    default:
      printf("**Invalid Operation\n");
      continue;
    }
  }

  return 0;
}

// --------------------- INSERTION FUNCTIONS ---------------------
// Linear Linked List
void insert_L(node **head, int value) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp->info = value;
  if (*head == NULL) {
    temp->next = NULL;
    *head = temp;
  } else if ((*head)->info >= value) {
    temp->next = *head;
    *head = temp;
  } else {
    node *it = NULL;
    it = *head;
    while (it->next != NULL && it->next->info < value)
      it = it->next;
    temp->next = it->next;
    it->next = temp;
  }
};
// Circular Linked List
void insert_CL(node **head, node **tail, int value) {
  node *temp = NULL;
  temp = (node *)malloc(sizeof(node));
  temp->info = value;
  if (*head == NULL) {
    temp->next = temp;
    *head = temp;
    *tail = temp;
    return;
  } else if ((*head)->info > value) {
    temp->next = *head;
    *head = temp;
    (*tail)->next = *head;
  } else {
    node *it = NULL;
    it = *head;
    while (it->next != *head && it->next->info < value)
      it = it->next;
    if (it->next == *head) {
      temp->next = it->next;
      it->next = temp;
      *tail = temp;
    } else {
      temp->next = it->next;
      it->next = temp;
    }
  }
}
void insert_DLL(doublyNode **head, int value) {
  doublyNode *temp = NULL;
  temp = (doublyNode *)malloc(sizeof(doublyNode));
  temp->info = value;
  if (*head == NULL) {
    temp->next = NULL;
    temp->prev = NULL;
    *head = temp;
  } else if ((*head)->info > value) {
    temp->prev = NULL;
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
  } else {
    doublyNode *it = NULL;
    it = *head;
    while (it->next != NULL && it->next->info < value)
      it = it->next;
    temp->next = it->next;
    it->next = temp;
    temp->prev = it;
  }
};
void insert_DCLL(doublyNode **head, doublyNode **tail, int value) {
  doublyNode *temp = NULL;
  temp = (doublyNode *)malloc(sizeof(doublyNode));
  temp->info = value;
  if (*head == NULL) {
    temp->next = temp;
    temp->prev = temp;
    *head = temp;
    *tail = temp;
  } else if ((*head)->info > value) {
    temp->prev = *tail;
    temp->next = *head;
    (*head)->prev = temp;
    (*tail)->next = temp;
    *head = temp;
  } else {
    doublyNode *it = NULL;
    it = *head;
    while (it->next != *head && it->next->info < value)
      it = it->next;
    temp->next = it->next;
    temp->prev = it;
    it->next->prev = temp;
    it->next = temp;
    (*tail) = it->next;
  }
};
// ---------------------------------------------------------------

void displayLL(node *head) {
  node *it = NULL;
  it = head;
  if (head == NULL) {
    printf("LINKED LIST EMPTY\n");
    return;
  }
  printf("Linear Linked List: ");
  while (it != NULL) {
    printf("|%d|-->", it->info);
    it = it->next;
  }
  printf("NULL\n");
}
void displayCLL(node *head) {
  node *it = NULL;
  it = head;
  if (head == NULL) {
    printf("CIRCULAR LINKED LIST EMPTY\n");
    return;
  }
  printf("Circular Linked List: ");
  while (it->next != head) {
    printf("|%d|-->", it->info);
    it = it->next;
  }
  printf("|%d|", it->info);
  printf("\n");
}
void displayDLL(doublyNode *head) {
  doublyNode *it = NULL;
  it = head;
  if (head == NULL) {
    printf("DOUBLY LINKED LIST EMPTY\n");
    return;
  }
  printf("Doubly Linked List: ");
  while (it != NULL) {
    printf("|%d|<==>", it->info);
    it = it->next;
  }
  printf("NULL");
  printf("\n");
}
void displayDCLL(doublyNode *head) {
  doublyNode *it = NULL;
  it = head;
  if (head == NULL) {
    printf("DOUBLY CIRCULAR LINKED LIST EMPTY\n");
    return;
  }
  printf("Doubly Circular Linked List: ");
  while (it->next != head) {
    printf("|%d|<==>", it->info);
    it = it->next;
  }
  printf("|%d|\n", it->info);
}
