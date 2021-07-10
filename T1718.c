#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 10

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

void imprime (LInt l) {
    LInt h = l;
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

//1.
int retiraNeg (int v[], int N) {
    int i,j;
    for (i=0;i<N;i++){
        if (v[i]<0) {
            for (j=i;j<N;j++) {
                v[j] = v[j+1];
            }
            --N;
        }
    }
    return N;
}

//2.
int difsAUX (char s[], int i, int j) {
    int k;
    for(i;i<j;i++) {
        k=i+1;
        while (k<j) {
            //printf("%c <-> %c\n",s[i],s[k]);
            if (s[i]==s[k]) {return 0;} //false
            else {k++;}
        }
    }
    return 1; //true
}

int difConseq (char s[],int N) {
    int counter=0,i,j;
    int max=0;
    for (i=0;i<N;i++) {
        j=i+1;
        counter=0;
        while (difsAUX(s,i,j)) {
            counter++;
            j++;
        }
        //printf("c: %d m: %d\n",counter,max);
        if (counter>max) {max=counter;}
    }
    return max;
}

//3.
int maximo (LInt l) {
    int max = 0;
    while (l) {
        if (l->valor > max) {max=l->valor;}
        l = l->prox;
    }
    return max;
}

//4.
int removeAll (LInt *l, int x) {
    LInt h;
    if ((*l)->valor == x) {
        h = (*l)->prox;
        free(*l);
        *l = h;
        removeAll(l,x);  //a chamada recursiva verifica se o primeiro
                        //elemento é igual a x novamente, já que o ciclo
                       //vai verificar os restantes elementos 
    }
    while ((*l)->prox) {
        h = (*l)->prox;
        if (h->valor == x) {
            (*l)->prox = h->prox;
        }
        else {l = &((*l)->prox);}
    }
}

//5.
LInt arrayToList (int v[], int N) {
    LInt node=NULL;
    if (N>0) {
        node = malloc(sizeof(struct lligada));
        node->valor = *v;
        node->prox = arrayToList(v+1,N-1);
    }
    return node;
}

LInt arrayToList2 (int v[], int N) {
    int i=0;
    LInt prev,node;
    for (N;N>0;N--) {
        node = malloc(sizeof(struct lligada));
        node->valor = v[N-1];
        node->prox = prev;
        prev = node;
    }
    return node;
}

//1.
int isMinHeap (ABin a) {
    int res=0;
    if (a->esq) {
        if ((a->esq)->valor < a->valor) {return 1;}
        else {res += isMinHeap(a->esq);}
    }
    if (a->dir) {
        if ((a->dir)->valor < a->valor) {return 1;}
        else {res += isMinHeap(a->dir);}
    }
    return res;
}

//2.
int maxHeap (ABin a) {
    int maxE=0,maxD=0;
    if (!a->esq && !a->dir) {
        return a->valor;
    }
    if (a->esq) {
        maxE = maxHeap(a->esq);
    }
    if (a->dir) {
        maxD = maxHeap(a->dir);
    }
    return ( maxE>maxD ? maxE : maxD );
}

//3.
ABin shiftLeft (ABin a) {
    if (a->dir) {
        ABin cpyD = a->dir;
        a->dir = (a->dir)->esq; 
        cpyD->esq = a;
        return cpyD;
    }
    else return a;
}

ABin shiftRight (ABin a) {
    if (a->esq) {
        ABin copy = a->esq;
        a->esq = (a->esq)->dir;
        copy->dir = a;
        return copy;
    }
}

void removeMin (ABin a) {
    if (a->esq && a->dir) {
    int e = (a->esq)->valor;
    int d = (a->dir)->valor;
    if (e>d) {
        ABin copy = a->esq;
        a = a->dir;
        a->esq = copy;
        removeMin(a->dir);        
    }
    else {
        ABin copy = a->dir;
        a = a->esq;
        a->dir = copy;
        removeMin(a->esq);
    }
    }
}

void addToMinHeap (ABin *a, int x) {
    if ((*a)->esq && (*a)->dir) {
        int esq = ((*a)->esq)->valor;
        int dir = ((*a)->dir)->valor;
        if (esq < x) {
            addToMinHeap((*a)->esq,x);
        }
        if (dir < x) {
            addToMinHeap((*a)->dir,x);
        }
    }
}




int main () {
    printf("TESTE 2017/2018 - Parte A\n1. ");
    int N = 5;
    int v[5] = {2,-1,4,-5,2};
    //N = retiraNeg(v,N);
    int i;
    for (i=0;i<N;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    printf("2. ");
    char arr[12] = "mundo cruel\0";
    printf("%d\n",difConseq(arr,11));

    /*LISTA B
    LInt a = malloc(sizeof(struct lligada));
    LInt b = malloc(sizeof(struct lligada));
    LInt c = malloc(sizeof(struct lligada));
    LInt d = malloc(sizeof(struct lligada));
    a->prox = b;
    a->valor = 2;
    b->prox = c;
    b->valor = 1;
    c->prox = d;
    c->valor = 1;
    d->prox = NULL;
    d->valor = 2;
    */
    //printf("3. %d\n",maximo(a));
    
    //printf("4. ");
    //removeAll(&a,2);
    //imprime(a);

    printf("5. ");
    N=5;
    LInt cpy = arrayToList(v,N);
    //LInt cpy = arrayToList2(v,N);
    imprime(cpy);

    printf("TESTE 2017/2018 - Parte B\n1. ");
    ABin a = malloc(sizeof(struct nodo));
    ABin b = malloc(sizeof(struct nodo));
    ABin c = malloc(sizeof(struct nodo));
    ABin d = malloc(sizeof(struct nodo));
    ABin e = malloc(sizeof(struct nodo));
    ABin f = malloc(sizeof(struct nodo));
    ABin g = malloc(sizeof(struct nodo));
    a->valor = 20;a->esq = b;a->dir = c;
    b->valor = 35;b->esq = d;b->dir = e;
    c->valor = 22;c->esq = f;c->dir = g;
    d->valor = 80;d->esq = NULL;d->dir = NULL;
    e->valor = 42;e->esq = NULL;e->dir = NULL;
    f->valor = 23;f->esq = NULL;f->dir = NULL;
    g->valor = 25;g->esq = NULL;g->dir = NULL;
    print2D(a);

    printf("%d\n",isMinHeap(a));

    printf("2. %d\n",maxHeap(a));

    //ABin left = shiftLeft(a);
    //ABin right = shiftRight(a);
    //print2D(right);

    //removeMin(a);
    //print2D(a);

}