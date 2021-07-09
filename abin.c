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

ABin newNode (int x) {
    ABin node = malloc(sizeof(struct nodo));
    node->valor = x;
    node->esq = NULL;
    node->dir = NULL;
    return node;
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

 
int iguaisAB (ABin a, ABin b) {
    //printf("a: %d,b: %d\n",a->valor,b->valor);
    if (a && b) {
        if (a->valor == b->valor) {
            return iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
        }
        else {return 0;}
    }
    if (!a && b || a && !b) {return 0;}
    return 1;
}

int dumpAbin (ABin a, int v[], int N) {
    int res=0;
    if (a && N>0) {
        res += dumpAbin(a->esq,v,N-1);
        v[N] = a->valor;
        res += dumpAbin(a->dir,v,N-1);
    }
    return res + 1;
}

int somasAcA (ABin a) {
    int res = 0;
    if (a) {
        res = a->valor;
        res += somasAcA(a->esq) + somasAcA(a->dir);
        a->valor = res;
    }
    return res;
}

ABin somas (ABin a) {
    if (a) {
        a->valor = somasAcA(a);
    }
    return a;
}

int contaFolhas (ABin a) {
    int res=0;
    if (a) {
        if (a->esq || a->dir) {
            res += contaFolhas(a->esq) + contaFolhas(a->dir);
            //printf("%d ",a->valor);
        }
        else {return 1;}
    }
    return res;
}

ABin cloneMirror (ABin a) {
    ABin node=NULL;
    if (a) {
        node = malloc(sizeof(struct nodo));
        node->valor = a->valor;
        node->esq = cloneMirror(a->dir);
        node->dir = cloneMirror(a->esq);
    }
    return node;
}

ABin addOrd (ABin *a, int x) {
    if (!(*a)) {return newNode(x);}
    else {
        if ((*a)->valor > x) {
            (*a)->esq = addOrd(&(*a)->esq,x);
        }
        if ((*a)->valor < x) {
            (*a)->dir = addOrd(&(*a)->dir,x);
        }
    }
    return *a;
}

ABin insert(struct nodo *root, int val)
{
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if(root == NULL)
        return newNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if(root->valor < val)
        root->dir = insert(root->dir,val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root->valor > val)
        root->esq = insert(root->esq,val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

int lookUpAB (ABin a, int x) {
    int res=0,flag=0;
    if (a && flag==0) {
        if (a->valor > x) {
            res += lookUpAB(a->esq,x);
            return 1;
        }
        if (a->valor < x) {
            res += lookUpAB(a->dir,x);
            return 1;
        }
        if (a->valor == x) {res++;flag=1;}
    }
}


int depthOrd (ABin a, int x) {
    int i=0,j=0;
    while(a && !i)
    {
        if(a->valor>x)
            a=a->esq;
        else if(a->valor<x)
             a=a->dir;
        else i=1;
        ++j;
    }
    if(!i) j=-1;
    return j;
}

int maiorAB (ABin a) {
    if (a->dir) { maiorAB(a->dir); }
    else { return a->valor; }
}

void removeMaiorAB (ABin a) {
    if (a->dir) {
        if ((a->dir)->dir) { removeMaiorAB(a->dir); }
        else { 
            free(a->dir);
            (a->dir) = NULL;
        }
    }
}

int quantosMaioresAB (ABin a, int x) {
    int res = 0;
    if (a) {
        if (a->valor > x) {
            res += quantosMaioresAB(a->esq,x);
            res += quantosMaioresAB(a->dir,x);
            printf("res %d\n",res);
            
        }
        if (a->valor <= x) {quantosMaioresAB(a->dir,x);}
        return 1;
    }
}

int quantosMaioresAB2 (ABin a, int x) {
    if (a) {
        if (a->valor > x) {
            return  1 + quantosMaioresAB2(a->esq,x) + quantosMaioresAB2(a->dir,x);
            
        }
        else { quantosMaioresAB2(a->dir,x);}
        
    } else{return 0;}
}


void listToBtree (LInt l, ABin *a) {
    while (l) {
        addOrd(a,l->valor);
        l = l->prox;
    }
}

int isBST_AUX (ABin a) {
    if (!a) return 1;
    else {
        if ((a->esq)->valor > a->valor) {return 0;}
        if ((a->dir)->valor < a->valor) {return 0;}
        return isBST_AUX(a->esq) && isBST_AUX(a->dir);
    }
}

int isBST (ABin a) {
    int esq=0,dir=0;
    if (!a) return 1;
    else {
        esq = isBST(a->esq) && isBST_AUX(a->esq);
        dir = isBST(a->dir) && isBST_AUX(a->dir);
        return esq && dir;
    }
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
    a->valor = 7;a->esq = b;a->dir = c;
    b->valor = 3;b->esq = d;b->dir = e;
    c->valor = 11;c->esq = f;c->dir = g;
    d->valor = 1;d->esq = NULL;d->dir = NULL;
    e->valor = 5;e->esq = NULL;e->dir = NULL;
    f->valor = 9;f->esq = NULL;f->dir = NULL;
    g->valor = 13;g->esq = NULL;g->dir = NULL;
    print2D(a);

    printf("altura: %d\n",altura(a));
    //ABin new = clone(a);

    //mirror(&new);
    //print2D(new);
/*
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
*/
    //printf("prune: %d\n",pruneAB(&a,2));
    //print2D(a);

    //new->valor = 9;
    //print2D(new);
    //printf("iguais: %d",iguaisAB(a,new));

/*
    int v[7];
    int i;
    dumpAbin(a,v,7);
    for (i=0;i<7;i++){
        printf("%d ",v[i]);
    }
*/
    //somas(a);
    //print2D(a);

    printf("nr de folhas: %d\n",contaFolhas(a));

    //ABin mirror = cloneMirror(a);
    //print2D(mirror);

    //ABin bst = addOrd(&a,4);
    //print2D(bst);

    //printf("lookUp: %d \n",lookUpAB(bst,9));

    //printf("depth: %d \n",depthOrd(bst,9));

    //printf("maior: %d \n",maiorAB(bst));

    //removeMaiorAB(bst);
    //print2D(bst);

    //int N=3;
    //printf("maiores que %d: %d\n",N,quantosMaioresAB2(bst,N));


    LInt a1 = malloc(sizeof(struct lligada));
    LInt b1 = malloc(sizeof(struct lligada));
    LInt c1 = malloc(sizeof(struct lligada));


    //LISTA B
    a1->prox = b1;
    a1->valor = 2;
    b1->prox = c1;
    b1->valor = 6;
    c1->prox = NULL;
    c1->valor = 8;

    
    //int v[10];

    //listToBtree2(a1,&a);
    //print2D(a);

    printf("%d\n",isBST(a));

}
