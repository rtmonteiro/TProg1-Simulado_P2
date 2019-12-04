#include <stdio.h>
#include <stdlib.h>

typedef struct linha {
    int* valor;
    int qtd_colunas;
} tLinha;

typedef struct matriz {
    tLinha* matriz;
    int qtd_linhas;
} tMatriz;

tLinha * criaLinha();
tMatriz criaMatriz();


tLinha * criaLinha(){
    int numero;
    char lixinho;
    tLinha *linha  = (tLinha*)malloc(sizeof(tLinha));
    linha->valor= (tLinha*)malloc(sizeof(tLinha));
    linha->qtd_colunas = 1;
    scanf("%d%c", &numero, &lixinho);
    while (lixinho != '\n'){
        scanf("%d%c", &numero, &lixinho);
        int qtd_colunas = linha->qtd_colunas++;
        tLinha* linha_aux = (tLinha*)malloc(sizeof(tLinha)*qtd_colunas);
        for (int i = 0; i < linha->qtd_colunas; ++i) {
            linha_aux->valor[i] = linha->valor[i];
        }
        linha_aux->valor[qtd_colunas] = numero;
        free(linha);
        linha = linha_aux;
        linha_aux = NULL;
    }
    return linha;
}

void imprimeLinha(tLinha* linha){
    printf("%d", linha->valor[0]);
    for (int i = 1; i < linha->qtd_colunas; ++i) {
        printf(" %d", linha->valor[i]);
    }
}

//tMatriz criaMatriz() {
//    tMatriz mat = (tMatriz)malloc(sizeof(tMatriz));
//}


int main() {
//    tMatriz matriz = criaMatriz();
    tLinha* linha = criaLinha();
    return 0;
}