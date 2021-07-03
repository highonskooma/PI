#include <stdio.h>

int hash3(char s[],int N){
    int c=0;
    for(int i = 0;i<N;i++) {
        c += s[i] ;
        //printf("%d * %d\n",s[i],i+1);
    }
    return c;
}

int next(char s[], int n) {
 while (n > 0) {
   n--;
   if (s[n] < 'z') {
     s[n]++;
     return 1;
   } else {
     s[n] = 'a';
   }
 }
 return 0;
}

int main () {
 char s[10];
 int n,i;
 for (n=0;n<10;n++) {
   for (i=0;i<n;i++) s[i] = 'a';
   s[n] = '\0';
   do {
     if(hash3(s,n)==370){printf("%s\n",s);}
   } while(next(s,n));
 }
 return 0;
}