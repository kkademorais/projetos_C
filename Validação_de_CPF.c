#include <stdio.h>
#include <locale.h> //Biblioteca para escrever acentos e grafias da l�ngua portuguesa na tela
#include <ctype.h> //Biblioteca para manipula��o de caracteres -> Retira caracteres n�o num�ricos (isdigit)
#include <string.h> //Biblioteca para an�lise de string -> Verificar tamanho da string (strlen)


    //Fun��o para converter o valor de um caractere num�rico para seu valor inteiro
    //Utiliza da tabela ASCII
    //Subtrai o valor do caractere '0' para obter o valor do n�mero inteiro correspondente
int charparaint(char caractere)
{
    return caractere - '0';
}

    //Fun��o para retirar os caracteres n�o n�mericos do CPF
void retirarnumcpf( char cpf[15], char cpfnumerico[15])
{
    int contagem = 0;
    int numero = 0;

    //For Loop -> Vai do primeiro elemento do CPF [0] at� o �ltimo
    //Como CPF � string, o �ltimo elemento � o caractere nulo ('\0') -> Ele � o flag de parada
    //Caso o caractere seja num�rico, ele � armazenado em outra string (cpnumerico)
    //Ap�s o Loop, � incluido o caractere nulo para que a string (cpfnumerico) seja mantido como uma string
    //Como a string � mantida, ela n�o vai ignorar o zero. Caso fosse tipo int, o zero no cpf seria excluido e daria erro

    for(contagem = 0; cpf[contagem] != '\0'; contagem++){
        if(isdigit(cpf[contagem])){
            cpfnumerico[numero++] = cpf[contagem];
        }
    }
    cpfnumerico[numero] = '\0';
}

    //Fun��o para verificar se o CPF possui 11 d�gitos
void verificardig(char cpfnumerico[15])
{
    int numdig;

    numdig = strlen(cpfnumerico);   //Armazena o tamanho da string em outra vari�vel, sendo essa do tipo int

        //Caso o CPF (j� num�rico) n�o tenha 11 d�gitos, o CPF � dado como inv�lido e o programa interrompido
    if (numdig != 11){
        printf("\nO CPF inserido � inv�lido!!");
        return 0;
    }
    else{
        printf("\nVerifica��o do n�mero de d�gitos conclu�da!");
    }
}

    //Fun��o para validar o primeiro d�gito verificador
void verificarprimeirodig(char cpfnumerico[15])
{
    int contagem;
    int fatorial = 10;
    int soma = 0;
    int resto = 0;
    int digitoverificador;

        //For Loop para realizar a soma da f�rmula de valida��o do CPF
    for(contagem = 0; contagem < 9; contagem++){
        soma += charparaint(cpfnumerico[contagem]) * fatorial;
        fatorial--;
    }
    printf("\nA soma total dos 9 d�gitos deu %i", soma);

    resto = (soma * 10) % 11;

    printf("\nE o resto dessa soma deu %i", resto);

    if(resto == 10){
        resto = 0; //Caso o resto de 10, tem que ser considerado como zero caso o d�gito verificador seja zero
    }

    digitoverificador = charparaint(cpfnumerico[9]); //Converte o d�gito verificador para inteiro e armazena em outra vari�vel

        //Segue a f�rmula de valida��o
        //caso o resto seja diferente do d�gito verificado, � dado como CPF inv�lido e o programa interrompido
    if(resto != digitoverificador){
        printf("\nVerifica��o do primeiro d�gito inv�lida!!");
        return 0;
    }
    else if(resto == digitoverificador){
        printf("\nValida��o do primeiro d�gito conclu�da! ");
    }
}

    //Fun��o para validar o segundo d�gito verificador
void verificarsegundodig(char cpfnumerico[15])
{
    int contagem;
    int soma = 0;
    int fatorial = 11;
    int resto = 0;
    int digitoverificador;

        //For Loop -> Realiza a soma seguindo a f�rmula de valida��o do d�gito verificador
    for(contagem = 0; contagem < 10; contagem++){
        soma += charparaint(cpfnumerico[contagem]) * fatorial;
        fatorial--;
    }
    printf("\nA soma total dos 10 d�gitos deu %i", soma);

    resto = (soma * 10) % 11;

    printf("\nE o resto dessa mesma soma deu %i", resto);

    digitoverificador = charparaint(cpfnumerico[10]);//Converte o d�gito verificador para inteiro e armazena em outra vari�vel

        //Segue a f�rmula de valida��o
        //Caso o resto seja diferente do d�gito verificador, � dado como CPF inv�lido e o programa interrompido
        //Sen�o, a valida��o � feita com sucesso
    if(resto != digitoverificador){
        printf("\nVerifica��o do segundo d�gito inv�lida!!");
        return 0;
    }
    else if(resto == digitoverificador)
        printf("\nValida��o do segundo d�gito conclu�da! ");
}

    //Fun��o Principal
main()
{
    char cpf[15]; //CPF oferecido pelo usu�rio
    char cpfnumerico[15]; //CPF somente n�mero

    //Possibilita escrever acentos e grafias da l�ngua portuguesa na tela
    setlocale(LC_ALL, "Portuguese");

    printf("Bem-vindo(a) ao Sistema de Valida��o de CPF UFCAT! \n\n");
    printf("Digite aqui seu CPF para verificarmos sua valida��o: ");
    scanf("%s", cpf);

    printf("\n\nAqui est� seu CPF: %s", cpf);

    //Fun��o para retirar caracteres n�o-num�ricos do CPF
    retirarnumcpf(cpf, cpfnumerico);

    printf("\nAgora aqui est� o CPF num�rico: %s", cpfnumerico);

    //Fun��o para verificar se o CPF possui 11 d�gitos
    verificardig(cpfnumerico);

    printf("\n\nProsseguimos agora com a verifica��o do primeiro d�gito!");

    //Fun��o para validar o primeiro d�gito verificador do CPF
    verificarprimeirodig(cpfnumerico);

    printf("\n\nFinalmente vamos agora para a verifica��o do segundo d�gito!");

    //Fun��o para validar o segundo d�gito verificador do CPF
    verificarsegundodig(cpfnumerico);

        //Caso todas as verifica��es sejam validadas, o CPF inserido � valido
    if(verificardig && verificarprimeirodig && verificarsegundodig){
        printf("\n\nO CPF inserido � v�lido!!\n");
    }

    return 0;
}
