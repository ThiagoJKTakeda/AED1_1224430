#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char itens[1001];
    int topo;
}pilha;

int Bem_Formada(char s[]){
    char *p;
    int t, n, i;
    n = strlen(s);
    p = malloc(n*sizeof(char));
    t = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            p[t++] = '(';
        }
        else if(s[i] == ')'){
            if(t > 0){
                t--;
            }
            else{
                free(p);
                return 0;
            }
        }
    }

    int resultado = (t == 0);
    free(p);
    return resultado;
}

int main(){
    char e[1001];

    while(scanf("%s", e) != EOF){

        if(Bem_Formada(e)){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
    }
    return 0;
}
