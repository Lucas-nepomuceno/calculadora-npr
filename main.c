#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO_PILHA 300

typedef struct {
    int valores[TAMANHO_MAXIMO_PILHA];
    int tamanho_atual;
} Pilha;

int inicializaPilha(Pilha *endereco_para_pilha) {
    endereco_para_pilha->tamanho_atual = 0;
    return 0;
}

int estaVazia(Pilha *endereco_para_pilha) {
    return endereco_para_pilha->tamanho_atual <= 0;
}

int push(Pilha *endereco_para_pilha, int valor) {
    if (endereco_para_pilha->tamanho_atual >= TAMANHO_MAXIMO_PILHA) return -1;
    endereco_para_pilha->valores[endereco_para_pilha->tamanho_atual++] = valor;
    return 0;
}

int pop(Pilha *endereco_para_pilha) {
    if (estaVazia(endereco_para_pilha)) return -1;
    return endereco_para_pilha->valores[--endereco_para_pilha->tamanho_atual];
}

int main() {
    char expressao[100];
    char *endptr;
    long int operando;
    Pilha pilha;
    inicializaPilha(&pilha);

    printf("Insira sua expressão em NPR (Não usar -1): ");
    fgets(expressao, sizeof(expressao), stdin);
    
    expressao[strcspn(expressao, "\n")] = '\0'; // remove o \n do final

    char *token = strtok(expressao, " ");
    while (token != NULL) {
        operando = strtol(token, &endptr, 10);

        if (*endptr == '\0') {
            // É número válido
            push(&pilha, (int)operando);
        } else {
            int b = pop(&pilha);
            int a = pop(&pilha);

            if (a == -1 || b == -1) {
                printf("Erro: elementos insuficientes na pilha para operação\n");
                return 1;
            }
            int resultado;
            if (strcmp(token, "+") == 0)
                resultado = a + b;
            else if (strcmp(token, "-") == 0)
                resultado = a - b;
            else if (strcmp(token, "*") == 0)
                resultado = a * b;
            else if (strcmp(token, "/") == 0)
                resultado = a / b;
            else {
                printf("Erro de sintaxe: operador desconhecido '%s'\n", token);
                return 1;
            }

            push(&pilha, resultado);
        }

        token = strtok(NULL, " ");
    }

    if (pilha.tamanho_atual == 1) {
        printf("O resultado da expressão é: %d\n", pop(&pilha));
    } else {
        printf("Erro de sintaxe: Verifique sua expressao\n");
    }

    return 0;
}
