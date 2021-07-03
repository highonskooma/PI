#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//STRUCTS
typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;


//METHODS
LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

void listaStack (Stack *s) {
    LInt h = (*s);
    for(h;h!=NULL;h=h->prox){
        printf("valor: %d\n",h->valor);
    }
}

void initStack (Stack *s) {
    LInt h = malloc(sizeof(struct slist));
    h->valor = 0;
    h->prox = NULL;
    (*s) = h;
}

void push (Stack *s, int x) {
    LInt temp = *s; //memorizar o primeiro elemento da list
    LInt h = malloc(sizeof(struct slist)); //criar um novo nodo
    h->valor = x; //mudar o valor
    h->prox = temp; //apontar o novo elemento para antiga cabeça da list
    *s = h;//cabeça da list passa a ser o novo nodo
}

int pop (Stack *s, int *x) {
    LInt h = *s;
    LInt next = h->prox;;
    while(next->prox != NULL) {
        if ( &(next->valor) == x ) {
            h->prox = next->prox;
        }
        h = next;
        next = next->prox;
    }
}

void listaQueue(Queue *q) {
    LInt h = q->inicio;
    for(h;h!=NULL;h=h->prox){
        printf("valor: %d\n",h->valor);
    }
}

void initQueue (Queue *q) {
    LInt h = malloc(sizeof(struct slist));
    h->valor = 0;
    h->prox = NULL;
    q->inicio = h;
    q->fim = h;
}

int enqueue (Queue *q, int x) {
    LInt h = malloc(sizeof(struct slist));
    h->prox = NULL;
    h->valor = x;
    (q->fim)->prox = h;
    (q->fim) = h;
}

int dequeue (Queue *q) { (q->inicio) = (q->inicio)->prox; }

int main() {
    printf ("\n_____________ Teste 1 _____________\n\n");
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    int* p = &((s->prox)->valor);
    pop(&s,p);
    listaStack(&s);
    printf ("\n_____________ Teste 2 _____________\n\n");
    Queue *q;
    initQueue(q);
    enqueue(q,1);
    enqueue(q,2);
    dequeue(q);
    //printf("inicio: %d\n",(q->inicio)->valor);
    //printf("fim: %d\n",(q->fim)->valor);
    listaQueue(q);

    return 0;
}