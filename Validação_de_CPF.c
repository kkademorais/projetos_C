#include <stdio.h>
#include <locale.h> //Biblioteca para escrever acentos e grafias da língua portuguesa na tela
#include <ctype.h> //Biblioteca para manipulação de caracteres -> Retira caracteres não numéricos (isdigit)
#include <string.h> //Biblioteca para análise de string -> Verificar tamanho da string (strlen)


    //Função para converter o valor de um caractere numérico para seu valor inteiro
    //Utiliza da tabela ASCII
    //Subtrai o valor do caractere '0' para obter o valor do número inteiro correspondente
int charparaint(char caractere)
{
    return caractere - '0';
}

    //Função para retirar os caracteres não númericos do CPF
void retirarnumcpf( char cpf[15], char cpfnumerico[15])
{
    int contagem = 0;
    int numero = 0;

    //For Loop -> Vai do primeiro elemento do CPF [0] até o último
    //Como CPF é string, o último elemento é o caractere nulo ('\0') -> Ele é o flag de parada
    //Caso o caractere seja numérico, ele é armazenado em outra string (cpnumerico)
    //Após o Loop, é incluido o caractere nulo para que a string (cpfnumerico) seja mantido como uma string
    //Como a string é mantida, ela não vai ignorar o zero. Caso fosse tipo int, o zero no cpf seria excluido e daria erro

    for(contagem = 0; cpf[contagem] != '\0'; contagem++){
        if(isdigit(cpf[contagem])){
            cpfnumerico[numero++] = cpf[contagem];
        }
    }
    cpfnumerico[numero] = '\0';
}

    //Função para verificar se o CPF possui 11 dígitos
int verificardig(char cpfnumerico[15])
{
    int numdig;

    numdig = strlen(cpfnumerico);   //Armazena o tamanho da string em outra variável, sendo essa do tipo int

        //Caso o CPF (já numérico) não tenha 11 dígitos, o CPF é dado como inválido e o programa interrompido
    if (numdig != 11){
        printf("\nO CPF inserido é inválido!! \n");
        return 0;
    }
    else{
        printf("\nVerificação do número de dígitos concluída!");
        return 1;
    }
}

    //Função para validar o primeiro dígito verificador
int verificarprimeirodig(char cpfnumerico[15])
{
    int contagem;
    int fatorial = 10;
    int soma = 0;
    int resto = 0;
    int digitoverificador;

        //For Loop para realizar a soma da fórmula de validação do CPF
    for(contagem = 0; contagem < 9; contagem++){
        soma += charparaint(cpfnumerico[contagem]) * fatorial;
        fatorial--;
    }
    printf("\nA soma total dos 9 dígitos deu %i", soma);

    resto = (soma * 10) % 11;

    printf("\nE o resto dessa soma deu %i", resto);

    if(resto == 10){
        resto = 0; //Caso o resto de 10, tem que ser considerado como zero caso o dígito verificador seja zero
    }

    digitoverificador = charparaint(cpfnumerico[9]); //Converte o dígito verificador para inteiro e armazena em outra variável

        //Segue a fórmula de validação
        //caso o resto seja diferente do dígito verificado, é dado como CPF inválido e o programa interrompido
    if(resto != digitoverificador){
        printf("\nVerificação do primeiro dígito inválida!! \n");
        return 0;
    }
    else if(resto == digitoverificador){
        printf("\nValidação do primeiro dígito concluída! ");
        return 1;
    }
}

    //Função para validar o segundo dígito verificador
int verificarsegundodig(char cpfnumerico[15])
{
    int contagem;
    int soma = 0;
    int fatorial = 11;
    int resto = 0;
    int digitoverificador;

        //For Loop -> Realiza a soma seguindo a fórmula de validação do dígito verificador
    for(contagem = 0; contagem < 10; contagem++){
        soma += charparaint(cpfnumerico[contagem]) * fatorial;
        fatorial--;
    }
    printf("\nA soma total dos 10 dígitos deu %i", soma);

    resto = (soma * 10) % 11;

    printf("\nE o resto dessa mesma soma deu %i", resto);

    digitoverificador = charparaint(cpfnumerico[10]);//Converte o dígito verificador para inteiro e armazena em outra variável

        //Segue a fórmula de validação
        //Caso o resto seja diferente do dígito verificador, é dado como CPF inválido e o programa interrompido
        //Senão, a validação é feita com sucesso
    if(resto != digitoverificador){
        printf("\nVerificação do segundo dígito inválida!! \n");
        return 0;
    }
    else if(resto == digitoverificador)
        printf("\nValidação do segundo dígito concluída! ");
        return 1;
}

    //Função para verificar se o CPF inserido possui todos os dígitos iguais
int verificardigiguais(char cpfnumerico[15])
{
    if(charparaint(cpfnumerico[0]) == charparaint(cpfnumerico[1]) &&
       charparaint(cpfnumerico[1]) == charparaint(cpfnumerico[2]) &&
       charparaint(cpfnumerico[2]) == charparaint(cpfnumerico[3]) &&
       charparaint(cpfnumerico[3]) == charparaint(cpfnumerico[4]) &&
       charparaint(cpfnumerico[4]) == charparaint(cpfnumerico[5]) &&
       charparaint(cpfnumerico[5]) == charparaint(cpfnumerico[6]) &&
       charparaint(cpfnumerico[6]) == charparaint(cpfnumerico[7]) &&
       charparaint(cpfnumerico[7]) == charparaint(cpfnumerico[8]) &&
       charparaint(cpfnumerico[8]) == charparaint(cpfnumerico[9])){
        printf("\nO CPF inserido é inválido, possui dígitos iguais! \n");
        return 0;
       }

}

    //Função Principal
main()
{
    char cpf[15]; //CPF oferecido pelo usuário
    char cpfnumerico[15]; //CPF somente número
    char validadedocpf;

    //Possibilita escrever acentos e grafias da língua portuguesa na tela
    setlocale(LC_ALL, "Portuguese");

    printf("Bem-vindo(a) ao Sistema de Validação de CPF UFCAT! \n\n");
    printf("Digite aqui seu CPF para verificarmos sua validação: ");
    scanf("%s", cpf);

    printf("\n\nAqui está seu CPF: %s", cpf);

    //Função para retirar caracteres não-numéricos do CPF
    retirarnumcpf(cpf, cpfnumerico);

    printf("\nAgora aqui está o CPF numérico: %s", cpfnumerico);

    //Função para verificar se o CPF inserido possui todos os dígitos iguais
    if(!verificardigiguais(cpfnumerico))
        return 0;   //Se o CPF não passar dessa verificação, o programa é encerrado aqui

    //Função para verificar se o CPF possui 11 dígitos
    if(!verificardig(cpfnumerico))
        return 0;   //Se o CPF não passar dessa verificação, o programa é encerrado aqui

    printf("\n\nProsseguimos agora com a verificação do primeiro dígito!");

    //Função para validar o primeiro dígito verificador do CPF
    if(!verificarprimeirodig(cpfnumerico))
        return 0;   //Se o CPF não passar dessa verificação, o programa é encerrado aqui

    printf("\n\nFinalmente vamos agora para a verificação do segundo dígito!");

    //Função para validar o segundo dígito verificador do CPF
    if(!verificarsegundodig(cpfnumerico))
        return 0;   //Se o CPF não passar dessa verificação, o programa é encerrado aqui

        //Caso todas as verificações sejam validadas, o CPF inserido é valido
    if(verificardig && verificarprimeirodig && verificarsegundodig){
        printf("\n\nO CPF inserido é válido!!\n");
    }

    return 0;
}
