#include <stdlib.h>
#include <string.h>
#include <stdio.h>

  
struct Node {
    int data;
    struct Node* next;
};

typedef struct slist {
  int valor;
  struct slist * prox;
} *LInt;

LInt newLInt (int x, LInt xs) {
  LInt r = malloc (sizeof(struct slist));
  if (r!=NULL) {
    r->valor = x;
    r->prox = xs;
  }
  return r;
}
/*
int sorted (LInt l) {
  int r = 1;
  while (l && r) {
    ...
    l = l->prox;
  }
  return 1;
}
*/





  
// This function prints contents of linked list starting from
// the given node
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}



/*
LInt clone (LInt l) {
  LInt r,a,b;
  r = a = b = NULL;
  while (l) {
    a = newLInt(l->valor,NULL);
    ...
    l = l->prox;
  }
  return r;
}
*/

int main()
{
    struct LInt* head = NULL;
    struct LInt* second = NULL;
    struct LInt* third = NULL;
  
    // allocate 3 nodes in the heap
    head = (struct slist*)malloc(sizeof(struct slist));
    second = (struct slist*)malloc(sizeof(struct slist));
    third = (struct slist*)malloc(sizeof(struct slist));
  
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
  
    second->data = 2; // assign data to second node
    second->next = third;
  
    third->data = 3; // assign data to third node
    third->next = NULL;
  
    printList(head);
  
    return 0;
}