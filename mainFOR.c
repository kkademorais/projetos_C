/*Nome: Kaike de Morais Carvalho
Mat�ria: Lab APC I
Programa: Desenvolva um programa que calcule o Fatorial de um n�mero usando a estrutura FOR*/

//Incluir biblioteca de Entrada e Sa�da Padr�o do C e a biblioteca para incluir acentos da l�ngua portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    //Setar a l�ngua portuguesa para possibilitar a escrita do c�digo com acentos
    setlocale(LC_ALL, "Portuguese");

    /*Declarar a classe e o nome das vari�veis
    num = vari�vel para receber o input do usu�rio
    fatorial = vari�vel para calcular fatorial*/
    int num, fatorial;

    /*Printar para o usu�rio digitar um n�mero
    Input do usu�rio � armazenado na vari�vel num*/
    printf("Bem-vindo � calculadora de Fatorial!! \n");
    printf("Digite um n�mero que deseja calcular: \n");
    scanf("%i", &num);

    /*Loop de FOR: Inicial; Final; Incremento
    Inicial: Inicia setando o fatorial a 1
    Final: Finaliza o loop quando num for igual ou menor que 1
    Incremento: O num vai subtraindo 1 conforme o loop vai rodando*/
    for (fatorial = 1; num > 1; num = num -1)

        /*Dentro do loop, o fatorial (1) vai multiplicar o num e receber� o mesmo valor que o usu�rio inseriu
        Conforme o loop for rodando, o fatorial vai sendo multiplicado com o antecessor de num (num-1), at� que num seja 1
        No fim do loop, o resultado do fatorial � mostrado*/
        fatorial = fatorial * num;
        printf("O fatorial do seu n�mero � %i!! \n", fatorial);

    return 0;
}
