#include <stdio.h>
#include <stdlib.h>

int main(){

    int maior;
    int *posicao;
    int *vetor;

    vetor = (int*) malloc(100*sizeof(int));
    if(vetor == NULL){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for(int i = 0; i < 100; i++){
        scanf("%d", vetor + i);
    }
    maior = *(vetor + 0);
    posicao = vetor + 0;
    for(int i = 0; i < 100; i++){
        if(*(vetor + i) >= maior){
            maior = *(vetor + i);
            posicao = vetor + i;
        }
    }
    printf("%d\n", maior);
    printf("%ld\n",( posicao - vetor) + 1);

    free(vetor);
    
    return 0;

}
