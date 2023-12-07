#include <stdio.h>
#include <locale.h>
#include <math.h>

/*  Nome:Kaike de Morais Carvalho
    Matrícula: 202301131
    Algoritmo: Torre de Hanoi
        Objetivo: mover os discos de A para C usando B como auxiliar
*/

    //Chama a função, mudando o nome dos parâmetros para identificar
void hanoi(int numeroDiscos, char origem, char auxiliar, char destino, int *movimento)
{
        //Flag de parada -> último movimento
        //Aqui move o menor disco para o topo do bastão de destino
    if(numeroDiscos == 1){
        printf("\nMovimento %i", *movimento);
        *movimento = *movimento + 1;
        printf("\nMova o disco %i do bastão %c para o bastão %c", numeroDiscos, origem, destino);
        printf("\nDisco %i: %c -> %c \n\n", numeroDiscos, origem, destino);
        return; //Retorna para a função anterior
                //Aqui começa a recursividade no sentido Bottom - up
    }
    else{
        hanoi(numeroDiscos - 1, origem, destino, auxiliar, movimento);
            //Move o disco respectivo do bastão A pro bastão B, usando o bastão C como auxiliar

        printf("\nMovimento %i", *movimento);
        *movimento = *movimento + 1;
        printf("\nMova o disco %i do bastão %c para o bastão %c", numeroDiscos, origem, destino);
        printf("\nDisco %i: %c -> %c \n\n", numeroDiscos, origem, destino);

        hanoi(numeroDiscos - 1, auxiliar, origem, destino, movimento);
            //Move o disco respectivo do bastão B para o bastão C de destino final, usando A como auxiliar
    }
}

main()
{
    int numeroDiscos;
    int numeroMovimentos;
    int movimento = 1;

    setlocale(LC_ALL, "Portuguese");

    printf("\n***Torre de Hanoi***\n");
    printf("Vamos mover os discos dos bastões A para C, utilizando o bastão B como auxiliar\n");

    printf("\nInsira o número de discos que deseja jogar: ");
    scanf("%i", &numeroDiscos);

    numeroMovimentos = pow(2, numeroDiscos) - 1;

    printf("\nPara resolver a Torre de Hanoi com %i discos, você deve realizar %i movimentos, sendo esses os passos: ", numeroDiscos, numeroMovimentos);
    printf("\n");

    hanoi(numeroDiscos, 'A', 'B', 'C', &movimento);
        //Passando como argumentos:
            //Bastão A: origem
            //Bastão B: auxiliar
            //Bastão C: destino

    printf("\n");

    return 0;
}
