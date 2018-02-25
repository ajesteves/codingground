/*
Aula T03 de MP2 2017/18 - Exercício 3:

Assuma que dispõe de um ficheiro texto "lista.txt" que guarda os dados de 
Empregado's, um por linha, com o formato de linha:

PrimeiroNome UltimoNome Idade

Esrever um programa que lê cada linha do ficheiro para uma variável do tipo 
Empregado, definida no exemplo anterior.

A leitura das linhas deve ser feita com a função: 
void LerEmpregados(FILE *fp);

Após ler uma linha do ficheiro, a função LerEmpregados() escreve no ecrã os 
dados do empregado lido. Pode reutilizar-se a função 
printDadosEmpregado(Empregado e), definida no exemplo anterior.

PARA COMPILAR 
*/

#include <stdio.h>
#include <stdlib.h>

struct 	empregado {
    char  pNome[100];
    char  uNome[100];
    int   idade;
    } ;

typedef struct empregado Empregado;

void printDadosEmpregado(Empregado *emp) {
    printf("--> Nome  do empregado: %s %s\n", emp->pNome, emp->uNome);
    printf("    Idade do empregado: %d\n", emp->idade);
}

// Formato do ficheiro com empregados:
//   PrimeiroNome_1 UltimoNome_1 Idade_1
//   ...
//   PrimeiroNome_N UltimoNome_N Idade_N
//
void LerEmpregados(FILE *fp) {
    Empregado e;
    int       n;

    do {
        n=fscanf(fp,"%s %s %d", e.pNome, e.uNome, &(e.idade));
        if (n == 3)
            printDadosEmpregado(&e);
        else if (n==EOF)
           printf("*** Fim de ficheiro!\n");
        else // (n<3) && (n != EOF)
           printf("*** Linha incompleta!\n");
    } while ( n != EOF );
}


int main(void) {

    FILE *fp;

    if ((fp = fopen("lista.txt", "r")) == NULL) {
        printf("Nao e' possivel abrir o ficheiro %s\n", "lista.txt");
        return EXIT_FAILURE;
    }
    else {
        LerEmpregados(fp);
        fclose(fp);
        return EXIT_SUCCESS;
    }

}
