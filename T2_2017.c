#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNT 10
#define MAXc 3

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//1.
void shift (char t[], int j,int N) {
    for(j;j<N;j++){
        t[j]=t[j+1];
    }
}

int limpaEspacos (char t[]) {
    int i,j;
    int len = strlen(t);
    int rem = 0;
    for(i=0;i<len;i++){
        if (t[i]==' '){
            j=i;
            while(t[j]==' '){
                shift(t,j,len);
                rem+=1;
                j+=1;
            }
        }
    }
    return len-rem;
}

//2. 
void transposta (int N, float m [N][N]) {
    int i=0,j=0,k=0;
    float temp;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            temp = m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=temp;
        }
    }
}

void imprime (LInt l) {
    LInt h = l;
    int i=1;
    for(h;h!=NULL;h=h->prox){
        printf("%d ",h->valor);
    }
    printf("\n");
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



LInt cloneL (LInt l) {
    LInt first = malloc(sizeof(struct slist));
    first->valor = l->valor;
    l = l->prox;
    LInt h = first;
    while (l) {
        LInt node = malloc(sizeof(struct slist));
        node->valor = l->valor;
        node->prox = NULL;
        first->prox = node;
        first = node;
        l = l->prox;
    }
    return h;
}

LInt cloneL2 (LInt *l) {
    LInt first = malloc(sizeof(struct slist));
    first->valor = (*l)->valor;
    l = &((*l)->prox);
    LInt h = first;
    while (*l) {
        LInt node = malloc(sizeof(struct slist));
        node->valor = (*l)->valor;
        node->prox = NULL;
        first->prox = node;
        first = node;
        l = &((*l)->prox);
    }
    return h;
}

void removeNode (LInt *l, int n) {
    LInt h = (*l);
    while (h) {
        if (n==1) {
            if (h->prox == NULL) {
                free(h->prox);
                h->prox = NULL;
            }
            else {
                LInt temp = (h->prox);
                h->prox = (h->prox)->prox;
                free(temp);
            }
        }
        h = h->prox;
        n-=1;
    }
}

void removeNode_Recursive (LInt *l, int n) {
    if (n==1) {
        if ((*l)->prox==NULL){
            free((*l)->prox);
            (*l)->prox = NULL;
        }
        else {
            LInt temp = (*l)->prox;
            (*l)->prox = ((*l)->prox)->prox;
            free(temp);
        }
    }
    else{
        removeNode_Recursive(&((*l)->prox),n-1);
    }
}

int nivelV (ABin a, int n, int v[]) {
    int i = 0;
    if (a) {
        if (n==1) {
            *v = a->valor;
            ++i;
        }
        else {
            i += nivelV(a->esq,n-1,v);
            i += nivelV(a->dir,n-1,v+i);
        }
    }
    return i;
}

void removeMaiorA (ABin a) {
    ABin prev = a;
    ABin cur = a;
    while (a->dir) {
        prev = cur;
        cur = a->dir;
        a = a->dir;
    }
    if (cur->esq) {
        prev->dir = cur->esq;
    }
    else {
        prev->dir = NULL;
    }
}

void removeMaiorA_Recursive (ABin a) {
    if ((a->dir)->dir) {
        removeMaiorA_Recursive(a->dir);
    }
    else {
        if ((a->dir)->esq) {
            a->dir = (a->dir)->esq;
        }
        else {
            a->dir = NULL;
        }
    }
}


typedef struct chunk {
    int vs [MAXc];
    struct chunk *prox;
} *CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

void printStack (StackC *s) {
    int i,chunk=2;
    printf("chunk 1: ");
    for(i=0;i<s->sp;i++){
        printf("%d ",(s->valores)->vs[i]);
    }
    printf("\n");
    CList h = s->valores;
    h = h->prox;
    while (h) {
        printf("chunk %d: ",chunk);
        for(i=0;i<MAXc;i++){
            printf("%d ",h->vs[i]);
        }
        printf("\n");
        h = h->prox;
        chunk+=1;
    }
}


int push (StackC *s, int x) {
    if (s->sp==MAXc) {
        CList chunk = malloc(sizeof(struct chunk));
        chunk->vs[0] = x;
        chunk->prox = s->valores;
        s->valores = chunk;
        s->sp = 1;
    }
    else {
        (s->valores)->vs[s->sp] = x;
        s->sp += 1;
    }
    return 0;
}

int pop (StackC *s, int *x) {
    CList val = s->valores;
    if (s->sp == 1) {
        *x = val->vs[0];
        val->vs[0] = '\0';
        (s->valores) = (s->valores)->prox;
        s->sp = MAXc;
        free(val);
    }
    else {
        *x = val->vs[s->sp-1];
        val->vs[s->sp-1] = '\0';
        s->sp -= 1;
    }
    return 0; 
}

int size(StackC s) {
    int res=0;
    StackC *p = &s;
    CList val = p->valores;
    while (val) {
        res+=1;
        val = val->prox;
    } 
    return res;
}

void reverse (StackC *s) {
    CList val = s->valores;
    CList temp, prev;
    while (val) {
        temp = val->prox;
        val->prox = prev;
        prev = val;
        val = temp;
    }
    s->valores = prev;
}


int main () {
    char t[] = "   hello   world   :)";
    printf("PARTE A\n1. %d\n",limpaEspacos(t));
    printf("t: %s\n",t);

    float m1[3] = {1,2,3};
    float m2[3] = {4,5,6};
    float m3[3] = {7,8,9};
    float m[3][3];
    int i,j;
    for(i=0;i<3;i++){
        m[0][i]=m1[i];
    } 
    for(i=0;i<3;i++){
        m[1][i]=m2[i];
    } 
     for(i=0;i<3;i++){
        m[2][i]=m3[i];
    }      
    printf("\n2.");
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%f ",m[i][j]);
        }
    }    
    printf("\n");
    transposta(3,m);  
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%f ",m[i][j]);
        }
    }

    LInt l1 = malloc(sizeof(struct slist));
    LInt l2 = malloc(sizeof(struct slist));
    LInt l3 = malloc(sizeof(struct slist));
    LInt l4 = malloc(sizeof(struct slist));
    l1->valor = 1;
    l1->prox = l2;
    l2->valor = 2;
    l2->prox = l3;
    l3->valor = 3;
    l3->prox = l4;
    l4->valor = 4;
    l4->prox = NULL;

    printf("\n\n3. \n");
    imprime(l1);
    LInt new ;
    new = cloneL2(&l1);
    imprime(new);

    printf("\n4. \n");

    //ABIN a    
    ABin a = malloc(sizeof(struct nodo));
    ABin b = malloc(sizeof(struct nodo));
    ABin c = malloc(sizeof(struct nodo));
    ABin d = malloc(sizeof(struct nodo));
    ABin e = malloc(sizeof(struct nodo));
    ABin f = malloc(sizeof(struct nodo));
    ABin g = malloc(sizeof(struct nodo));
    a->valor = 4;a->esq = b;a->dir = c;
    b->valor = 2;b->esq = d;b->dir = e;
    c->valor = 6;c->esq = f;c->dir = g;
    d->valor = 1;d->esq = NULL;d->dir = NULL;
    e->valor = 3;e->esq = NULL;e->dir = NULL;
    f->valor = 5;f->esq = NULL;f->dir = NULL;
    g->valor = 7;g->esq = NULL;g->dir = NULL;

    print2D(a);
    int v[4];
    nivelV(a,3,v);
    printf("v: ");
    for(i=0;i<4;i++){printf("%d ",v[i]);}
    printf("\n5. \n");

    removeMaiorA_Recursive(a);
    print2D(a);

    printf("PARTE B\n1.\n");
    
    //chunk 1
    CList c1 = malloc(sizeof(struct chunk));
    (c1->vs)[0] = 0;
    (c1->vs)[1] = 1;
    (c1->vs)[2] = 2;

    //chunk 2
    CList c2 = malloc(sizeof(struct chunk));
    (c2->vs)[0] = 3;
    (c2->vs)[1] = 4;
    (c2->vs)[2] = 5;

    c2->prox = c1;

    StackC *stack = malloc(sizeof(struct stackC));
    stack->valores = c2;
    stack->sp = 3;

    push(stack,5);
    push(stack,6);
    push(stack,7);

    int res;
    int *p = &res;
    //pop(stack,p);
    //pop(stack,p);
    //pop(stack,p);
    
    printStack(stack);
    //printf("res: %d\n",res);

    printf("size: %d\n",size(*stack));

    reverse(stack);
    printStack(stack);
}