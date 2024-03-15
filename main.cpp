#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <thread>

typedef struct 
{
    int id;
    int ativo;
    int possui;
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
void criarPassagem(cadastroPassagem*, const char*);
void comprarPassagem();
void opcoesPassagem();
void mostrarAssentos(const char*, cadastroPassagem*);
void escolherAssento(cadastroPassagem*);
void verificarPassagens();
void adicionarSaldo();
void consultarSaldo();

cadastroPassagem passagem[5];
float saldo = 100;
int num_passagens = 0;


int main(){
    system("clear");
    if (passagem[0].cidade.nome == "ibirarema" ) {
        mostraTitulo("VENDA DE PASSAGENS DE ÔNIBUS");
        mostraOpcoes();
    }else {
        criarPassagem(&passagem[0], "ibirarema");
        criarPassagem(&passagem[1], "Salto Grande");
        criarPassagem(&passagem[2], "Campinas");
        criarPassagem(&passagem[3], "Ourinhos");
        criarPassagem(&passagem[4], "Assis");
        mostraTitulo("VENDA DE PASSAGENS DE ÔNIBUS");
        mostraOpcoes();
    }
}

void mostraOpcoes(){
    printf("Escolha uma opção:\n\n");
    printf("1. Comprar passagens\n");
    printf("2. Verificar passagens\n");
    printf("3. Adicionar saldo\n");
    printf("4. Consultar saldo\n");
    printf("5. Sair\n");
    printf("\nColocar uma opção inválida encerrará o programa.\n");
    
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
            break;
        case 2:
            verificarPassagens();
            break;
        case 3:
            adicionarSaldo();
            break;
        case 4:
            consultarSaldo();
            break;
        case 5:
            break;
        default:
            printf("\nOpção inválida\nEncerrando programa...\n");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
    }
}


void criarPassagem(cadastroPassagem *passagem, const char nome[]){
    int i;

    passagem->preco = 30;
    passagem->cidade.nome = nome;
    passagem->cidade.onibus.quantidadeDeAssentos = 48;

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
            break;
        case 2:
            cidadeEscolhida = "Salto Grande";
            break;
        case 3:
            cidadeEscolhida = "Campinas";
            break;
        case 4:
            cidadeEscolhida = "Ourinhos";
            break;
        case 5:
            cidadeEscolhida = "Assis";
            break;
        case 6:
            main();
        default:
            printf("\nOpção inválida\nRetornando ao menu...\n");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            main();
            break;
    }

    if (cidadeEscolhida == "Ibirarema") {
        mostrarAssentos("Ibirarema", &passagem[0]);
    }
    if (cidadeEscolhida == "Salto Grande") {
        mostrarAssentos("Salto grande", &passagem[1]);
    }
    if (cidadeEscolhida == "Campinas") {
        mostrarAssentos("Campinas", &passagem[2]);
    }
    if (cidadeEscolhida == "Ourinhos") {
        mostrarAssentos("Ourinhos", &passagem[3]);
    }
    if (cidadeEscolhida == "Assis") {  
        mostrarAssentos("Assis", &passagem[4]);
    }
}

void mostrarAssentos(const char assento[],cadastroPassagem *passagem){
    int i;
    system("clear");
    mostraTitulo("ESCOLHA DE ASSENTOS");
    printf("CIDADE: %s\n", assento);
    printf("------------------------------------------------\n");
    for (i=0; i < passagem->cidade.onibus.quantidadeDeAssentos; i++) {
        printf("[x]| Id: %02d | Id: %02d |////| Id: %02d | Id: %02d |[x]\n", passagem->cidade.onibus.assento[i].id, passagem->cidade.onibus.assento[i+1].id, passagem->cidade.onibus.assento[i+2].id, passagem->cidade.onibus.assento[i+3].id);
        i = i+3;
    }
    printf("------------------------------------------------\n");
    printf("\n[x] = Janela.  //// = Corredor.\nPressione '0' para retornar ao menu.\n");

    escolherAssento(passagem);
}

void escolherAssento(cadastroPassagem *passagem){
    int assento;
    printf("\nEscolha seu assento: ");
    scanf("%d", &assento);
    assento--;
    if (assento == -1) {
        main();
    }else if (passagem->cidade.onibus.assento[assento].ativo == 0 || assento < 0 || assento > 48) {
        printf("\nEste assento não está disponível!\nRetornando ao menu em 5 segundos...\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        main();
    }else if (saldo <= passagem->preco) {
        printf("\nSaldo indisponível!\nRetornando ao menu em 5 segundos...\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        main();
    }else {
        passagem->cidade.onibus.assento[assento].ativo = 0;
        passagem->cidade.onibus.assento[assento].possui = 1;
        saldo = saldo - passagem->preco;
        num_passagens++;
        printf("\nNovo saldo: %.2f\n", saldo);
        printf("\nPassagem adquirida com sucesso!\nRetornando ao menu em 5 segundos...\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        main();
    }
}

void verificarPassagens(){
    system("clear");
    int i, x, wait;
    mostraTitulo("MINHAS PASSAGENS");
    for (i=0; i<5; i++) {
        for (x=0; x<92; x++) {
            if (passagem[i].cidade.onibus.assento[x].possui == 1) {
                printf("---------------------\n");
                printf("Cidade = %s \nId = %d\n", passagem[i].cidade.nome.c_str(), passagem[i].cidade.onibus.assento[x].id);
                printf("---------------------\n\n");
            }
        }
    }
    printf("Pressione '1' para voltar ao menu...");
    scanf("%d", &wait);
    main();
}

void adicionarSaldo(){
    system("clear");
    float valor;

    mostraTitulo("ADICIONAR SALDO");

    printf("Valor para adicionar: ");
    scanf("%f", &valor);
    if (valor < 0) {
        printf("\nNão é possivel adicionar valores negativos!\nRetornando ao menu em 5 segundos...\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        main();
    }else {
        saldo = saldo + valor;
        printf("\nValor adicionado com sucesso!\nRetornando ao menu em 5 segundos...\n");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        main();
    }
    
}

void consultarSaldo(){
    system("clear");
    mostraTitulo("CONSULTAR SALDO");

    printf("\nSaldo atual: %.2f \n\nRetornando ao menu em 5 segundos...\n", saldo);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    main();
}