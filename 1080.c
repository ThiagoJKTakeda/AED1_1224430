#include <stdio.h>

int main(){
    int v[100];
    int posicao = 0, maior;
    for(int i = 0; i < 100; i++){
        scanf("%d", &v[i]);
    }
    maior = v[0];
    for(int i = 1; i < 100; i++){
        if(v[i]>maior){
            maior = v[i];
            posicao = i + 1;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicao);
    return 0;
}
