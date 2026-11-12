#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char valor;
    struct no *direita;
    struct no *esquerda;
}no;

no* criar_no(char valor){
    no *novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return novo;
}

no* inserir(no *raiz, char valor){
    if(raiz == NULL){
        return criar_no(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if(valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

no* buscar(no *raiz, char valor){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->valor == valor){
        return raiz;
    }
    if(valor < raiz->valor){
        return buscar(raiz->esquerda, valor);
    }
    else{
        return buscar(raiz->direita, valor);
    }
}

void infixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        infixo(raiz->esquerda, primeiro);
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        infixo(raiz->direita, primeiro);
    }
}

void prefixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
        prefixo(raiz->esquerda, primeiro);
        prefixo(raiz->direita, primeiro);
    }
}

void posfixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        posfixo(raiz->esquerda, primeiro);
        posfixo(raiz->direita, primeiro);
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
}

int main(){
    char comando[10];
    char caractere;
    no *raiz = NULL;
    while(scanf("%s", comando) != EOF){
        if(strcmp(comando, "I") == 0){
            scanf(" %c", &caractere);
            raiz =  inserir(raiz, caractere);
        }
        else if(strcmp(comando, "P") == 0){
            scanf(" %c", &caractere);
            no *resultado = buscar(raiz, caractere);
            if(resultado == NULL){
                printf("%c nao existe\n", caractere);
            }
            else{
                printf("%c existe\n", caractere);
            }
        }
        else if(strcmp(comando, "INFIXA") == 0){
            int primeiro = 1;
            infixo(raiz, &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "PREFIXA") == 0){
            int primeiro = 1;
            prefixo(raiz, &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "POSFIXA") == 0){
            int primeiro = 1;
            posfixo(raiz, &primeiro);
            printf("\n");
        }
    }
    return 0;
}
