#include <stdio.h>
#include <string.h>
#include <string>

void mostraOpcoes();
void mostraTitulo(const char*);
void escolherOpcoes();
void verificarDisponibilidade();
void criarPassagem();

typedef struct 
{
    int id;
    int janela;
    int andar;
} cadastroAssento;

typedef struct
{
    int quantidadeDeAssentos;

    cadastroAssento assento;
} cadastroOnibus;

typedef struct
{
    std::string nome;

    cadastroOnibus onibus;
} cadadastroCidade;

typedef struct
{ 
    int preco;

    cadadastroCidade cidade;
} cadastroPassagem;

int main(){
    criarPassagem();
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

void mostraTitulo(const char titulo[]){
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

void verificarDisponibilidade(){
    
}

void criarPassagem(){
    cadastroPassagem passagem;
    passagem.preco = 30;
    passagem.cidade.nome = "Ibirarema"; 
    passagem.cidade.onibus.quantidadeDeAssentos = 50;
}

