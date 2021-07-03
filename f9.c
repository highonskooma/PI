#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define COUNT 10

//STRUCTS
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

//METHODS
ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r;
        a->esq = e; 
        a->dir = d;
    }
    return a;
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

int altura (ABin a) {
    if (a) {
        int h_esq = altura(a->esq);
        int h_dir = altura(a->dir);
        if (h_dir>h_esq) {return h_dir + 1;}
        else {return h_esq + 1;}
    }
}

int nFolhas (ABin a) {
    if (a==NULL){return 0;}
    else if (a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    else {
        return nFolhas(a->esq) + nFolhas(a->dir);
    }
}

int nFolhas_2 (ABin a) {
    int n_dir,n_esq;
    if (a->esq) {
        n_esq = nFolhas(a->esq);
    }
    else if (a->dir){
        n_dir = nFolhas(a->dir);
    }
    return n_esq + n_dir ;
    printf("n_esq: %d\n",n_esq);
    printf("n_dir: %d\n",n_dir);
}

ABin maisEsquerda (ABin a) {
    if(a->esq) {
        maisEsquerda(a->esq);
    }
    else{return a;}
}

ABin maisDireita(ABin a) {
    if(a->dir) {
        maisDireita(a->dir);
    }
    else{return a;}
}

void imprimeNivel (ABin a, int l,int s[]) {
    int i;
    if(a){
        imprimeNivel(a->esq,l-1,s);
        imprimeNivel(a->dir,l-1,s);
    }
    if(l==0){
        s[i] = a->valor;
        i++;
    }
}

//1 true, 0 false.
int procuraE (ABin a, int x) {
    if(a){
        if(a->valor==x){return 1;}
        procuraE(a->esq,x);
        procuraE(a->dir,x);
    }
}

void procura (ABin a, int x) {
    if(a){
        if(a->valor == x){printf("encontrado\n");}
        if(a->valor<x){
            procura(a->dir,x);
        }
        if(a->valor>x){
            procura(a->esq,x);
        }
    }
}

struct nodo *procura2 (ABin a, int x) {
    if(a->valor==x){return a;}
    if(a->dir && (a->valor<x)){procura(a->dir,x);}
    if(a->esq && (a->valor>x)){procura(a->esq,x);}
    return NULL;
}


int main() {

    //BTREE
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
    g->valor = 6;g->esq = NULL;g->dir = NULL;

    printf("\n_____________ BTREE _____________\n\n");
    print2D(a);
    printf("\n\n_____________ Testes _____________\n\n");
    printf("altura: %d\n",altura(a));
    printf("n de folhas: %d\n",nFolhas(a));
    printf("nodo + à esq: %d\n",maisEsquerda(a)->valor);
    printf("nodo + à dir: %d\n",maisDireita(a)->valor);
    int N = 4;
    int s[N];
    int lvl = 2;
    imprimeNivel(a,lvl,s);
    printf("nível %d",lvl);
    printf(": ");
    for(int i=0;i<N;i++){printf("%d ",s[i]);}
    printf("\n");
    int M = 2;
    int res = procuraE(a,M);
    switch (res)
    {
    case 0:
        printf("o elemento %d não está na tree\n",M);
        break;
    
    case 1:
        printf("o elemento %d está na tree\n",M);
        break;
    }
    printf("\n__________ BINARY SEARCH TREE __________\n\n");
    ABin h = malloc(sizeof(struct nodo));
    ABin i = malloc(sizeof(struct nodo));
    a->valor = 6;a->esq = b;a->dir = c;
    b->valor = 2;b->esq = d;b->dir = e;
    c->valor = 8;c->esq = f;c->dir = g;
    d->valor = 1;d->esq = NULL;d->dir = NULL;
    e->valor = 4;e->esq = h;e->dir = i;
    f->valor = 7;f->esq = NULL;f->dir = NULL;
    g->valor = 9;g->esq = NULL;g->dir = NULL;
    h->valor = 3;h->esq = NULL;h->dir = NULL;
    i->valor = 5;i->esq = NULL;i->dir = NULL;
    print2D(a);
    printf("\n\n__________ Testes __________\n\n");
    int n = 5; 
    ABin p = procura2(a,n);
    if(p==NULL){printf("NULL\n");}
    else{printf("yesyesyeyses\n");}
    return 0;
}