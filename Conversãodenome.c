#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void nomemais(char nome[30])
{
    printf("\nSeu nome em maíusculo fica: %s", strupr(nome));
    //printf("\nSeu nome com a primeira letra maíuscula fica: %s", toupper(nome[0]));
}

void nomemenos(char nome[30])
{
    printf("\nSeu nome em minúsculo fica: %s", strlwr(nome));
    //printf("Seu nome com a primeira letra minúscula fica: "%s", toupper(nome[0}));
}

main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[30];

    printf("Digite seu nome: ");
    gets(nome);

    printf("Seu nome inserido: %s", nome);

    nomemais(nome);

    nomemenos(nome);

    return 0;
}
