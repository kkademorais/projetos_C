#include <stdio.h>
#include <stdlib.h>

/*  Falta:
    Corrigir algoritmo
    Aplicar ponteiro
    Aplicar malloc

*/

int binarySearch(int vetor[], int valorBusca, int tamanho, int pontaEsq, int pontaDir){
    //tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int meio = meioVetor(pontaEsq, pontaDir);

    if(pontaEsq >= pontaDir) return -1;

    if(valorBusca == vetor[meio]){
        printf("\nValor encontrado!\n");
        printf("\nValor %d na Posição %d do vetor...\n", vetor[meio], meio);
        return valorBusca;
    }
    if(valorBusca > vetor[meio]){
        printf("\nValor buscado (%d) maior que o elemento do meio (%d)\n", valorBusca, vetor[meio]);
        pontaEsq = meio+1;
        binarySearch(vetor, valorBusca, (tamanho), pontaEsq, pontaDir);
    }
    if(valorBusca < vetor[meio]){
        printf("\nValor buscado (%d) menor que o elemento do meio (%d)\n", valorBusca, vetor[meio]);
        pontaDir = meio-1;
        binarySearch(vetor, valorBusca, (tamanho), pontaEsq, pontaDir);
    }
    else return -1;


}


int binarySearchCorreto(int vetor[], int valorBusca, int tamanho, int pontaEsq, int pontaDir){
    //tamanho = sizeof(vetor) / sizeof(vetor[0]);
    imprimindoVetor(vetor, pontaEsq, pontaDir);
    while(pontaEsq < pontaDir){
        int meio = meioVetor(pontaEsq, pontaDir);
        imprimindoVetor(vetor, pontaEsq, pontaDir);
        if(valorBusca == vetor[meio]){
            //printf("\nChave encontrada!\n");
            return vetor[meio];
        }
        if(valorBusca > vetor[meio]){
            printf("\nValor de busca (%d) maior que o meio do vetor (%d)\n", valorBusca, vetor[meio]);
            pontaEsq = meio + 1;
            imprimindoVetor(vetor, pontaEsq, pontaDir);
            binarySearchCorreto(vetor, valorBusca, tamanho, pontaEsq, pontaDir);
        }
        if(valorBusca < vetor[meio]){
            printf("\nValor de busca (%d) menor que o meio do vetor (%d)\n", valorBusca, vetor[meio]);
            pontaDir = meio - 1;
            imprimindoVetor(vetor, pontaEsq, pontaDir);
            binarySearchCorreto(vetor, valorBusca, tamanho, pontaEsq, pontaDir);
        }
    }
}


int meioVetor(int pontaEsq, int pontaDir){
    int meio = (pontaEsq+pontaDir)/2;
    return meio;
}

void imprimindoVetor(int vetor[],int pontaEsq, int pontaDir){
    printf("\nImprimindo vetor atual: \n");
    for(int i = pontaEsq; i <= pontaDir; i++){
        printf("[%d] ", vetor[i]);
    }
}



int main()
{
    int vetor[7] = {2,3,5,8,15,20,77};
    int valorBusca;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int pontaEsq = 0;
    int pontaDir = tamanho-1;

    printf("\nDigite um valor para buscarmos no vetor: ");
    scanf("%d", &valorBusca);

    //printf("\nBuscando %d no vetor = %d\n", valorBusca, binarySearch(vetor, valorBusca, tamanho, pontaEsq, pontaDir));
    printf("\nBuscando %d no vetor = %d\n", valorBusca, binarySearchCorreto(vetor, valorBusca, tamanho, pontaEsq, pontaDir));


    return 0;
}
