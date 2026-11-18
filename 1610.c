/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Thiago Jun Kimura Takeda
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : Saber se existe um loop na lista.
Dificuldade : Aplicar o DFS.
Uso de IA   : Entender como o DFS funciona.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int *inicio, *destino, *prox;
int *estado;
int aresta;

void adicionar_aresta(int a, int b){
    destino[aresta] = b;
    prox[aresta] = inicio[a];
    inicio[a] = aresta;
    aresta++;
}

int dfs(int v){
    estado[v] = 1;

    for(int i = inicio[v]; i != -1; i = prox[i]){
        int vizinho = destino[i];

        if(estado[vizinho] == 1){
            return 1;
        }

        if(estado[vizinho] == 0){
            if(dfs(vizinho)){
                return 1;
            }
        }
    }

    estado[v] = 2;
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        inicio = malloc((n + 1) * sizeof(int));
        destino = malloc(m * sizeof(int));
        prox = malloc(m * sizeof(int));
        estado = calloc(n + 1, sizeof(int));

        for(int i = 1; i <= n; i++){
            inicio[i] = -1;
        }

        aresta = 0;

        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            adicionar_aresta(a, b);
        }

        int ciclo = 0;

        for(int i = 1; i <= n; i++){
            if(estado[i] == 0){
                if(dfs(i)){
                    ciclo = 1;
                    break;
                }
            }
        }

        if(ciclo){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

        free(inicio);
        free(destino);
        free(prox);
        free(estado);
    }

    return 0;
}
