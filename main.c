#include <stdio.h>
#include <string.h>

void mostraOpcoes();
void mostraTitulo(char*);
void escolherOpcoes();

struct 
{
    int id;
    int janela;
    int andar;
} cadastroAssento[50];

struct
{
    int quantidadeDeAssentos;
} cadastroOnibus[2];

struct
{
    char nome[40];
} cadadastroCidade[5];

struct
{
    int preco;

    struct cadadastroCidade cidade;
} cadastroPassagem;

int main(){
    mostraTitulo("VENDA DE PASSAGENS DE ÔNIBUS");
    mostraOpcoes();
}

void mostraOpcoes(){
    printf("Escolha uma opção:\n\n");
    printf("1. Comprar passagens\n");
    printf("2. Verificar disponibilidade de assentos\n");
    printf("3. Sair\n");
    
    escolherOpcoes();
}

void mostraTitulo(char titulo[]){
    int i;
    int tamanho_titulo = (strlen(titulo) + 4);

    for (i=1; i < tamanho_titulo; i++) printf("─");
    printf("\n  %s\n", titulo);
    for (i=1; i < tamanho_titulo; i++) printf("─");
    printf("\n");
}

void escolherOpcoes(){
    int opcao;

    printf("\nOpção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Opção inválida\n");
    }
}