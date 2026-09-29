/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Thiago Jun Kimura Takeda
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 29/09/2026
Objetivo    : Fazer um jogo de cartas que descarte a carta do topo e jogue a seguinte para o fim.
Dificuldade : Fazer o exercíciio usando listas encadeadas.
Uso de IA   : O porquê de estarem ocorrendo certos erros no beecrowd.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int conteudo;
    struct celula *seguinte;
}celula;

typedef struct{
    struct celula *head;
    struct celula *tail;
}fila;


int Remove_Topo(fila *f){
    if(f->head == NULL){
        return -1;
    }

    celula *lixo = f->head;
    int valor = lixo->conteudo;
    f->head = f->head->seguinte;
    if(f->head == NULL){
        f->tail = NULL;
    }

    free(lixo);
    return valor;

}

void Mover_para_fim(fila *f){
   if(f -> head == NULL || f->head->seguinte == NULL){
        return;
   }
   celula *mover = f-> head;
   f->head = mover->seguinte;
   f->tail->seguinte = mover;
   f->tail = mover;
   mover->seguinte = NULL;
}

void Insere_Fim(fila *f, int valor){
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->conteudo = valor;
    novo->seguinte = NULL;
    if(f->head == NULL){
        f->head = novo; 
        f->tail = novo;
    }
    else{
        f->tail->seguinte = novo;
        f->tail = novo;
    }
}

int main(){
    int n;

    while(scanf("%d", &n) && n != 0){
        fila f;
        f.head = NULL;
        f.tail = NULL;
        
        for(int i = 1; i <= n; i++){
            Insere_Fim(&f, i);
        }

        int descartadas[55];
        int qtd_descartadas = 0;

        while(f.head != f.tail){
            descartadas[qtd_descartadas] = Remove_Topo(&f);
            qtd_descartadas++;

            Mover_para_fim(&f);
        }

        printf("Discarded cards: ");

        for(int i = 0; i < qtd_descartadas; i++){
            if(i > 0){
                printf(", ");
            }
            printf("%d", descartadas[i]);
            
        }
        printf("\n");
        printf("Remaining card: %d\n", f.head->conteudo);
        free(f.head);
    }
    return 0;
}
