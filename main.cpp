#include <stdio.h>
#include <string.h>
#include <string>

typedef struct 
{
    int id;
    int janela;
    int andar;
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
void verificarDisponibilidade();
void criarPassagem(cadastroPassagem*);

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

void verificarDisponibilidade(){
    
}

void criarPassagem(cadastroPassagem *passagem){
    int i, x=3;
    int numero;
    srand(unsigned(time(NULL))); 
    numero = rand() % 2; 

    passagem->preco = 30;
    passagem->cidade.nome = "Ibirarema";
    if (numero == 0) {
        passagem->cidade.onibus.quantidadeDeAssentos = 46;
    } else {
        passagem->cidade.onibus.quantidadeDeAssentos = 92;
    }
    if (passagem->cidade.onibus.quantidadeDeAssentos > 1) {
        for (i=0; i<46; i++) {
            passagem->cidade.onibus.assento[i].id = i+1;
            passagem->cidade.onibus.assento[i].ativo = 1;
        if (x == 2 || passagem->cidade.onibus.assento[i].id == 1) {
            passagem->cidade.onibus.assento[i].janela = 1;
            x=0;
        }
        x++;
        }
    } 
    if (passagem->cidade.onibus.quantidadeDeAssentos > 46) {
        x=2;
        for (i=46; i<96; i++) {
            passagem->cidade.onibus.assento[i].id = i+1;
            passagem->cidade.onibus.assento[i].ativo = 1;
            passagem->cidade.onibus.assento[i].andar = 1;
        if (x == 2 || passagem->cidade.onibus.assento[i].id == 47) {
            passagem->cidade.onibus.assento[i].janela = 1;
            x=0;
        }
        x++;
        }
    }
}

