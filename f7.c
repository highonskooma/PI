#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

int quantasP (Palavras l) {
    Palavras h = l;
    int res = 0;
    for(h;h!=NULL;h=h->prox){res++;}
    return res;
}

void listaPal (Palavras l) {
    Palavras h = l;
    for(h;h!=NULL;h=h->prox){
        printf("%s %d\n",h->palavra,h->ocorr);
    }
}

char * ultima (Palavras l) {
    Palavras h = l;
    while(h->prox!=NULL){h=h->prox;}
    return h->palavra;
}

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras h = l;
    Palavras first;
    first->ocorr = 1;
    first->palavra = p;
    first->prox = h;
    return first;
}

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras h = l;
    while(h->prox!=NULL){h=h->prox;}
    Palavras last = malloc(sizeof(Palavras));
    last->ocorr = 1;
    last->palavra = p;
    last->prox = NULL;
    h->prox = last;
}

Palavras acrescenta (Palavras l, char *p) {
    Palavras h = l;
    int flag = 0;
    for(h;h->prox!=NULL;h=h->prox){
        if(h->palavra == p) {h->ocorr += 1; flag = 1;}
    }
    if (flag == 0) {
        Palavras last = malloc(sizeof(Palavras));
        last->ocorr = 1;
        last->palavra = p;
        last->prox = NULL;
        h->prox = last;
    }
}

struct celula * maisFreq (Palavras l) {
    Palavras h = l;
    Palavras res;
    int max = 1;
    for(h;h->prox!=NULL;h=h->prox){
        //printf("h->ocorr: %d\n",h->ocorr);
        if(h->ocorr > max) {max = h->ocorr; res = h;}
    }
    //printf("test: %s\n",h->palavra);
    return res;
}

bool notInList(char* s,Palavras h) {
    Palavras n = h;
    for(n;n!=NULL;n=n->prox){
        if (s == n->palavra) {return false;}
    }
    return true;
}

Palavras createList(char* str[],int N){
    Palavras h = malloc(sizeof(Palavras));
    h->ocorr = 1;
    h->palavra = str[0];
    h->prox = NULL;
    Palavras n=h;
    int i = 1;
    for(i=1;i<N;i++){
        if (notInList(str[i],h)) {
            Palavras t = malloc(sizeof(Palavras));
            t->prox = NULL;
            t->ocorr = 1;
            t->palavra = str[i]; 
            n->prox = t;
            n = t;
            t = t->prox;
        }
        else {
            Palavras t = h;
            for(t;t->palavra!=str[i];t=t->prox){}
            t->ocorr += 1;
        }
    }
    return h;
}


int main () {
    Palavras h = malloc(sizeof(Palavras));
    h->ocorr = 1;
    h->palavra = "first";
    h->prox = NULL;
    Palavras dic = h;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    char * test1 [5] = {"a","b","c","a","b"}; 

    printf ("\n_____________ Teste 1 _____________\n\n");

    //Palavras t = malloc(sizeof(Palavras));
    dic = acrescentaFim(dic,"second");
    dic = acrescentaFim(dic,"third");
    dic = acrescenta(dic,"fourth");
    dic = acrescenta(dic,"third");
    listaPal(h);
    printf("nr de palavras dif: %d\n",quantasP(h));
    printf("ultima palavra da list: %s\n",ultima(h));
    printf("palavra mais freq: %s\n",maisFreq(h)->palavra);

    printf ("\n_____________ Teste 2 _____________\n\n");

    h = createList(canto1,44);
    listaPal(h);
    printf("\n");

    return 0;
}
