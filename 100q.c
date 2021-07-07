#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 10

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

//3.
void imprime (LInt l) {
    LInt h = l;
    int i=1;
    for(h;h!=NULL;h=h->prox){
        printf("nodo %d: %d\n",i,h->valor);
    }
}

//4.
LInt reverseL (LInt l) {
    LInt cur = l;
    LInt next = l->prox;
    cur->prox = NULL;
    while(next){
        LInt t = next->prox;
        next->prox = cur;
        cur = next;
        next = t;
    }
    return cur;
}

//5.
void insereOrd (LInt l, int x) {
    LInt cur = l;
    for(cur;cur->prox!=NULL;cur=cur->prox){
        if((cur->prox)->valor>x){
            LInt node = malloc(sizeof(struct lligada));
            node->valor = x;
            node->prox = cur->prox;
            cur->prox = node;
            break;
        }
    }
}

//6.
int removeOneOrd (LInt l, int x) {
    LInt cur = l;
    LInt prox = cur->prox;
    while (prox) {
        if (prox->valor == x) {
            if (prox->prox==NULL) {cur->prox=NULL;return 0;}
            else{
                cur->prox = prox->prox;
                return 0;
            }    
        }
        cur = prox;
        prox = prox->prox;
    }
    return 1;
}

//7.
void merge (LInt *r, LInt a, LInt b) {
    while (a || b) {
        if (a->valor > b->valor) {
            (*r)->prox = b;
            (*r) = (*r)->prox;
            b = b->prox;
        }
        if (a->valor < b->valor) {
            (*r)->prox = a;
            (*r) = (*r)->prox;
            a = a->prox;
        }
    }
}

void merge2 (LInt *r, LInt a, LInt b) {
    while (a || b) {
        if (a->valor > b->valor) {
            (*r) = b;
            r = &(b->prox);
            b = b->prox;
        }
        if (a->valor < b->valor) {
            (*r) = a;
            r = &(a->prox);
            a = a->prox;
        }
    }
}

//8.
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    LInt cur = l;
    LInt prox = cur->prox;
    (*mx) = l;
    while (prox) {
        if (prox->valor > x) {
            (*Mx) = prox;
            cur->prox = NULL;
            break;
            
        }
        cur = prox;
        prox = prox->prox; 
    }
}

//10.
int removeAll (LInt l, int x) {
    LInt cur = l;
    LInt prox = cur->prox;
    while(prox){
        if(prox->valor==x && prox->prox==NULL){cur->prox=NULL;}
        if (prox->valor==x && prox->prox!=NULL) {
            cur->prox=prox->prox;
        }
        cur = prox;
        prox=prox->prox;
    }
}

//11.
void removeDups (LInt l) {
    for(l;l->prox!=NULL;l=l->prox){
        LInt cur=l;
        LInt prox=cur->prox;
        while(prox){
            if(prox->valor==l->valor){
                if(prox->prox==NULL){cur->prox=NULL;}
                else{cur->prox = prox->prox;}
            }
            cur = prox;
            prox = prox->prox;
        }
    }
}

//12.
int removeMaior (LInt l) {
    LInt cur = l;
    int max = 0;
    for(cur;cur->prox!=NULL;cur=cur->prox){
        if (cur->valor>max) {max=cur->valor;}
    }
    cur = l;
    LInt prox = cur->prox;
    for(cur;cur->prox!=NULL;cur=prox,prox=prox->prox){
        if (prox->valor==max) {
            if (prox->prox==NULL) {cur->prox=NULL;}
            else {
                cur->prox=prox->prox;
                break;
            }
        }
    }
    return max;
}

//13.
void init (LInt l) {
    LInt cur = l;
    LInt prox = cur->prox;
    while(prox->prox){cur=prox;prox=prox->prox;}
    cur->prox = NULL;
    free(prox);
}

//14.
void appendL (LInt l, int x) {
    LInt cur = l;
    while(cur->prox){cur=cur->prox;}
    LInt node = malloc(sizeof(struct lligada));
    node->valor = x;
    node->prox = NULL;
    cur->prox = node;
}

//15.
void concatL (LInt *a, LInt b) {
    LInt cur = (*a);
    while(cur->prox){cur=cur->prox;}
    cur->prox = b;
}

//17.
LInt cloneRev (LInt l) {
    LInt cur = l;
    LInt prox = l->prox;
    LInt node1 = malloc(sizeof(struct lligada)); //last elem on list
    LInt node2;
    node1->prox = NULL;
    node1->valor = l->valor;
    while (prox) {
        node2 = malloc(sizeof(struct lligada));
        node2->valor = prox->valor;
        node2->prox = node1;
        node1 = node2;
        cur = prox;
        prox = prox->prox;
    }
    return node2;
}

LInt cloneRev2 (LInt l) {
    LInt node1 = NULL;
    while (l) {
        LInt node2 = malloc(sizeof(struct lligada));
        node2->valor = l->valor;
        node2->prox = node1;
        node1 = node2;
        l=l->prox;
    }
    return node1;
}

//18.
int maximo (LInt l) {
    int max=0;
    while(l){
        if(l->valor>max){max=l->valor;}
        l=l->prox;
    }
    return max;
}

//19.
int take (int n, LInt *l) {
    int i=0;
    for((*l);i<n;l = &((*l)->prox),i++){}
    i=0;
    LInt cur = (*l)->prox;
    (*l)->prox = NULL;
    while (cur) {
        LInt t;
        t = cur->prox;
        free(cur);
        cur = t;
        i+=1;
    }
    return i;
}

//20.
LInt drop (int n, LInt *l) {
    int i=0;
    for(;*l && i<n;i++){
        LInt t = (*l)->prox;
        free(*l);
        (*l) = t;
    }
    return (*l);
}

//21.
LInt Nforward (LInt l, int n) {
    for(l;l && n>0;n--){
        l=l->prox;
    }
    return l;
}

//22.
void listToArray (LInt l, int v[], int N) {
    int i=0;
    for(l;l && i<N;i++){
        v[i]=l->valor;
        l=l->prox;
    }
}

//23.
LInt arrayToList (int v[], int N) {
    int i;
    LInt h;
    LInt nodo1 = malloc(sizeof(struct lligada));
    nodo1->valor = v[0];
    nodo1->prox = NULL;
    h = nodo1;
    for(i=1;i<N;i++){
        LInt nodo2 = malloc(sizeof(struct lligada));
        nodo2->valor = v[i];
        nodo2->prox = NULL;
        nodo1->prox = nodo2; 
        nodo1 = nodo2;
    }
    return h;
}

LInt arrayToList2 (int v[], int N) {
    if(N == 0) return NULL;
    LInt nodo = malloc(sizeof(struct lligada));
    nodo->valor = (*v);
    nodo->prox = arrayToList(v + 1, N - 1);
    return nodo;
}

//24.
LInt somasAcL (LInt l) {
    int sum = l->valor;
    LInt node1 = malloc(sizeof(struct lligada));
    node1->valor = sum;
    node1->prox = NULL;
    l=l->prox;
    LInt h = node1;
    for(;l;l=l->prox){
        sum += l->valor;
        LInt node2 = malloc(sizeof(struct lligada));
        node2->valor = sum;
        node2->prox = NULL;
        node1->prox = node2;
        node1 = node2;
    }
    return h;
}

//25.
void remreps (LInt l) {
    LInt cur = l;
    LInt prox = l->prox;
    while(prox){
        if(cur->valor==prox->valor){
            cur->prox = prox->prox;
            free(prox);
            prox = cur->prox;
        }
        else{
            cur=prox;
            prox=prox->prox;
        }
    }
}

//26.
LInt rotateL (LInt l) {
    LInt h = l->prox;
    LInt temp = l;
    while(l->prox){
        l=l->prox;
    }
    l->prox = temp;
    temp->prox = NULL;
    return h;
}

//27.
LInt parte (LInt l) {
    LInt cur = l;
    LInt prox = l->prox;
    if(cur->valor%2){}

}

//ARVORES BINARIAS

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


//28.
int altura (ABin a) {
    if (a) {
        int h_esq = altura(a->esq);
        int h_dir = altura(a->dir);
        if (h_dir>h_esq) {return h_dir + 1;}
        else {return h_esq + 1;}
    }    
}

int altura2 (ABin a) {
    int hd = 1;
    int he = 1;
    if (a) {
        hd += altura(a->dir);
        he += altura(a->esq);
    }
    if (hd>he) return hd;
    else return he;
}

//30.
void mirror (ABin a) {
    if (a) {
        ABin t = a->esq;
        a->esq = a->dir;
        a->dir = t;
        mirror(a->esq);
        mirror(a->dir);
    }
}

//31.
void inorder (ABin a, LInt *l) {
    if (a) {
        inorder(a->esq,l);
        
        while(*l){
            l=&((*l)->prox);    
        }
        
        LInt nodo = malloc(sizeof(struct lligada));
        nodo->valor = a->valor;
        nodo->prox = NULL;
        
        (*l) = nodo;

        inorder(a->dir,l);
    }
}

//32.
void preorder (ABin a) {
    if (a) {
        printf("%d ",a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

//33.
void postorder (ABin a) {
    if (a) {
        postorder(a->esq);
        postorder(a->dir);
        printf("%d ",a->valor);
    }
}

//34.
int depth (ABin a, int x) {
    int res=0,esq=0,dir=0;
    if (a) {
        if (a->valor==x){res++;}
        else {
            esq += depth(a->esq,x);
            dir += depth(a->dir,x);
            if (dir>esq) res=esq+1;
            else res=dir+1;
        }
    }
    return res;
}

//35.
LInt nivelL (ABin a, int n) {
    LInt nodo,esq,dir;
    if (a) {
        if (n==0) {
            LInt nodo = malloc(sizeof(struct lligada));
            nodo->valor = a->valor;
            nodo->prox = NULL;
        }
        else{
            esq = nivelL(a->esq,n-1);
            dir = nivelL(a->dir,n-1);
            LInt cur = esq;
            while(cur->prox){cur=cur->prox;}
            cur->prox = dir;
            return esq;
        }
    }
}

//38.
int nivelV (ABin a, int n, int v[]) {
    int i=0,esq=0,dir=0;
    if (a) {
        if (n==0) {
            while(v[i]){i+=1;}
            v[i] = a->valor;
            printf("valor: %d\n",v[i]);
            return i;
        }
        else {
            esq += nivelV(a->esq,n-1,v);
            dir += nivelV(a->dir,n-1,v+esq);
        }
    }
}
 
//40.
int dumpABin (ABin a, int v[], int N) {
    int i=0;
    if (a) {
        
        i += dumpABin(a->esq,v,N);

        if(i<N){
            v[i] = a->valor;
            return i+1;
        }

        i += dumpABin(a->dir,v,N);
    
    }
}

int main() {
    /*
    LInt a = malloc(sizeof(struct lligada));
    LInt b = malloc(sizeof(struct lligada));
    LInt c = malloc(sizeof(struct lligada));
    LInt d = malloc(sizeof(struct lligada));
    LInt a1 = malloc(sizeof(struct lligada));
    LInt b1 = malloc(sizeof(struct lligada));
    LInt c1 = malloc(sizeof(struct lligada));

    //LISTA A
    a->valor = 0;
    a->prox = b;
    b->valor = 1;
    b->prox = c;
    c->valor = 1;
    c->prox = d;
    d->valor = 2;
    d->prox = a1;

    //LISTA B
    a1->prox = b1;
    a1->valor = 2;
    b1->prox = c1;
    b1->valor = 2;
    c1->prox = NULL;
    c1->valor = 6;
    */
    int i=0;
    //int v[4] = {1,2,3,4};
    
    //LInt r = rotateL(a);

    //for(i=0;i<4;i++){printf("%d ",v[i]);}
    //printf("\n");

    //printf("res: %d\n",res);
    //imprime(r);

    //printf("2do elem do array: %d\n",(*v+1));    
    
    //ABIN a    
    ABin a = malloc(sizeof(struct nodo));
    ABin b = malloc(sizeof(struct nodo));
    ABin c = malloc(sizeof(struct nodo));
    ABin d = malloc(sizeof(struct nodo));
    ABin e = malloc(sizeof(struct nodo));
    ABin f = malloc(sizeof(struct nodo));
    ABin g = malloc(sizeof(struct nodo));
    a->valor = 0;a->esq = b;a->dir = c;
    b->valor = 1;b->esq = d;b->dir = e;
    c->valor = 2;c->esq = f;c->dir = g;
    d->valor = 3;d->esq = NULL;d->dir = NULL;
    e->valor = 4;e->esq = NULL;e->dir = NULL;
    f->valor = 5;f->esq = NULL;f->dir = NULL;
    g->valor = 1;g->esq = NULL;g->dir = NULL;

    print2D(a);

    int v[7];

    int res = dumpABin(a,v,7);

    printf("res: %d\n",res);

    for(i=0;i<7;i++){printf("%d ",v[i]);}
    



    
}