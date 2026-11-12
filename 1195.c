#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
}no;

no* criar_no(int valor){
    no *novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

no* inserir(no *raiz, int valor){
    if(raiz == NULL){
        return criar_no(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if(raiz->valor < valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void prefixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%d", raiz->valor);
        *primeiro = 0;
        prefixo(raiz->esquerda, primeiro);
        prefixo(raiz->direita, primeiro);
    }
}

void infixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        infixo(raiz->esquerda, primeiro);
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%d", raiz->valor);
        *primeiro = 0;
        infixo(raiz->direita, primeiro);
    }
}

void posfixo(no *raiz, int *primeiro){
    if(raiz != NULL){
        posfixo(raiz->esquerda, primeiro);
        posfixo(raiz->direita, primeiro);
        if(!(*primeiro)){
            printf(" ");
        }
        printf("%d", raiz->valor);
        *primeiro = 0;
    }
}

void liberar(no *raiz){
    if(raiz != NULL){
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main(){
    int n = 0, i = 0;
    scanf("%d", &n);
    for( i = 0; i < n; i++){
        no *raiz = NULL;
        int qtd = 0;
        scanf("%d", &qtd);
        for(int j = 0; j < qtd; j++){
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", i + 1);

        int primeiro = 1;
        printf("Pre.: ");  
        prefixo(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        infixo(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posfixo(raiz, &primeiro);
        printf("\n\n");
        liberar(raiz);
    }
    return 0;
}
