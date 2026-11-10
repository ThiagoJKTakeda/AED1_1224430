#include <stdio.h>

int main(){
    int n = 0;
    int c = 0, r = 0, s = 0, total = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int quantidade = 0;
        scanf("%d", &quantidade);
        char tipo;
        scanf(" %c", &tipo);

        if(tipo == 'C'){
            c = c + quantidade;
        }
        else if(tipo == 'R'){
            r = r + quantidade;
        }
        else{
            s = s + quantidade;
        }
        total = total + quantidade;
    }

    float pc = ((float)c/total)*100;
    float pr = ((float)r/total)*100;
    float ps = ((float)s/total)*100;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", c);
    printf("Total de ratos: %d\n", r);
    printf("Total de sapos: %d\n", s);
    printf("Percentual de coelhos: %.2f %\n", pc);
    printf("Percentual de ratos: %.2f %\n", pr);
    printf("Percentual de sapos: %.2f %\n", ps);
    return 0;
}
