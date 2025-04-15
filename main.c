/*  Atividade sobre Hashing
    Aluno: Kaike de Morais Carvalho - 12421BCC051
*/
/*  Refer�ncias:
        https://linguagemc.com.br/localizacao-de-programas-com-locale-h/

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Produto{
    int id; //Sofre o hashing
    char tipo;
    char desc[50];
}Produto;

void hashing(Produto produtosCadastrados[], int numProdutos, Produto produtoCadastrar){
    /*
        Hashing => sondagem linear -> itera��o pelo pr�prio vetor
        TransformFunct => resto da div
    */
    /*
        TransformFunct
            retorna resto div
        ver se tem espaco null
        se != NULL
            incrementa
            compara
            at� que == NULL
        insere
    */

    int indexInserir = transformFunct();
}

void transformFunct(){

}

    //Op��o [1]
void cadastrarProduto(Produto produtosCadastrados[], int numProdutos){
    /*
        Input: DescricaoProduto
        Input: tipoProduto
        Chamar hashing pra saber onde inserir
    */

    printf("\n\n");
    printf("====CADASTRO DE PRODUTO====");
    printf("\n\n");
    //Input da desc
    //Input do tipo
    Produto produtoCadastrar; //Produto a ser cadastrado
    hashing(produtosCadastrados, numProdutos, produtoCadastrar);
}

    //Op��o [2]
void filtrarTipo(Produto produtosCadastrados[], int numProdutos){
    /*
        Input: letra correspondente ao tipoProduto
        Retorna todos os produtos do tipo com a descri��o
    */

    printf("\n\n");
    printf("====TIPOS DISPON�VEIS====");
    printf("\n\n");
    printf("[A] Alimenta��o\n");
    printf("[H] Higiene\n");
    printf("[L] Limpeza\n");
    printf("[V] Vestu�rio\n");
    printf("\n");

    char tipoBusca;
    printf("Digite o tipo que deseja consultar: ");
    /*FALTA: Ler char para busca*/

    //fgets(tipoBusca, sizeof(tipoBusca), stdin);
    //tipoBusca = getchar;

    printf("Tipo a ser buscado: %c\n", tipoBusca);

}

    //Op��o [3]
void contagemProdutos(Produto produtosCadastrados[], int numProdutos){
    /*
        Filtrar produtos
        Realizar contagem aqui nessa funct
        Retorna todos os tipos com a contagem de produtos
    */

    int alimentacao = 0;
    int higiene = 0;
    int limpeza = 0;
    int vestuario = 0;

    for(int i = 0; i < numProdutos; i++){
        if(produtosCadastrados[i].tipo == 'A') alimentacao++;
        if(produtosCadastrados[i].tipo == 'H') higiene++;
        if(produtosCadastrados[i].tipo == 'L') limpeza++;
        if(produtosCadastrados[i].tipo == 'V') vestuario++;
    }

    printf("\n\n");
    printf("====EXIBINDO TIPOS====");
    printf("\n\n");
    printf("Alimenta��o [A] = %d produtos\n", alimentacao);
    printf("Higiene [H] = %d produtos\n", higiene);
    printf("Limpeza [L] = %d produtos\n", limpeza);
    printf("Vestu�rio [V] = %d produtos\n", vestuario);
}

void menu(Produto produtosCadastrados[], int numProdutos){
    while(1){
        printf("\n\n");
        printf("======MENU=====");
        printf("\n\n");
        printf("[1] Cadastrar produto\n");
        printf("[2] Filtrar por tipo\n");
        printf("[3] Contagem de produtos por tipo\n");
        printf("[4] Sair\n");
        printf("\n");

        int opcao;
        printf("Digite a op��o desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nOp��o escolhida: Cadastro de Produtos [1]\n");
                cadastrarProduto(produtosCadastrados, numProdutos);
                break;
            case 2:
                printf("\nOp��o escolhida: Filtrar Produtos por Tipo [2]\n");
                filtrarTipo(produtosCadastrados, numProdutos);
                break;
            case 3:
                printf("\nOp��o escolhida: Contagem de Produtos [3]\n");
                contagemProdutos(produtosCadastrados, numProdutos);
                break;
            case 4:
                printf("\nOp��o escolhida: Sair [4]\n");
                printf("Saindo...");
                break;
            default:
                printf("\nOp��o inv�lida...\n");
                break;
        }
     if(opcao==4) break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numProdutos;

    printf("Quantos produtos ser�o registrados: ");
    scanf("%d", &numProdutos);

    Produto produtosCadastrados[numProdutos];

    menu(produtosCadastrados, numProdutos);

    return 0;
}
