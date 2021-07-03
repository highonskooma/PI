#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COUNT 10


typedef struct llint {
    int valor;
    struct llint *prox;
} NodoL, *LLint;

typedef struct abin {
    int valor;
    struct abin *esq, *dir;
} NodoAB, *ABin;


int sqrtInt (int n) {
    int res = sqrt(n);
    return res;
} 

void reverse (int v[], int N) {
    int i=0,j=N;
    int temp;
    for (i=0;i<=N/2 && i!=j;i++){
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        j--;
    }
}

void imprime (LLint l) {
    LLint h = l;
    int i=1;
    for(h;h!=NULL;h=h->prox){
        printf("%d ",h->valor);
    }
    printf("\n");
}

LLint cloneRev (LLint l) {
    LLint cur = l;
    LLint temp = NULL, n;
    while (cur!=NULL) {
        n = malloc(sizeof(struct llint));
        n->valor = cur->valor;
        n->prox = temp;
        temp = n;
        cur = cur->prox;
    }
    return n;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(ABin root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->dir, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->valor);
  
    // Process left child
    print2DUtil(root->esq, space);
}
  
// Wrapper over print2DUtil()
void print2D(ABin root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

int freeAB (ABin a) {
    int res = 0;
    if (a) {
        freeAB(a->esq);
        freeAB(a->dir);
        free(a);
        res++;
    }
    return res;
}


int main () {
    //1.
    int r = sqrtInt(45);
    printf("1. %d\n",r);
    
    //2.
    int v[5] = {1,2,3,4,5};
    int N = 5;
    reverse(v,3);
    printf("2. ");
    for (int i=0;i<N;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    //3.
    LLint l1 = malloc(sizeof(struct llint));
    LLint l2 = malloc(sizeof(struct llint));
    LLint l3 = malloc(sizeof(struct llint));
    LLint l4 = malloc(sizeof(struct llint));
    l1->valor = 1;
    l1->prox = l2;
    l2->valor = 2;
    l2->prox = l3;
    l3->valor = 3;
    l3->prox = l4;
    l4->valor = 4;
    l4->prox = NULL;
    printf("3. ");
    imprime(l1);
    LLint new = cloneRev(l1);
    printf("   ");
    imprime(new);

    //4.a.    
    ABin a = malloc(sizeof(struct abin));
    ABin b = malloc(sizeof(struct abin));
    ABin c = malloc(sizeof(struct abin));
    ABin d = malloc(sizeof(struct abin));
    ABin e = malloc(sizeof(struct abin));
    ABin f = malloc(sizeof(struct abin));
    ABin g = malloc(sizeof(struct abin));
    a->valor = 0;a->esq = b;a->dir = c;
    b->valor = 1;b->esq = d;b->dir = e;
    c->valor = 2;c->esq = f;c->dir = g;
    d->valor = 3;d->esq = NULL;d->dir = NULL;
    e->valor = 4;e->esq = NULL;e->dir = NULL;
    f->valor = 5;f->esq = NULL;f->dir = NULL;
    g->valor = 6;g->esq = NULL;g->dir = NULL;
    print2D(a);



}