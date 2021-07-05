#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define COUNT 10
#define NUM 3


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

int nodeCount (ABin a) {
    if (a) {
        return 1 + nodeCount(a->esq) + nodeCount(a->dir);
    }
}

//4.a.
int freeAB (ABin a) {
    int res = 1;
    if (a) {
        res += freeAB(a->esq);
        res += freeAB(a->dir);
        free(a);
        return res;
    }
}

//4.b.
int pruneAB (ABin *a, int l) {
    int res = 0;
    if (*a) {
        if (l>0) {
            res += pruneAB(&(*a)->esq,l-1);
            res += pruneAB(&(*a)->dir,l-1);
        }
        else {return freeAB(*a);}
    }
}

int pruneAB_alt (ABin *a, int l) {
    int res = 0;
    if (*a) {
        res += pruneAB(&(*a)->esq,l-1);
        res += pruneAB(&(*a)->dir,l-1);
        if (l<=0) {
            free(*a);
            *a=0;
            ++res;
        }
    }
    return res;
}

int pruneAB_RF (ABin *a, int l) {
    int n;
    if(!(*a)) return 0;
    
    if(l == 0) {
        n = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else n = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir),l - 1);
    
    return n;
}


typedef struct bloco {
    int quantos; // elementos ocupados
    int valores[NUM];
    struct bloco *prox;
} Bloco, *LBloco;


int quantos (LBloco l) {
    int i,res=0;
    while(l!=NULL){
        res += l->quantos;
        l=l->prox;
    }
    return res;
}

void imprimeBloco (LBloco l) {
    int i,c=1;
    while (l) {
        printf("BLOCO %d: ",c);
        for (i=0;i<l->quantos;i++) {
            printf("%d ",l->valores[i]);
        }
        printf("\n");
        l=l->prox;
        c+=1;
    }
}

void compacta_AUX (int a[], int b[], int n) {
    int init = NUM-n;
    printf("init: %d\n",init);
    int i,j=0;
    for(i=init;i<NUM;i++){
        a[i] = b[j];
        j++;
    }
    for(i=0;i<=n;i++){
        b[i]=b[i+1];
    }
    b[i] = '\0';
}

int compacta (LBloco *l) {
    LBloco h = *l;
    while ((*l)->prox) {
        if ((*l)->quantos!=NUM) {
            compacta_AUX((*l)->valores,((*l)->prox)->valores,NUM-((*l)->quantos));
            if ((*l)->quantos + ((*l)->prox)->quantos == NUM) {
                LBloco temp = ((*l)->prox)->prox;
                (*l)->prox = temp;
            }
            (*l)->quantos = NUM;
        }
        imprimeBloco(h);
        printf("\n");
        l = &(*l)->prox;
    }
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
    int free = freeAB(a);
    printf("4.a. %d\n",free);

    //printf("4.b. %d\n",pruneAB_RF(&a,2));

    //6.a.
    LBloco b1 = malloc(sizeof(struct bloco));
    LBloco b2 = malloc(sizeof(struct bloco));
    LBloco b3 = malloc(sizeof(struct bloco));
    int v1[NUM] = {1};
    memcpy(b1->valores,v1, sizeof v1);
    b1->quantos = 1;
    b1->prox = b2;
    int v2[NUM] = {4,5};
    memcpy(b2->valores,v2, sizeof v2);
    b2->quantos = 2;
    b2->prox = b3;
    int v3[NUM] = {6,7,8};
    memcpy(b3->valores,v3, sizeof v3);
    b3->quantos = 3;
    b3->prox = NULL;
    printf("6.a %d\n    ",quantos(b1));

    int t1[NUM] = {1};
    int t2[NUM] = {3,4};
    //compacta_AUX(t1,t2,2);
    int i;
    //for(i=0;i<NUM;i++){printf("%d ",t1[i]);}
    printf("\n    ");
    //for(i=0;i<NUM;i++){printf("%d ",t2[i]);}
    printf("\n");
    imprimeBloco(b1);
    compacta(&b1);
    imprimeBloco(b1);
}