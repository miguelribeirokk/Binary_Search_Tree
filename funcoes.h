#include <stdio.h>
#include <stdlib.h>


typedef struct TipoNo *apontador;

typedef struct TipoNo{
    int valor;
    apontador esq, dir;
}TipoNo;


void IniciaArvore(apontador *no);
void Insere(apontador *no, int valor);
void percorrer(apontador no);
void pre_ordem(apontador no);
void pos_ordem(apontador no);
void retira_no(apontador *no, int valor);
void antecessor(apontador no, apontador *a);
int estaNaArvore(apontador no, int valor);
int numero_de_nos(apontador no);
int maior_elemento(apontador no);
int altura(apontador no);
int profundidade(apontador no, int valor);
void menor_elemento(apontador no, int *valor);




