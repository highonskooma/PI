#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a) {
    int i;
    int sum=0;
    float mediaF=0;
    for(i=0;i<6;i+=1){
        sum+=(a.miniT[i]);
    }
    sum=sum/6;
    mediaF=(0.3*sum)+(0.7*a.teste);
    if (mediaF<9.5) {return 0;}
    else{{return mediaF;}}
}

int procuraNum (int num, Aluno t[], int N) {
    for(int i=0;i<=N;i+=1){
        if(t[i].numero==num){return i;}
    }
    return -1;
}

void ordenaPorNum (Aluno t[], int N){
    struct aluno temp;
    for(int i=0;i<N;i+=1){
        if(t[i].numero>t[i+1].numero){
            temp=t[i];
            t[i]=t[i+1];
            t[i+1]=temp;
        }
    }
}


int main() {
    struct aluno Aluno1;
    Aluno1.numero=0;
    strcpy(Aluno1.nome,"João");
    int v[6] = {10,15,9,8,16,20};
    for(int i=0;i<6;i+=1){Aluno1.miniT[i]=v[i];}
    Aluno1.teste=16.2;
    int um = nota(Aluno1);
    printf("nota final do aluno 1: %d\n",um);

    struct aluno Aluno2;
    Aluno2.numero=4;
    strcpy(Aluno2.nome,"Maria");
    for(int i=0;i<6;i+=1){Aluno2.miniT[i]=v[i];}
    Aluno2.teste=16.2;

    struct aluno Aluno3;
    Aluno3.numero=9;
    strcpy(Aluno3.nome,"Velho");
    for(int i=0;i<6;i+=1){Aluno3.miniT[i]=v[i];}
    Aluno3.teste=16.2;

    struct aluno alunos[3];
    alunos[0]=Aluno1;
    alunos[1]=Aluno3;
    alunos[2]=Aluno2; 

    int dois = procuraNum(4,alunos,2);
    printf("O indice do aluno número %d é: %d\n",4,dois);

    printf("ordem inicial: ");
    for(int i=0;i<=3;i+=1){printf("%s ",alunos[i].nome);}
    printf("\n");

    ordenaPorNum(alunos,3);

    printf("depois da ordenação: ");
    for(int i=0;i<=3;i+=1){printf("%s ",alunos[i].nome);}
    printf("\n");
}