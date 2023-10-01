#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Preparing the model 😉
typedef struct node {
  int info;
  struct node *next;
} node;
typedef struct doublyNode {
  int info;
  struct doublyNode *next;
  struct doublyNode *prev;
} doublyNode;

// Insertion 😈
void insert_L(node **, int);           // for linear linked list
void insert_CL(node **, node **, int); // for circular linked list
void insert_DLL(doublyNode **, int);
void insert_DCLL(doublyNode **, doublyNode **, int);

// Deletion 😵
void delete_L(node **, int);           // for linear linked list
void delete_CL(node **, node **, int); // for linear linked list
void delete_DLL(doublyNode **, int);
void delete_DCLL(doublyNode **, doublyNode **, int);

// Show something 😏
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

  // Options for nerds 😎
  char optionList[][30] = {
      "  -2: Help\n",
      "  -1: Clear\n",
      "   0: Exit\n",
      "Insert\n",
      "   1: Singly linear\n",
      "   2: Singly circular\n",
      "   3: Doubly linear\n",
      "   4: Doubly Circular\n",
      "1234: Auto random insertion\n",
      "Display\n",
      "   5: Singly linear\n",
      "   6: Singly circular\n",
      "   7: Doubly linear\n",
      "   8: Doubly Circular\n",
      "5678: Display All\n",
      "Deletion\n",
      "   9: Singly Linear\n",
      "  10: Singly Circular\n",
      "  11: Doubly Linear\n",
      "  12: Doubly Circular\n",
  };
  for (int i = 0; i < sizeof(optionList) / 30; i++)
    printf("%s", optionList[i]);

  // Decision Selector 🙋
  while (decision) {
    int num;
    printf(":");
    scanf("%d", &decision);
    getchar();
    if (decision < 5 && decision > 0 || decision >= 9 && decision <= 12) {
      printf("Input: ");
      scanf("%d", &num);
    }
    switch (decision) {
    case -2:
      system("clear");
      for (int i = 0; i < sizeof(optionList) / 30; i++)
        printf("%s", optionList[i]);
      continue;
    case -1:
      system("clear");
      printf("%s", optionList[0]);
      continue;
    case 0:
      break;
    case 1:
      insert_L(&Lll, num);
      printf("Insertion = ✓\n");
      continue;
    case 2:
      insert_CL(&Cll, &tail_Cll, num);
      printf("Insertion = ✓\n");
      continue;
    case 3:
      insert_DLL(&Dll, num);
      printf("Insertion = ✓\n");
      continue;
    case 4:
      insert_DCLL(&DCll, &tail_DCll, num);
      printf("Insertion = ✓\n");
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
    case 9:
      delete_L(&Lll, num);
      continue;
    case 10:
      delete_CL(&Cll, &tail_Cll, num);
      continue;
    case 11:
      delete_DLL(&Dll, num);
      continue;
    case 12:
      delete_DCLL(&DCll, &tail_DCll, num);
      continue;
    default:
      printf("**Invalid Operation\n");
      continue;
    }
  }

  return 0;
}

// --------------------- INSERTION FUNCTIONS ---------------------
// Singly Linear Linked List
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

// Singly Circular Linked List
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

// Doubly Linear Linked List
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

// Doubly Circular Linked List
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

// --------------------- DELETION FUNCTIONS ---------------------

// Singly Linear Linked List
void delete_L(node **head, int value) {
  if (*head == NULL) {
    printf("Key Not Found\n");
    return;
  }
  if ((*head)->info == value) {
    node *temp = NULL;
    temp = *head;
    *head = temp->next;
    temp->next = NULL;
    free(temp);
    return;
  }
  node *it = NULL;
  it = *head;
  while (it->next != NULL && it->next->info != value)
    it = it->next;
  if (it->next == NULL) {
    printf("Key Not Present\n");
    return;
  }
  node *temp = NULL;
  temp = it->next;
  it->next = temp->next;
  temp->next = NULL;
  free(temp);
};

// Singly Circular Linked List
void delete_CL(node **head, node **tail, int value) {
  if (*head == NULL) {
    printf("Key Not Found\n");
    return;
  } else if (*head == *tail && (*head)->info == value) {
    free(*head);
    *head = *tail = NULL;
    return;
  } else if ((*head)->info == value) {
    (*tail)->next = (*head)->next;
    (*head)->next = NULL;
    free(*head);
    *head = (*tail)->next;
    return;
  }
  node *it = NULL;
  it = *head;
  while (it->next != *head && it->next->info != value)
    it = it->next;
  if (it->next == *head) {
    printf("Key Not Present\n");
    return;
  } else if (it->next == *tail) {
    *tail = it;
  }
  node *temp = NULL;
  temp = it->next;
  it->next = temp->next;
  temp->next = NULL;
  free(temp);
};

// Doubly Linear Linked List
void delete_DLL(doublyNode **head, int value) {
  if (*head == NULL) {
    printf("Key Not Found\n");
    return;
  }
  doublyNode *it = NULL;
  it = *head;
  while (it->info != value) {
    it = it->next;
    if (it == NULL) {
      printf("Key Not Found\n");
      return;
    }
  }
  if (it == *head)
    *head = it->next;
  if (it->prev != NULL)
    it->prev->next = it->next;
  if (it->next != NULL)
    it->next->prev = it->prev;
  it->next = it->prev = NULL;
  free(it);
};

// Doubly Circular Linked List
void delete_DCLL(doublyNode **head, doublyNode **tail, int value) {
  if (*head == NULL) {
    printf("Key Not Found\n");
    return;
  }
  if (*head == *tail && (*head)->info == value) {
    free(*head);
    *head = NULL;
    *tail = NULL;
    return;
  }
  doublyNode *it = NULL;
  it = *head;
  while (it != *tail && it->info != value)
    it = it->next;

  if (it->info != value) {
    printf("Key Not Found\n");
    return;
  }
  if (it == *head) {
    *head = it->next;
    (*head)->prev = *tail;
    (*tail)->next = *head;
  } else if (it == *tail) {
    *tail = it->prev;
    (*tail)->next = *head;
    (*head)->prev = *tail;
  } else {
    it->prev->next = it->next;
    it->next->prev = it->prev;
  }
  it->next = it->prev = NULL;
  free(it);
};
// ---------------------------------------------------------------

// ----------------------- DISPLAY FUNCTIONS ---------------------

// Singly Linear Linked List
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

// Singly Circular Linked List
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

// Doubly Linear Linked List
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

// Doubly Circular Linked List
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
// ---------------------------------------------------------------
