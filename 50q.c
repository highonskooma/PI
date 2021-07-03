#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//1.
void maior() {
    int s = 1;
    int max = 1;
    while (s!=0) {
        printf("Digite um número: ");
        scanf("%d", &s);
        if (s > max) {max = s;}
    }
    printf("O maior elemento é: %d",max);
}

//2.
void media() {
    int d = 1;
    int sum = 0;
    int size = -1;
    while (d!=0) {
        printf("Digite um número: ");
        scanf("%d", &d);
        sum += d;
        size +=1;
    }
    printf("sum: %d\n",sum);
    printf("size: %d\n",size);
    printf("A média da sequencia é: %d",sum/size);
}

//3.
void segmaior() {
    int s = 1;
    int max = 1;
    int second = 1;
    while (s!=0) {
        printf("Digite um número: ");
        scanf("%d", &s);
        if (s > max) {
            second = max;
            max = s;
        }
    }
    printf("O segundo maior elemento é: %d",second);
}

//6.
int qDig (unsigned int n) {
    int res = 0;
    while ( n > 1 ) {
        n = n / 10;
        res+=1;
    }
    return res;
}

//7.
char* strcat2 (char s1[], char s2[]) {
    int l1=strlen(s1); 
    int l2=strlen(s2);
    printf("l1: %d\nl2: %d\n",l1,l2);
    for (int i=0; i<l2 ; i++ , l1++ ) {
        s1[l1] = s2[i];
    }
    s1[l1] = '\0';
    return s1;
}

//8.
char* strcpy2 (char *dest, char source[]) {
    int ld=strlen(dest);
    int ls=strlen(source);
    int i=0,j=0;
    for (i=0; j<ls; i++, j++) {
        dest[i] = source[j];
    }
    dest[i] = '\0';
    return dest;
}

//9.
int strcmp2 (char s1[], char s2[]) {
    int N1 = strlen(s1);
    int N2 = strlen(s2);
    int res=0;
    int i=0;
    while (i<N1 && i<N2) {
        if (s1[i] < s2[i]) {return -1;}
        if (s1[i] > s2[i]) {return 1;}
        i+=1;
    }
    if (N1<N2) {return -1;}
    if (N1>N2) {return 1;}
    if (N1==N2) {return 0;}
}

//10.
char* strstr2 (char s1[],char s2[]) {
    int N1 = strlen(s1);
    int N2 = strlen(s2);
    int i=0;
    int j=0;
    char *p;
    //printf("N2: %d\n",N2);
    for (i=0; i<N1; i++) {
        if (s2[j]=='\0') {return p;}
        if (j==0) {p=&s1[i];}
        if (s1[i]==s2[j]) {j+=1;}
        
    }
    return NULL;
}

//11.
void strrev (char s[]) {
    int size = strlen(s);
    int i = 0;
    int j = size-1;
    char t;
    for (i=0;i<=(size/2)-1;i++,j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

//12.
void strnoV (char s[]) {
    int i=0;
    int j=0;
    int size = strlen(s);
    for(i=0;i<size;i++){
        if(s[i]=='a' ||
        s[i]=='e' ||
        s[i]=='i' ||
        s[i]=='o' ||
        s[i]=='u') {
            for (j=i;j<size;j++){s[j]=s[j+1];}
        }
    }
}

//13. por fazer
void aux (char t[], int i,int size) {
    int j,k=0;
    for(j=i;j<size;j++){
        t[j]=t[j+1];
    }
    t[j]='\0';
}

void truncW (char t[], int n) {
    int i,j,c,k,r = 0;
    int size = strlen(t);
    for(i=0;i<size;i++){ //este ciclo tem q ter controlo de ' ' 
        if(c==n){
            for(j=i;t[j]!=' ';j++){r++;}
            for(k=0;k<r;k++){aux(t,i,size);size--;}
            c=-1;
            r=0;
        }
        c++;
    }
}

//14.
char charMaisFreq (char s[]) {
    int i,j,c = 0;
    int max=0;
    char res;
    int size = strlen(s);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if (i!=j && s[i]==s[j]) {
                c+=1;
            }
        }
        if (c > max) {max = c;res=s[i];}
        c=0;
    }
    return res;
}

//15.
int iguaisConseq (char s[]) {
    int i = 0;
    int c = 1;
    int max = 0;
    int size = strlen(s);
    for(i=0;i<size;i++){
        if(s[i]==s[i+1]){c++;}
        else{
            if(c>max){max=c;}
            c=1;
        }
    }
    return max;
}

//16.
int dif_aux (char s[], char ch,int i,int j) {
    int k;
    int cont = 0;
    for(k=i;k<j;k++){
        if(s[k]==ch){cont++;}
    }
    if(cont>1){return 1;}
    else{return 0;}
}

int difConseq (char s[]) {
    int i,j = 0;
    int c = 1;
    int max = 0;
    int size = strlen(s);
    for(i=0;i<size;i++){
        c=0;
        for(j=i;j<size;j++){
            if(dif_aux(s,s[j],i,j)) {c++;}
            else{break;}
        }
        if(c>max){max=c;}    
    }
    return max;
}

//17.
int maiorPref (char s1[], char s2[]) {
    int i = 0;
    int c = 0;
    for(i=0;s1[i];i++){
        if(s1[i]==s2[i]){c++;}
        else{break;}
    }
    return c;
}

//18
int maiorSuf (char s1[], char s2[]) {
    int c = 0;
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    //printf("s1: %d\ns2: %d\n",size1,size2);
    while(size1>0){
        if (s1[size1]==s2[size2]){
            size1--;
            size2--;
            c++;
        }
        else{break;}
    }
    return c;
}

//19. aux recebe 2 int de s1 para verificar se sao pref de s2
int isPref (char s1[], char s2[], int i, int j){
    int k;
    for(k=0;s2[k];k++){
        if(s2[k]==s1[i] && i<j){i++;}
        else{break;}
    }
    if(i==j){return 0;}
    else{return 1;}
}

int sufPref (char s1[], char s2[]) {
    int size1 = strlen(s1);
    int i,c,max = 0;
    for(i=0;i<size1;i++){
        if (isPref(s1,s2,i,size1-1)==0) {
            c = size1-i;
            //printf("(%d,%d,%d)\n",i,size1,c);
            if (c > max) {max=c;}
        }
    }
    return max;
}

//20.
int contaPal (char s[]) {
    int i,c = 0;
    char ch = ' ';
    for(i=0;s[i];i++) {
        if (s[i]!=' ' && ch==' ') {c++;}
        ch = s[i];   
    }
    return c;
}

//22.
int contida (char a[], char b[]) {
    int i,j;
    int c = 0;
    for(i=0;a[i];i++){
        for(j=0;b[j];j++){
            if(a[i]==b[j]){c++;break;}
        }
    }
    if(c==strlen(a)){return 0;}
    else{return 1;}
}

//23.
int palindrome (char s[]) {
    int size = strlen(s);
    printf("t: %c\n",s[3]);
    int t = size-1;
    int i,res=0;
    for(i=0;i<size/2;i++){
        if (s[i]!=s[t]) {res=1;break;}
        t--;
    }
    return res;
}

//24.
int remRep (char s[]) {
    int i;
    int size = strlen(s);
    while(s[i]){
        if(s[i]==s[i+1]){aux(s,i+1,size);size--;}
        else{i++;}
    }
    return size;
}

//26.
void insere (int v[], int N, int x) {
    int i,j;
    for(i=0;i<N;i++){
        if(x<v[i]){
            for(j=N;j>i;j--){
                v[j] = v[j-1];
            }
            v[i] = x;
            break;    
        }
        if(i == N - 1) {
            v[N] = x;
        }
    }    
}

//27.
void merge (int r[], int a[], int b[], int na, int nb) {
    int i,j,k=0;
    while(k<na+nb){
        if(a[i]<b[j]){
            r[k++]=a[i++];
        }
        if(a[i]>b[j]){
            r[k++]=b[j++];           
        }
    }
    //if(i==na){r[k]=b;}
    //if(j==nb){r[k]=a;}
}

//28.
int crescente (int v[], int i, int j) {
    int res = 0;
    for(i;i<j;i++){
        if(v[i]>v[i+1]){res=1;break;}
    }
    return res;
}

void retira (int v[], int i, int N) {
    for(i;i<N;i++){v[i]=v[i+1];}
}

int retiraNeg (int v[], int N) {
    int i;
    for(i=0;i<N;i++){
        if (v[i]<0) {retira(v,i,N);N--;}
        printf("N: %d\n",N);
    }
}

//30.
int menosFreq (int v[], int N) {
    int res = 0;
    int min = 10;
    int i = 0;
    int c=1;
    for(i=0;i<N;i++){
        if(v[i]==v[i+1]){c++;}
        else{
            if (c<min) {min=c;res=v[i];}
            c=1;
        }
    }
    return res;
}

//32.
int maxCresc (int v[], int N) {
    int max = 0;
    int i = 0;
    int c = 1;
    for(i;i<N;i++){
        if (v[i]<v[i+1]) {c++;}
        else {
            if (c>max) {max = c;}
            c=1;
        }
    }
    return max;
}

//33.
int elimRep (int v[], int N) {
    int i=0,j=0;
    for(i;i<N;i++){
        for(j=i+1;j<N;j++){
            if (v[i]==v[j]) {retira(v,j,N);N--;}
        }
    }
    return N;
}

//34.
int elimRepOrd (int v[], int N) {
    int i=0;
    while(i<N){
        if (v[i]==v[i+1]) {retira(v,i+1,N);N--;}
        else{i++;}
    }
    return N;
}

//35. assuma q a[] e b[] estão ordenados 
int comunsOrd (int a[], int b[], int na, int nb) {
    int i=0,j=0,res=0;
    for(i=0;i<na;i++){
        if (a[i]==a[i-1]){i++;}
        for(j=0;j<nb;j++){
            if (b[j]>a[i]) {break;}
            if (b[j]==a[i]) {res++;break;}
        }
    }
    return res;
}




int main() {
    //maior();
    //media();
    //segmaior();
    
    //int digits = qDig(25434);
    //printf("nr de dígitos: %d",digits);

    char s1[14] = "aaaaaaaaaaaa\0";
    //char s2[16] = "bra\0";

    //char *p = strcat2(s1,s2);
    //char *p = strcpy2(s2,s1);
    //int res = strcmp2(s1,s2);
    //char *p = strstr2(s1,s2);
    //strrev(s1);
    //strnoV(s1);

    int i=0,j=0;
    int size = 11;
    //for(i=0;i<5;i++){aux(s2,4,size);size--;}

    //aux(s1,5,11);
    //truncW(s1,4);

    //char res = charMaisFreq(s1);
    //int res = iguaisConseq(s2);
    //int res = difConseq(s2);
    //int res = maiorPref(s1,s2);
    //int res = maiorSuf(s1,s2);
    //int res = isPref(s1,s2,2,5);
    //int res = sufPref(s1,s2);

    //int res = contaPal(s1);
    //int res = contida(s1,s2);
    //int res = palindrome(s1);
    //int res = remRep(s1);

    int v1[4] = {1,2,3,4};
    int v2[4] = {0,3,3,4};
    int v3[4] = {0,0,1,2};
    int v4[4] = {0,0,0,4};
    int m[4][4];
    for(i=0;i<4;i++){m[0][i] = v1[i];}
    for(i=0;i<4;i++){m[1][i] = v2[i];}
    for(i=0;i<4;i++){m[2][i] = v3[i];}
    for(i=0;i<4;i++){m[3][i] = v4[i];}

    int r[12] = {};
    int N = 6;
    //insere(v,N,4);
    //merge(r,v1,v2,6,6);
    //int res = crescente(v1,0,3);
    //retiraNeg(v1,6);
    //int res = menosFreq(v1,6);
    //int res = maxCresc(v1,7);
    //int res = elimRepOrd(v1,7);
    //int res = comunsOrd(v1,v2,4,4);
    int res = triSup(4,m);


    //printf("len s1: %d\nlen s2: %d\n",strlen(s1),strlen(s2));
    //printf("res: %d\n",res);
    //for(i=0;i<4;i++){printf("%d ",v1[i]);}
    //printf("\n");

    //PRINT MATRIX
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){printf("%d ",m[i][j]);}
        printf("\n");
    }

}