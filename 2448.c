/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Thiago Jun Kimura Takeda
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 12/10/2026
Objetivo    : Calcular quanto tempo um carteiro leva para fazer uma certa quantidade de entrgas.
Dificuldade : Entender a lógica de busca binária.
Uso de IA   : Realizar correções pontuais no código. 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int Busca_Binaria(int vetor[], int tamanho, int VP){
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim){
        int meio = inicio + (fim - inicio)/2;

        if(vetor[meio] == VP){
            return meio;
        }

        if(vetor[meio] < VP){
            inicio = meio + 1;
        }

        else{
            fim = meio - 1;
        }
    }
}

int main(){
    int casas = 0, encomendas = 0, tempo_deslocamento = 0;
    int N[50000], M[50000];
    long long int tempo_total = 0;
    scanf("%d%d", &casas, &encomendas);

    for(int i = 0; i < casas; i++){
        scanf("%d", &N[i]);
    }

    for(int i = 0; i < encomendas; i++){
        scanf("%d", &M[i]);
    }
    int posicao_atual = 0;
    for(int i = 0; i < encomendas; i++){
        int nova_posicao = Busca_Binaria(N, casas, M[i]);

        tempo_deslocamento = abs(nova_posicao - posicao_atual);
        tempo_total = tempo_total + tempo_deslocamento;
        posicao_atual = nova_posicao; 
        
    }

    printf("%lld\n", tempo_total);

    return 0;
}
