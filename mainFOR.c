/*Nome: Kaike de Morais Carvalho
Matéria: Lab APC I
Programa: Desenvolva um programa que calcule o Fatorial de um número usando a estrutura FOR*/

//Incluir biblioteca de Entrada e Saída Padrão do C e a biblioteca para incluir acentos da língua portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    //Setar a língua portuguesa para possibilitar a escrita do código com acentos
    setlocale(LC_ALL, "Portuguese");

    /*Declarar a classe e o nome das variáveis
    num = variável para receber o input do usuário
    fatorial = variável para calcular fatorial*/
    int num, fatorial;

    /*Printar para o usuário digitar um número
    Input do usuário é armazenado na variável num*/
    printf("Bem-vindo à calculadora de Fatorial!! \n");
    printf("Digite um número que deseja calcular: \n");
    scanf("%i", &num);

    /*Loop de FOR: Inicial; Final; Incremento
    Inicial: Inicia setando o fatorial a 1
    Final: Finaliza o loop quando num for igual ou menor que 1
    Incremento: O num vai subtraindo 1 conforme o loop vai rodando*/
    for (fatorial = 1; num > 1; num = num -1)

        /*Dentro do loop, o fatorial (1) vai multiplicar o num e receberá o mesmo valor que o usuário inseriu
        Conforme o loop for rodando, o fatorial vai sendo multiplicado com o antecessor de num (num-1), até que num seja 1
        No fim do loop, o resultado do fatorial é mostrado*/
        fatorial = fatorial * num;
        printf("O fatorial do seu número é %i!! \n", fatorial);

    return 0;
}
