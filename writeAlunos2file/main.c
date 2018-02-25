/*
MP2 17/18: EXERCICIO 4 DA AULA T03

Escrever em ficheiro um conjunto de valores, que definem uma tabela,
em modo texto e em modo binário.
Os valores estão num array de estruturas do tipo Aluno que contém 3 campos:
nome (String), numero (int) e nota (float). Utilize um array com 5 posições.
 
Após executar o programa, visualize o conteúdo dos 2 ficheiros criados e 
tire conclusões sobre a diferença
*/

#include <stdio.h>
#include <string.h>

typedef struct aluno {
    char  nome[100];
    int   numero;
    float nota;
} Aluno;

int main() {

    Aluno a[5] = { // Inicializar o array de Aluno's com dados
        {"Anabela Maria", 34111, 11.5},
        {"Marco Polo",    35222, 10.7},
        {"Paulo Paulino", 36555, 14.2},
        {"Joana Manuela", 45333,  9.8},
        {"Manuel Lopes",  46888, 12.9}
    };

    int        n;
    FILE*      fp;

    // ************* ESCRITA EM MODO TEXTO **************************
    if ((fp = fopen("pauta_alunos.txt", "w")) == NULL) {
        printf("Nao e' possivel abrir o ficheiro\n");
        return 1;
    }
    else {
        for(n=0; n<5; ++n)
            fprintf(fp,"%20s %d %.1f\n", a[n].nome, a[n].numero, a[n].nota);
    }
    fclose(fp);

    // ************* ESCRITA EM MODO BINARIO ************************
    if ((fp = fopen("pauta_alunos.bin", "wb")) == NULL) {
        printf("Nao e' possivel abrir o ficheiro\n");
        return 2;
    }
    else {
        for(n=0; n<5; ++n) {
            fwrite (a[n].nome, sizeof(char), strlen(a[n].nome)+1,fp);
            fwrite (&a[n].numero, sizeof(int),1,fp);
            fwrite (&a[n].nota, sizeof(float),1,fp);
        }
    }
    fclose(fp);
    // **************************************************************

    return 0;
}
