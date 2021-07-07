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

int altura (ABin a) {
    int h_esq = 0;
    int h_dir = 0;
    if (a) {
        h_esq += altura(a->esq);
        h_dir += altura(a->dir);
        if (h_esq >= h_dir) {return h_esq + 1;}
        else {return h_dir + 1;}
    }
}

ABin clone (ABin a) {
    if (a) {
        ABin node = malloc(sizeof(struct nodo));
        node->valor = a->valor;
        node->esq = clone(a->esq);
        node->dir = clone(a->dir);
        return node;
    }
}

void mirror (ABin *a) {
    if (*a) {
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}
//como a lista está a ser cos ntruida de tras para a frente
//temos q inverter o metodo de travessia da arvore (dir,root,esq)
void inorder (ABin a, LInt *l) {
    if (a) {
        inorder(a->dir,l);

        LInt node = malloc(sizeof(struct lligada));
        node->valor = a->valor;
        node->prox = *l;
        *l = node;
        
        inorder(a->esq,l);
    }
}

//como a lista está a ser cos ntruida de tras para a frente
//temos q inverter o metodo de travessia da arvore (dir,esq,root)
void preorder (ABin a,LInt *l) {
    if (a) {
        preorder(a->dir,l);
        preorder(a->esq,l);

        LInt node = malloc(sizeof(struct lligada));
        node->valor = a->valor;
        node->prox = *l;
        *l = node;
    }
}

//como a lista está a ser cos ntruida de tras para a frente
//temos q inverter o metodo de travessia da arvore (root,dir,esq)
void posorder (ABin a, LInt *l) {
    if (a) {
        LInt node = malloc(sizeof(struct lligada));
        node->valor = a->valor;
        node->prox = *l;
        *l = node;

        posorder(a->dir,l);
        posorder(a->esq,l);
    }
}

int depth (ABin a, int x) {
    int n_esq=0,n_dir=0;
    if (a) {
        if (x==a->valor) {return 1;}
        else {
            n_esq += depth(a->esq,x);
            n_dir += depth(a->dir,x);
            if (n_esq >= n_dir) {return 1 + n_dir;}
            else {return 1 + n_esq;}
        }
    }
}

int pruneAB (ABin *a, int l){
	int res=0;
	//ABin root=(*a);
	if((*a)){
	    res+=pruneAB(&((*a)->esq),l-1);
		res+=pruneAB(&((*a)->dir),l-1);
		if(l<=0){
		    free(*a);
		    res++;
		    *a=NULL;
		}
		else{
			l--;
		}
	}
	return res;
}



int main() {
    //abin a
    printf("ABIN A:\n");
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
    print2D(a);

    printf("altura: %d\n",altura(a));
    ABin new = clone(a);

    //mirror(&new);
    //print2D(new);

    LInt l;
    inorder(a,&l);
    printf("inorder(esq,root,dir): ");
    imprime(l);
    LInt r;
    printf("preorder(root,esq,dir): ");
    preorder(a,&r);
    imprime(r);
    LInt t;
    printf("postorder(esq,dir,root): ");
    posorder(a,&t);
    imprime(t);

    int N = 4;
    printf("nivel de %d na tree: %d\n",N,depth(a,N));

    printf("prune: %d\n",pruneAB(a,3));
    print2D(a);
    
}