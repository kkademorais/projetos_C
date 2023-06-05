#include <stdio.h>
#include <locale.h>

main()
{
    setlocale(LC_ALL, "Portuguese");

    float dinheiro = 0;
    float deposito;
    float saque;
    float dinsacado;
    int option = 0;

    printf("Desafio 21 -> Fazer um caixa eletr�nico \n\n");

    while(option != 4){
        printf("\n Voc� est� no Caixa UFCAT! \n");
        printf("[1] Depositar dinheiro \n[2] Ver saldo dispon�vel \n[3] Sacar dinheiro dispon�vel \n[4] Sair do programa \n");
        printf("Digite a op��o que deseja: ");
        scanf("%i", &option);

        if(option == 1){
            printf("\n Opera��o escolhida: DEP�SITO \n\n");
            printf("Digite a quantia de dinheiro que deseja depositar: ");
            scanf("%f", &deposito);

            dinheiro += deposito;
            printf("Voc� depositou R$%.2f na sua conta! \n", deposito);
        }

        else if(option == 2){
            printf("\n Opera��o escolhida: VER SALDO \n\n");

            if(dinheiro == 0){
                printf("Saldo inexistente, deposite algum valor e verifique novamente \n");
                printf("Saldo = R$00,00 \n");
            }

            else
                printf("Seu saldo atual � de R$%.2f ! \n", dinheiro);
        }

        else if(option == 3){
            printf("\n Opera��o escolhida: SACAR DINHEIRO \n\n");

            if(dinheiro == 0){
                printf("Saque indispon�vel, deposite algum valor e tente novamente \n");
                printf("Saldo = R$00,00 \n");
            }

            else{
                printf("Seu saldo atual � de R$%.2f \n", dinheiro);
                printf("Digite o valor que deseja sacar de seu saldo: ");
                scanf("%f", &saque);

                printf("Voc� sacou R$%.2f da sua conta \n", saque);
                dinsacado = dinheiro - saque;
                printf("Seu saldo atual � de R$%.2f ! \n", dinsacado);
                dinheiro = dinsacado;
            }
        }

        else if(option == 4){
            printf("\n Opera��o escolhida: SAIR \n\n");
            printf("Volte sempre! :) \n");
            return 0;
        }
    }
    return 0;
}
