/*Nome: Kaike de Morais Carvalho
Mat�ria: Lab APC I
Programa: Desenvolver um programa que calcule o Fatorial de um n�mero usando a estrutura DO WHILE*/

//Incluir a biblioteca de Entrada e Sa�da Padr�o do C e a biblioteca para acentos da L�ngua Portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    //Setar o locale para que seja poss�vel escrever o c�digo com acentos
    setlocale(LC_ALL, "Portuguese");

    /*Declarar a vari�vel (num) que receber� o input do usu�rio
    Declarar a vari�vel (fatorial) que ir� auxiliar no c�lculo do fatorial de num*/
    int num;
    int fatorial = 1;

    /*Printar para que o usu�rio digite um n�mero a ser calculado
    Atribuir o input do usu�rio na vari�vel num*/
    printf("Calculadora de Fatorial Autom�tica em C!! \n");
    printf("Insira um n�mero que deseja calcular: \n");
    scanf("%i", &num);

    /*Do (Bloco de comandos a ser executado)
    While (Condi��o para que o loop ocorra)*/
    do {
        /*Fatorial (1) recebe o mesmo valor inserido pelo usu�rio
        Num � subtra�do por 1
        Fatorial � multiplicado pelos antecessores de 1 at� que o loop seja finalizado*/
        fatorial = fatorial * num;
        num = num - 1;
    }
    //O loop ocorre enquanto o num (valor inserido pelo usu�rio) � maior que 1
    while (num > 1);

    //Printar o resultado do fatorial
    printf("O fatorial do seu n�mero escolhido � %i!! \n ", fatorial);


    return 0;
}
