#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char operador;
    struct No* proximo;
}No;

void push(No** topo, char op){
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        return;
    }
    novoNo->operador = op;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

char pop(No** topo){
    if(*topo == NULL){
        return '\0';
    }
    No* temp = *topo;
    char op = temp->operador;
    *topo = temp->proximo;
    free(temp);
    return op;
}

char peek(No* topo){
    if(topo == NULL){
        return '\0';
    }
    return topo->operador;
}

int vazia(No* topo){
    return topo == NULL;
}

int obter_precedencia(char op){
    if(op == '^'){
        return 3;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '+' || op == '-'){
        return 1;
    }
    return 0;
}

void Resolver_caso(){
    char expressao[305];
    if(scanf("%s", expressao)==EOF){
        return;
    }

    No* pilha = NULL;

    for(int i = 0; expressao[i] != '\0'; i++){
        char atual = expressao[i];

        if((atual >= 'A' && atual <= 'Z') || (atual >= 'a' && atual <= 'z' ) || (atual >= '0' && atual <= '9')){
            printf("%c", atual);
        }

        else if (atual == '('){
            push(&pilha, atual);
        }
        else if (atual == ')'){
            while(!vazia(pilha) && peek(pilha) != '('){
                printf("%c", pop(&pilha));
            }
            if(!vazia(pilha)){
                pop(&pilha);
            }
        }
        else{
            while(!vazia(pilha) && obter_precedencia(peek(pilha)) >= obter_precedencia(atual)){
                printf("%c", pop(&pilha));
            }

            push(&pilha, atual);
        }

    }
    while (!vazia(pilha)){
        printf("%c", pop(&pilha));
    }
    printf("\n");
}

int main(){
    int n;
    if(scanf("%d", &n) != EOF){
        while(n--){
            Resolver_caso();
        }
    }
    return 0;
}
