#include <stdio.h>
#include <stdlib.h>

typedef struct linha {
    int* valor;
    int qtd_colunas;
} tLinha;

typedef struct matriz {
    tLinha** matriz;
    int qtd_linhas;
} tMatriz;

tLinha *criaLinha(char *criterio_parada);
tMatriz * criaMatriz();


tLinha *criaLinha(char *criterio_parada) {
    int numero;

    tLinha *linha  = (tLinha*)malloc(sizeof(tLinha));
    linha->qtd_colunas = 1;
    linha->valor = (int*)malloc(sizeof(int));

    scanf("%d%c", &numero, criterio_parada);
    linha->valor[0] = numero;

    while (*criterio_parada != '\n' && *criterio_parada != 'c'){
        scanf("%d%c", &numero, criterio_parada);
        int qtd_colunas = linha->qtd_colunas + 1;
        tLinha* linha_aux = (tLinha*)malloc(sizeof(tLinha)*qtd_colunas);
        linha_aux->valor = (int*)malloc(sizeof(int)*qtd_colunas);
        linha_aux->qtd_colunas = qtd_colunas;
        for (int i = 0; i < linha->qtd_colunas; ++i) {
            linha_aux->valor[i] = linha->valor[i];
        }
        linha_aux->valor[qtd_colunas-1] = numero;
        free(linha);
        linha = linha_aux;
    }
    return linha;
}

void imprimeLinha(tLinha* linha){
    printf("%d", linha->valor[0]);
    for (int i = 1; i < linha->qtd_colunas; ++i) {
        printf(" %d", linha->valor[i]);
    }
    printf("\n");
}

tMatriz * criaMatriz() {
    char criterio_parada = '0';
    tMatriz* mat = (tMatriz*)malloc(sizeof(tMatriz));
//    mat->qtd_linhas = 1;
//    while (criterio_parada != 'c') {
    for (mat->qtd_linhas = 1; criterio_parada != 'c' ; ++mat->qtd_linhas) {
        tMatriz* mat_aux = (tLinha**)malloc(sizeof(tLinha*));
        mat_aux->matriz = (tLinha**)malloc(sizeof(tLinha*) * mat->qtd_linhas);
        mat->matriz[mat->qtd_linhas] = criaLinha(&criterio_parada);
    }
    return mat;
}

void imprimeMatriz(tMatriz* matriz){
    for (int i = 0; i < matriz->qtd_linhas; ++i) {
        imprimeLinha(matriz->matriz[i]);
    }
}


int main() {
    tMatriz* matriz = criaMatriz();
    imprimeMatriz(matriz);
//    tLinha* linha1 = criaLinha(0);
//    tLinha* linha2 = criaLinha(0);
//    imprimeLinha(linha1);
//    imprimeLinha(linha2);
    return 0;
}