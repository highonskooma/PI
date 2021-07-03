#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int sumhtpo (int n,int v[]){
  int r = 0;
  int c=0;
  int menor=n;
  int size=0;
  while (n != 1) {
    v[c]=n;
    c++;
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
    size+=1;
  }
  printf("m: %d\n",menor);
  return size;
}


int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}


int main(){
    int i=0;
    int res[118];
    int size = sumhtpo(97,res);
    printf("size: %d\n",size);
    qsort(res,size,sizeof(int),compare);
    for(i=0;i<size;i+=1){
        printf("%d\n",res[i]);
    }
    printf("RESULTADO: %d\n",res[29]);
}