 /*
 6)
 Fa�a um programa para qualificar a temperatura:
� se a temperatura for menor do que 20oC, ent�o est� frio
� se a temperatura estiver entre 20oC e 30oC, ent�o est�
agrad�vel
� se a temperatura for maior do que 30oC, ent�o est�
quente

OBS:
    Melhoria no c�digo
    Pedir para o usu�rio digitar em qual escala est� sua temperatura digitada
    Realizar a convers�o para Celsius e mostrar na tela
    Avaliar se o tempo est� frio, agrad�vel ou quente
*/

#include <stdio.h>
#include <locale.h>

main()
{
    setlocale(LC_ALL, "Portuguese");
    float temperatura;
    int escala;
    float temperaturaKC;
    float temperaturaFC;

    printf("Voc� chegou ao medidor de temperatura em C!! \n");

while(escala != 3){
    printf("Digite a temperatura atual da sua cidade: ");
    scanf("%f", &temperatura);

    printf("[1] Kelvin \n[2] Fahrenheit \n[3] Celsius \n");
    printf("Agora digite em qual escala est� a temperatura da sua cidade: ");
    scanf("%i", &escala);

    if(escala == 1){
        printf("Vamos realizar a convers�o da sua temperatura de Kelvin para Celsius \n");
        temperaturaKC = temperatura - 273;
        printf("A temperatura da sua cidade em Kelvin � %.1f e em Celsius � %.1f�C \n", temperatura, temperaturaKC);
    }

    else if(escala == 2){
        printf("Vamos realizar a convers�o da sua temperatura de Fahrenheit para Celsius \n");
        temperaturaFC = ((5 * temperatura) - 160) / 9;
        printf("A temperatura da sua cidade em Fahrenheit � %.1f�F e em Celsius � de %.1f�C \n", temperatura, temperaturaFC);
    }

    else if(escala == 3){
        if(temperatura < 20)
            printf("Sua temperatura � de %.1f�C , est� frio!! \n", temperatura);

        else if (20 < temperatura && temperatura < 30)
            printf("Sua temperatura � de %.1f�C, est� um tempo agrad�vel!! \n", temperatura);

        else
            printf("Sua temperatura � de %.1f�C, est� quente!! \n", temperatura);

    }
}


    return 0;
}
