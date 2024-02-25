#include <stdio.h>
#include <string.h>
#include <string>

typedef struct 
{
    int id;
    int ativo;
} cadastroAssento;

typedef struct
{
    int quantidadeDeAssentos;

    cadastroAssento assento[92];
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

void mostraOpcoes();
void mostraTitulo(const char*);
void escolherOpcoes();
void criarPassagem(cadastroPassagem*);
void comprarPassagem();

int main(){
    cadastroPassagem passagem[5];
    criarPassagem(passagem);
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
    int tamanho_titulo = int((strlen(titulo) + 4));

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
            printf("\nOpção inválida\n");
    }
}


void criarPassagem(cadastroPassagem *passagem){
    int i;
    int numero;
    srand(unsigned(time(NULL))); 
    numero = rand() % 2; 

    passagem->preco = 30;
    passagem->cidade.nome = "Ibirarema";
    passagem->cidade.onibus.quantidadeDeAssentos = 46;

    for (i=0; i < 92; i++) {
        passagem->cidade.onibus.assento[i].id = 0;
        passagem->cidade.onibus.assento[i].ativo = 0;
    }
    for (i=0; i < passagem->cidade.onibus.quantidadeDeAssentos; i++) {
        passagem->cidade.onibus.assento[i].id = i+1;
        passagem->cidade.onibus.assento[i].ativo = 1;
    }
}
