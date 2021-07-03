#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int contavogais(char *s) {
    int c = 0;
    int i = 0;
    int low_vowel , upper_vowel;
    for(i=0;s[i]!='\0';i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
        s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            c++;
        }
    }
    return c;
}

int removevogais(char *s) {
    int i;
    int j=0;
    char c = 'f';
    int l = strlen(s);
    char temp[l];
    int res=0;
    for(i=0;i<l;i++){
        if(s[i]==c){res++;}
        else{temp[j]=s[i];j++;}
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
        s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            c=s[i];
        }
    }
    j=0;
    for(i=0;i<(l-res);i++){
        s[i]=temp[j];
        j++;
    }
    s[i]='\0';
    return res;
}

int ordenado (int v[], int N) {
    int i;
    int last=v[0];
    for(i=1;i<N;i++){
        if(last>v[i]){return 0;}
        last=v[i];
    }
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while(a[i]){
        if(a[i]<b[j]){
            r[k]=a[i];
            k++;i++;
        }
        else{
            r[k]=b[j];
            k++;j++;
        }
    }
    if(i>j){
        while(j<nb){
            r[k]=b[j];
            k++;
            j++;
        }
    }
    else{
        while(i<na){
            r[k]=a[i];
            k++;
            i++;
        }
    }
}

int hash(char s[],int N){
    int c=0;
    for(int i = 0;i<N;i++) {
        c += s[i] * (i+1);
        //printf("%d * %d\n",s[i],i+1);
    }
    return c;
}

int hash2(char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}

int hash3(char s[],int N){
    int c=0;
    for(int i = 0;i<N;i++) {
        c += s[i] ;
        //printf("%d * %d\n",s[i],i+1);
    }
    return c;
}

int main() {
    char s[6] = "dababy";
    char* p = s; 
    int r = contavogais(p);

    char t[38] = "Estaa e umaa string coom duuuplicadoos";
    //printf("%s\n",t);
    p=t;
    int q = removevogais(p);
    //printf("%d\n",q);
    //printf("%s\n",t);

    /*
    static int N=5;
    int v[5] = {1,2,6,4,5};
    for(int i=0;i<N;i++){printf("%d ",v[i]);}
    printf("\n");
    if (ordenado(v,5)) {printf("está ordenado\n");}
    else{printf("não está ordenado\n");}
    */

   /*
    int v1[5] = {1,3,4,6,7};
    int v2[5] = {2,5,8,9,10};
    int v3[10];
    merge(v1,5,v2,5,v3);
    for(int i=0;i<10;i++){printf("%d ",v3[i]);}
    printf("\n");
    */

    char pf[5] = "aaauz";
    printf("resultado: %d\n",hash3(pf,5));

    //char teste[5] = "aaauz";
    //printf("hash: %d\n",hash2(teste));


    return 0;
}