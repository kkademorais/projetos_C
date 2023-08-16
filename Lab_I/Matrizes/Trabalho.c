//Nome: Kaike de Morais Carvalho
//Matéria: Laboratório de Programação I
//Matrícula: 202301131

#include <stdio.h>
#include <locale.h> //Biblioteca para uso e escrita dos acentos em português

main()
{
    setlocale(LC_ALL, "Portuguese"); //Permite o uso dos acentos

    char matriz1[3][4]; //Matriz que recebe os valores digitados
    char matriz2[3][4]; //Matriz final que recebe o dobro da Matriz1 em sua respectiva posição
    int valor, linha, coluna;

    printf("\n");
    printf("Trabalho -> Matrizes");
    printf("\n");

    //FOR de preenchimento da Matriz 1
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 4; coluna++){
            printf("\n");
            printf("Linha %i - Coluna %i", linha + 1, coluna + 1);
            printf("\n");
            printf("Insira um valor nessa posição: ");
            scanf("%i", &valor);
            matriz1[linha][coluna] = valor;
        }
    }

    printf("\n");
    printf("Matriz 1: ");
    printf("\n");

    //FOR de visualização da Matriz 1
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 4; coluna++){
            printf("%i \t", matriz1[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Agora vamos a montagem e visualização da Matriz 2");
    printf("\n");

    //FOR de preenchimento da Matriz2
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 4; coluna++){
            matriz2[linha][coluna] = matriz1[linha][coluna] * 2; //O FOR percorre elemento por elemento e preenche a Matriz2 com o dobro do valor da Matriz1 na respectiva posição
            printf("Valor adicionado na posição: ");
            printf("\n");
            printf("Linha %i -> Coluna %i", linha + 1, coluna + 1);
            printf("\n\n");
        }
    }

    //FOR de visualização da Matriz2
    printf("Matriz 2: ");
    printf("\n");
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 4; coluna++){
            printf("%i \t", matriz2[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
