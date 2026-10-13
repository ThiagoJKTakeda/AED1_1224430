/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Thiago Jun Kimura Takeda
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 12/10/2026
Objetivo    : Se ao empilhar uma sequencia é possível desempilha-la em uma certa sequencia desejada.
Dificuldade : Entender a lógica de pilhas.
Uso de IA   : Entender melhor como usar pilhas.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int vagao;
    struct no* proximo;
}no;

void push(no **topo, int op){
    no*novono = (no*) malloc(sizeof(no));
    if(novono == NULL){
        return;
    }
    novono->vagao = op;
    novono->proximo = *topo;
    *topo = novono;
}

int pop(no** topo){
    if(*topo == NULL){
        return '\0';
    }
    no* temp = *topo;
    int op = temp->vagao;
    *topo = temp->proximo;
    free(temp);
    return op;
}

int peek(no* topo){
    if(topo == NULL){
        return -1;
    }
    return topo->vagao;
}

int vazia(no* topo){
    return topo == NULL;
}

int main(){
    int n;
    while(scanf("%d", &n) && n != 0){
        while(1){
            no* topo = NULL;
            int desejado[1000];
            scanf("%d", &desejado[0]);
            if(desejado[0] == 0){
                break;
            }
            for(int i = 1; i < n; i++){
                scanf("%d", &desejado[i]);
            }

            int j  = 0;
            int vagao_A = 1;

            while(j < n){

                if(!vazia(topo) && peek(topo) == desejado[j]){
                    pop(&topo);
                    j++;
                }
                else if(vagao_A <= n){
                    push(&topo, vagao_A);
                    vagao_A++;
                }
                else{
                    break;
                }
            }
            
            if(j == n){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
            
            while(!vazia(topo)){
                pop(&topo);
            }

        }

        printf("\n");
    }
    return 0;
}
