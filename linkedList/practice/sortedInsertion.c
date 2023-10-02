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

// --------------------- Insertion 😈 ---------------------
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

// --------------------- Deletion 😵 ---------------------
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

// ----------------------- Show something 😏 ---------------------
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
    printf("%d ", it->info);
    it = it->next;
  }
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
    printf("%d ", it->info);
    it = it->next;
  }
  printf(" %d \n", it->info);
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
    printf("%d ", it->info);
    it = it->next;
  }
  printf("NULL\n");
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
    printf("%d ", it->info);
    it = it->next;
  }
  printf("%d\n", it->info);
}
// ---------------------------------------------------------------

int main() {
  node *Lll = NULL;                           // Linear linked list
  node *Cll = NULL, *tail_Cll = NULL;         // Circular linked list
  doublyNode *Dll = NULL;                     // Doubly linked list
  doublyNode *DCll = NULL, *tail_DCll = NULL; // Doubly circular linked list

  int decision = 1;

  // Options for nerds 😎
  printf("Insert\n");
  printf(" 1: Singly linear\n");
  printf(" 2: Singly circular\n");
  printf(" 3: Doubly linear\n");
  printf(" 4: Doubly Circular\n");
  printf("Display\n");
  printf(" 5: Singly linear\n");
  printf(" 6: Singly circular\n");
  printf(" 7: Doubly linear\n");
  printf(" 8: Doubly Circular\n");
  printf("Deletion\n");
  printf(" 9: Singly Linear\n");
  printf("10: Singly Circular\n");
  printf("11: Doubly Linear\n");
  printf("12: Doubly Circular\n");

  // Decision Selector 🙋
  while (decision) {
    int num;
    printf("Siddharth >>");
    scanf("%d", &decision);
    getchar();
    if (decision < 5 && decision > 0 || decision >= 9 && decision <= 12) {
      printf("Input: ");
      scanf("%d", &num);
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
      printf("Invalid Operation\n");
      continue;
    }
  }

  return 0;
}
