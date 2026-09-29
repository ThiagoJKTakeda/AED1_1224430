#include <stdio.h>
#include <stdlib.h>

int valida_linhas(int **matriz, int linhas, int colunas){
     for(int i = 0; i<linhas; i++){
        int frequencia[10]={0};
        for(int j = 0; j < colunas; j++){
            int numero = matriz[i][j];
            if(frequencia[numero]==1){
                return 0;
            }
            else{
                frequencia[numero] = 1;
            }
        }
    }
    return 1;
}

int valida_colunas(int **matriz, int linhas, int colunas){
    for(int j = 0; j < colunas; j++){
        int frequencia[10]={0};
        for(int i = 0; i < linhas; i++){
            int numero = matriz[i][j];
            if(frequencia[numero]==1){
                return 0;
            }
            else{
                frequencia[numero] = 1;
            }
        }
    }
    return 1;
}

int valida_blocos(int **matriz){
    for(int coluna_bloco = 0; coluna_bloco < 9; coluna_bloco += 3){
        for(int linha_bloco = 0; linha_bloco < 9; linha_bloco += 3){
            int frequencia[10]={0};
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int numero = matriz[linha_bloco + i][coluna_bloco + j];

                    if(frequencia[numero] == 1){
                        return 0;
                    }
                    else{
                        frequencia[numero] = 1;
                    }
                }
            }
        }
    }
    return 1;
}

int main(){
    int **matriz;
    int i, j, linhas = 9, colunas = 9, n;

    scanf("%d", &n);

    for(int t = 0; t < n; t++){
        
        matriz = (int **) malloc(linhas * sizeof(int*));
        if(matriz == NULL){
            printf("Erro de alocação!\n"); 
            return 1;
        }
        for(i = 0; i < 9; i ++){
            matriz[i] = (int *) malloc(colunas*sizeof(int));
            if(matriz[i] == NULL){
                printf("Erro de alocação!\n");
                return 1;
            }
        }

        for(i = 0; i < linhas; i++){
            for(j = 0; j < colunas; j++){
                scanf("%d", &matriz[i][j]);
            }
        }
        int valida_linha = valida_linhas(matriz, linhas, colunas);
        int valida_coluna = valida_colunas(matriz, linhas, colunas);
        int valida_bloco = valida_blocos(matriz);

        printf("Instancia %d\n", t+1);

         if(valida_linha == 1 && valida_coluna == 1 && valida_bloco == 1){
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        for(i = 0; i < 9; i++){
            free(matriz[i]);
        }
        free(matriz);

    }

    return 0;
}
