/*Nome: Kaike de Morais Carvalho
Matéria: Lab APC I
Programa: Desenvolver um programa que calcule o Fatorial de um número usando a estrutura DO WHILE*/

//Incluir a biblioteca de Entrada e Saída Padrão do C e a biblioteca para acentos da Língua Portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    //Setar o locale para que seja possível escrever o código com acentos
    setlocale(LC_ALL, "Portuguese");

    /*Declarar a variável (num) que receberá o input do usuário
    Declarar a variável (fatorial) que irá auxiliar no cálculo do fatorial de num*/
    int num;
    int fatorial = 1;

    /*Printar para que o usuário digite um número a ser calculado
    Atribuir o input do usuário na variável num*/
    printf("Calculadora de Fatorial Automática em C!! \n");
    printf("Insira um número que deseja calcular: \n");
    scanf("%i", &num);

    /*Do (Bloco de comandos a ser executado)
    While (Condição para que o loop ocorra)*/
    do {
        /*Fatorial (1) recebe o mesmo valor inserido pelo usuário
        Num é subtraído por 1
        Fatorial é multiplicado pelos antecessores de 1 até que o loop seja finalizado*/
        fatorial = fatorial * num;
        num = num - 1;
    }
    //O loop ocorre enquanto o num (valor inserido pelo usuário) é maior que 1
    while (num > 1);

    //Printar o resultado do fatorial
    printf("O fatorial do seu número escolhido é %i!! \n ", fatorial);


    return 0;
}
