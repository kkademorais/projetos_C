/*Nome: Kaike de Morais Carvalho
Matéria: Lab APC I
Programa: Desenvolva um programa que calcule o Fatorial de um número usando a estrutura WHILE*/

//Incluir biblioteca de Entrada e Saída Padrão do C e a biblioteca para acentos da Língua Portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    /*Setar o locale para que seja possível a escrita do código com acentos
    Declaração da variável num que receberá o input do usuário
    Declaração da variável fatorial para que seja realizado o cálculo de fatorial*/
    setlocale(LC_ALL, "Portuguese");
    int num;
    int fatorial = 1;

    /*Printar para que o usuário digite um número a ser calculado
    Input do usuário é atribuído na variável num*/
    printf("Calculadora de Fatorial em C!! \n");
    printf("Insira um número que deseja calcular: \n");
    scanf("%i", &num);

    /*While: (Condição final)
    While vai ser executado enquanto o num é igual a 1*/
    while (num > 1)
    {
        /*Dentro do while:
        Fatorial (1) é multiplicado e recebe o mesmo valor inserido pelo usuário
        O num é subtraido por 1 até que seja igual a 1 e assim acabe o loop
        O fatorial vai sendo multiplicado pelo antecessor de num até o fim do loop*/
        fatorial = fatorial * num;
        num = num - 1;
    }
    //Printar o resultado do fatorial
    printf("O fatorial do seu número é %i!! \n", fatorial);

    return 0;
}
