/*Nome: Kaike de Morais Carvalho
Mat�ria: Lab APC I
Programa: Desenvolva um programa que calcule o Fatorial de um n�mero usando a estrutura WHILE*/

//Incluir biblioteca de Entrada e Sa�da Padr�o do C e a biblioteca para acentos da L�ngua Portuguesa
#include <stdio.h>
#include <locale.h>

main()
{
    /*Setar o locale para que seja poss�vel a escrita do c�digo com acentos
    Declara��o da vari�vel num que receber� o input do usu�rio
    Declara��o da vari�vel fatorial para que seja realizado o c�lculo de fatorial*/
    setlocale(LC_ALL, "Portuguese");
    int num;
    int fatorial = 1;

    /*Printar para que o usu�rio digite um n�mero a ser calculado
    Input do usu�rio � atribu�do na vari�vel num*/
    printf("Calculadora de Fatorial em C!! \n");
    printf("Insira um n�mero que deseja calcular: \n");
    scanf("%i", &num);

    /*While: (Condi��o final)
    While vai ser executado enquanto o num � igual a 1*/
    while (num > 1)
    {
        /*Dentro do while:
        Fatorial (1) � multiplicado e recebe o mesmo valor inserido pelo usu�rio
        O num � subtraido por 1 at� que seja igual a 1 e assim acabe o loop
        O fatorial vai sendo multiplicado pelo antecessor de num at� o fim do loop*/
        fatorial = fatorial * num;
        num = num - 1;
    }
    //Printar o resultado do fatorial
    printf("O fatorial do seu n�mero � %i!! \n", fatorial);

    return 0;
}
