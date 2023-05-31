 /*
 6)
 Faça um programa para qualificar a temperatura:
– se a temperatura for menor do que 20oC, então está frio
– se a temperatura estiver entre 20oC e 30oC, então está
agradável
– se a temperatura for maior do que 30oC, então está
quente

OBS:
    Melhoria no código
    Pedir para o usuário digitar em qual escala está sua temperatura digitada
    Realizar a conversão para Celsius e mostrar na tela
    Avaliar se o tempo está frio, agradável ou quente
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

    printf("Você chegou ao medidor de temperatura em C!! \n");

while(escala != 3){
    printf("Digite a temperatura atual da sua cidade: ");
    scanf("%f", &temperatura);

    printf("[1] Kelvin \n[2] Fahrenheit \n[3] Celsius \n");
    printf("Agora digite em qual escala está a temperatura da sua cidade: ");
    scanf("%i", &escala);

    if(escala == 1){
        printf("Vamos realizar a conversão da sua temperatura de Kelvin para Celsius \n");
        temperaturaKC = temperatura - 273;
        printf("A temperatura da sua cidade em Kelvin é %.1f e em Celsius é %.1fºC \n", temperatura, temperaturaKC);
    }

    else if(escala == 2){
        printf("Vamos realizar a conversão da sua temperatura de Fahrenheit para Celsius \n");
        temperaturaFC = ((5 * temperatura) - 160) / 9;
        printf("A temperatura da sua cidade em Fahrenheit é %.1fºF e em Celsius é de %.1fºC \n", temperatura, temperaturaFC);
    }

    else if(escala == 3){
        if(temperatura < 20)
            printf("Sua temperatura é de %.1fºC , está frio!! \n", temperatura);

        else if (20 < temperatura && temperatura < 30)
            printf("Sua temperatura é de %.1fºC, está um tempo agradável!! \n", temperatura);

        else
            printf("Sua temperatura é de %.1fºC, está quente!! \n", temperatura);

    }
}


    return 0;
}
