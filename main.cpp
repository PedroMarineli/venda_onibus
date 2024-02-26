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
void opcoesPassagem();
void mostrarAssentos(const char*, cadastroPassagem*);

cadastroPassagem passagem[5];

int main(){
    system("clear");
    
    criarPassagem(passagem);
    mostraTitulo("VENDA DE PASSAGENS DE ÔNIBUS");
    mostraOpcoes();
}

void mostraOpcoes(){
    printf("Escolha uma opção:\n\n");
    printf("1. Comprar passagens\n");
    printf("2. Verificar saldo\n");
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
            comprarPassagem();
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

void comprarPassagem(){
    system("clear");
    mostraTitulo("COMPRAR PASSAGENS");
    opcoesPassagem();
}

void opcoesPassagem(){
    printf("Escolha uma cidade:\n\n");
    printf("1. Ibirarema\n");
    printf("2. Salto Grande\n");
    printf("3. Campinas\n");
    printf("4. Ourinhos\n");
    printf("5. Assis\n");
    printf("6. Sair\n");
    
    int opcao;
    std::string cidadeEscolhida;

    printf("\nOpção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            cidadeEscolhida = "Ibirarema";
        case 2:
            cidadeEscolhida = "Salto Grande";
        case 3:
            cidadeEscolhida = "Campinas";
        case 4:
            cidadeEscolhida = "Ourinhos";
        case 5:
            cidadeEscolhida = "Assis";
        case 6:
            main();
        default:
            printf("\nOpção inválida\n");
    }

    if (cidadeEscolhida == "Ibirarema") {
        mostrarAssentos("Ibirarema", &passagem[0]);
    }
    if (cidadeEscolhida == "Salto Grande") {
        mostrarAssentos("Salto Grande");
    }
    if (cidadeEscolhida == "Campinas") {
        mostrarAssentos("Campinas");
    }
    if (cidadeEscolhida == "Ourinhos") {
        mostrarAssentos("Ourinhos");
    }
    if (cidadeEscolhida == "Assis") {
        mostrarAssentos("Assis");
    }
}

void mostrarAssentos(const char assento[],cadastroPassagem *passagem){
    for (i=0; condition; inc-expression) {
    
    }
}
