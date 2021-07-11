#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define COUNT 10

typedef struct posicao { int x, y; } Posicao;

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

//2. tail e truncAUX fazem a mesma coisa só muda a argumentação
void tail(char* s) {
    for(; *s; s++)
        *s = *(s+1);
}

void truncAUX (char t[], int i) {
    for (i;t[i];i++) {
        t[i]=t[i+1];
    }
}

void truncAUX2 (char t[], int i, int n, int len) {
    while (t[n+i] != ' ' || (i+n)<len) {
        int j=n+i;
        for (j;t[j];j++) {
            t[j] = t[j+1];
        }
        //printf("%s\n",t);
    }
}

void truncW (char t[], int n) {
    int len = strlen(t);
    int i=0,c=0,j=0;
    while(t[i]) {
        if (t[i]==' ') {c=0;i++;}
        else {
            if (c>=n) {tail(t+i);}
            else {i++;c++;}
        }
    }
}

//3.
int imprimePos (Posicao pos[],int N) {
    if (N>0) {
        printf("x: %d y: %d\n",pos->x,pos->y);
        imprimePos(pos+1,N-1);
    }
}

int maisCentral (Posicao pos[], int N) {
    int i=0,res=i;
    float min=100,d,c1,c2;
    while (i<N) {
        //printf("x -> %d\n",(pos+i)->x);
        c1 = ((pos+i)->x)^2;
        c2 = ((pos+i)->y)^2;
        d = sqrt(c1+c2);
        if (d<min) {min=d;res=i;}
        i++;
        printf("d: %f\n",d);
    }
    return res;
}

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

typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e) {
    int space = 0;
    int res = 0;
    int i = 0;
    int flag=0;
    while (*s) {
        //printf("s: %c\n",*s);
        if (*s == ' ' && flag==0) {space++;}
        if (*s == ' ' && flag==1) {break;}
        else {res++;flag=1;}
        s++;
    }
    *e = space;
    return res;
}

int isspace2 (char c) {
    if (c == ' ') return 1;
    else return 0;
}

Palavras words (char *texto) {
    int space=0;
    int length=daPalavra(texto,&space);
    Palavras head=malloc(sizeof(struct celula));
    head->comp = length;
    head->palavra = texto;
    head->prox = NULL;
    Palavras res = head;
    while (*texto) {
        texto = texto+space+length;
        length = daPalavra(texto,&space);
        //printf("length: %d\n",length);
        //printf("space: %d\n",space);
        Palavras pal = malloc(sizeof(struct celula));
        pal->comp = length;
        pal->palavra = texto+space;
        pal->prox = NULL;
        head->prox = pal;
        head = pal;
    }
    return res;
}

Palavras daLinha (Palavras t, int n) {
    int sum=0;
    int res = t;
    while (sum < n) {
        sum += t->comp + 1;
        t = t->prox;
    }
    //Palavras temp = t;
    //t = t->prox;
    //temp->prox = NULL;
    return res;
}



int main () {
    char s[36] = "liberdade, igualdade e fraternidade\0";
    printf("PARTE A\n%s\n",s);
    //truncAUX(s,4);
    truncW(s,4);
    //tail(s+1);
    //printf("2. %c\n",*(s+2));
    printf("2. %s\n",s);

    Posicao *p1 = malloc(sizeof(struct posicao));
    Posicao *p2 = malloc(sizeof(struct posicao));
    Posicao *p3 = malloc(sizeof(struct posicao));
    Posicao *p4 = malloc(sizeof(struct posicao));
    p1->x = 12; p1->y = 4;
    p2->x = 5; p2->y = 7;
    p3->x = -3; p3->y = 10;
    p4->x = -5; p4->y = -5;

    Posicao p[4];
    p[0] = *p1;
    p[1] = *p2;
    p[2] = *p3;
    p[3] = *p4;

    imprimePos(p,4);
    printf("3. %d\n",maisCentral(p,4));


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
    printf("4. \n");
    LInt somas = somasAcL(a);
    imprime(a);
    imprime(somas);

    int e;
    char str[10] = " test one\0";
    char *ptr = &str;
    daPalavra(ptr,&e);
    printf("\nPARTE B\n1. res: %d space: %d\n",daPalavra(ptr,&e),e);

    char texto[203] = "Aqui ao leme sou mais do que eu: Sou um povo que quer o mar que e teu; E mais que o mostrengo, que me a alma teme E roda nas trevas do fim do mundo, Manda a vontade, que me ata ao leme, De El-Rei D. João Segundo!";

    printf("%s\n",texto);
    Palavras pal = words(&texto);

    int i=1;
    /*
    while (pal) {
        printf("pal %d: %s\n",i,pal->palavra);
        printf("length %d: %d\n",i,pal->comp);
        pal = pal->prox;
        i++;
    }
    */
   
    Palavras linha = daLinha(pal,10);
    /*while (linha) {
        printf(":: %s\n",linha->palavra);
        linha=linha->prox;
    */
   

}