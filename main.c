#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    int a, b, c, d, e;
    apontador no;
    IniciaArvore(&no);
    
    for (int i = 0; i < 10; i++) {
        Insere(&no, rand()%100);
    }
    
    printf("\nOrdem: \n");
    percorrer(no);
    
    
    printf("\n\nPre ordem: \n");
    pre_ordem(no);
    
    printf("\n\nPos ordem: \n");
    pos_ordem(no);
    printf("\n");

    
    printf("\nProfundidade: \n");
    scanf("%d", &a);
    printf("%d", profundidade(no, a));
    printf("\n");

    //maior elemento
    printf("\nMaior elemento: \n");
    printf("%d\n", maior_elemento(no));

    //menor elemento
    printf ("\n\nMenor elemento: \n");
    menor_elemento(no, &c);
    printf("\n");

    //retirar um elemento
    printf ("\nRetirar um elemento: \n");
    scanf("%d", &d);
    retira_no(&no, d);
    percorrer(no);
    printf("\n");

    //numero de nos
    printf ("\nNumero de nos: \n");
    printf("%d", numero_de_nos(no));
    printf("\n");

    //esta na arvore
    printf ("\nEsta na arvore: \n");
    scanf("%d", &d);
    printf("%d", estaNaArvore(no, d));
    printf("\n");

    return 0;


    
}
