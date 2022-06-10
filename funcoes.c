#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void IniciaArvore(apontador *no){
    *no = NULL;
    
}

void Insere(apontador *no, int valor){
    
    if(*no == NULL){
        
        *no = (apontador )malloc(sizeof(TipoNo));
        (*no)->valor = valor;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
    }
     
    else{
        if(valor < (*no)->valor){
            
            Insere(&(*no)->esq, valor);
            
        }
        else if(valor > (*no)->valor){
            Insere(&(*no)->dir, valor);
        }
    }

}
void percorrer(apontador no){
    if(no != NULL){
        percorrer(no->esq);
        printf("%d ", no->valor);
        percorrer(no->dir);
    }
}
void pre_ordem(apontador no){
    if(no != NULL){
        printf("%d ", no->valor);
        pre_ordem(no->esq);
        pre_ordem(no->dir);
    }
}

void pos_ordem(apontador no){
    if(no != NULL){
        pos_ordem(no->esq);
        pos_ordem(no->dir);
        printf("%d ", no->valor);
    }
}
void antecessor(apontador no, apontador *a){
    apontador aux;
    if(no->dir != NULL){
        antecessor(no->dir, a);
    }
    else{
        *a = no;
    
    }

}
    
void retira_no(apontador *no, int valor){
    apontador aux;
    if(*no != NULL){
        if(valor < (*no)->valor){
            retira_no(&(*no)->esq, valor);
        }
        else if(valor > (*no)->valor){
            retira_no(&(*no)->dir, valor);
        }
        else{
            if((*no)->esq == NULL && (*no)->dir == NULL){
                free(*no);
                *no = NULL;
            }
            else if((*no)->esq == NULL){
                aux = *no;
                *no = (*no)->dir;
                free(aux);
            }
            else if((*no)->dir == NULL){
                aux = *no;
                *no = (*no)->esq;
                free(aux);
            }
            else{
                antecessor((*no)->esq, &aux);
                (*no)->valor = aux->valor;
                retira_no(&(*no)->esq, aux->valor);
            }
        }
    }}

    //retornar true ou false se esta ou nao esta na arvore
    int estaNaArvore(apontador no, int valor){
        if(no == NULL)
            return 0;
        if(valor == no->valor)
            return 1;
        if(valor < no->valor)
            return estaNaArvore(no->esq, valor);
        else
            return estaNaArvore(no->dir, valor);
    }
    int numero_de_nos (apontador no){
        if(no == NULL)
            return 0;
        return 1 + numero_de_nos(no->esq) + numero_de_nos(no->dir);
    }

    int maior_elemento(apontador no){
        if(no->dir != NULL){
            return maior_elemento(no->dir);
        }
        else{
            return no->valor;
        }

    }
    void menor_elemento(apontador no, int *menor){
        if(no->esq != NULL){
            menor_elemento(no->esq, menor);
        }
        else{
            *menor = no->valor;
            printf(" %d ", *menor);
        }
    }
//calcula a altura da arvore
int altura(apontador no){
    int altura_esq, altura_dir;
    if(no == NULL)
        return 0;
    altura_esq = altura(no->esq);
    altura_dir = altura(no->dir);
    if(altura_esq > altura_dir)
        return altura_esq + 1;
    else
        return altura_dir + 1;
}
//calcular a profundidade do no
int profundidade(apontador no, int valor){
    if(no == NULL)
        return 0;
    if(valor == no->valor)
        return 0;
    if(valor < no->valor)
        return profundidade(no->esq, valor) + 1;
    else
        return profundidade(no->dir, valor) + 1;
}
    