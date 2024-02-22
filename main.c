#include <stdio.h>
#include <string.h>

void mostraOpcoes();
void mostraTitulo(char*);

int main(){
    mostraTitulo("VENDA DE PASSAGENS DE ÔNIBUS");
    mostraOpcoes();
}

void mostraOpcoes(){
    printf("Escolha uma opção:\n");
    printf("1. Comprar passagens\n");
    printf("2. Verificar disponibilidade de assentos\n");
    printf("3. Sair\n");
}

void mostraTitulo(char titulo[]){
    int i;
    int tamanho_titulo = (strlen(titulo) + 4);
    for (i=1; i < tamanho_titulo; i++) printf("─");
    printf("\n  %s\n", titulo);
    for (i=1; i < tamanho_titulo; i++) printf("─");
    printf("\n");
}