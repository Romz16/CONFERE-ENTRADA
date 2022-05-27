#include "pilha.h"
#include <stdio.h>


int main() {
    char ch;
    TItem item;
    TPilha pilha;

    TPilhaInicia(&pilha);

    while (scanf("%c", &ch)!=EOF) {
        if(ch == '\n')
            break;
        
        if(ch == '('){
            TPilhaPush(&pilha, ch);
            
        }
        if(ch == ')'){
            TPilhaPop(&pilha, &item);
        }

        if (TPilhaPop(&pilha, &item)==0)
        {
            printf("incorreto");
            return 0 ;
        }
        
    }

    if(TPilhaEhVazia(&pilha)==0)
        printf("incorreto");
    else
        printf("correto");

    TPilhaEsvazia(&pilha);

    return 0;//nao remova
}
