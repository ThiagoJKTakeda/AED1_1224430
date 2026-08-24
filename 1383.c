#include <stdio.h>

int valida_linhas(int sudoku[9][9]){
    for(int i = 0; i<9; i++){
        int frequencia[10]={0};
        for(int j = 0; j < 9; j++){
            int numero = sudoku[i][j];
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

int valida_colunas(int sudoku[9][9]){
    for(int j = 0; j < 9; j++){
        int frequencia[10]={0};
        for(int i = 0; i < 9; i++){
            int numero = sudoku[i][j];
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

int valida_blocos(int sudoku[9][9]){
    for(int coluna_bloco = 0; coluna_bloco < 9; coluna_bloco += 3){
        for(int linha_bloco = 0; linha_bloco < 9; linha_bloco += 3){
            int frequencia[10]={0};
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int numero = sudoku[linha_bloco + i][coluna_bloco + j];

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
    int sudoku[9][9];
    int n, valido;
    scanf("%d", &n);
    for(int t = 0; t < n; t++){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &sudoku[i][j]);
            }
        }
        int valido_linha = valida_linhas(sudoku);
        int valido_coluna = valida_colunas(sudoku);
        int valido_bloco = valida_blocos(sudoku);

        printf("Instancia %d\n", t+1);

        if(valido_linha == 1 && valido_coluna == 1 && valido_bloco == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        printf("\n");
       
    }
    return 0;
}
