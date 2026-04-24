#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"

int main() {
    srand(time(NULL)); 
    clock_t inicio, fim;

    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo CSV.\n");
        return 1;
    }
    fprintf(arquivo, "Tamanho_N,BubbleSort,MergeSort,BuscaSeq,BuscaBin\n");
    fclose(arquivo);

    printf("=== AUTOMACAO DE ANALISE DE COMPLEXIDADE ===\n");
    printf("Iniciando testes para N = 10000 a N = 100000\n\n");

    for (int n = 10000; n <= 100000; n += 10000) {
        printf("Testando para N = %d...\n", n);

        int* dadosBase = gerarDados(n);
        int* arrBubble = (int*)malloc(n * sizeof(int));
        int* arrMerge = (int*)malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            arrBubble[i] = dadosBase[i];
            arrMerge[i] = dadosBase[i];
        }

        // --- TEMPO DE ORDENAÇÃO ---
        inicio = clock();
        bubbleSort(arrBubble, n);
        fim = clock();
        double tempoBubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        inicio = clock();
        mergeSort(arrMerge, 0, n - 1);
        fim = clock();
        double tempoMerge = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        // --- TEMPO DE BUSCA ---
        int alvo = arrMerge[rand() % n];

        inicio = clock();
        int resSeq = buscaSequencial(arrMerge, n, alvo);
        fim = clock();
        double tempoSeq = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        inicio = clock();
        int resBin = buscaBinaria(arrMerge, n, alvo);
        fim = clock();
        double tempoBin = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        if (resSeq != -1 && resBin != -1) {
            printf(" -> Alvo %d encontrado com sucesso!\n", alvo);
        }

        // --- SALVANDO NO CSV PARA CRIAR O GRAFICO ---
        arquivo = fopen("resultados.csv", "a"); 
        fprintf(arquivo, "%d,%f,%f,%f,%f\n", n, tempoBubble, tempoMerge, tempoSeq, tempoBin);
        fclose(arquivo);

        free(dadosBase);
        free(arrBubble);
        free(arrMerge);
    }

    printf("\nTestes concluidos! Dados salvos em 'resultados.csv'.\n");

    // GNUPLOT 1: GRÁFICO DE ORDENAÇÃO
    printf("\nGerando 'grafico_ordenacao.png'...\n");
    FILE *gnuplotOrd = popen("gnuplot", "w");
    if (gnuplotOrd != NULL) {
        fprintf(gnuplotOrd, "set terminal pngcairo size 800,600 enhanced font 'Arial,12'\n");
        fprintf(gnuplotOrd, "set output 'grafico_ordenacao.png'\n");
        fprintf(gnuplotOrd, "set title 'Analise de Desempenho: Ordenacao (O(n^2) vs O(n log n))'\n");
        fprintf(gnuplotOrd, "set xlabel 'Quantidade de Entradas (n)'\n");
        fprintf(gnuplotOrd, "set ylabel 'Tempo de Execucao (segundos)'\n");
        fprintf(gnuplotOrd, "set grid\n");
        fprintf(gnuplotOrd, "set datafile separator ','\n");
        fprintf(gnuplotOrd, "plot 'resultados.csv' skip 1 using 1:2 with linespoints linewidth 2 title 'Bubble Sort', \\\n");
        fprintf(gnuplotOrd, "     'resultados.csv' skip 1 using 1:3 with linespoints linewidth 2 title 'Merge Sort'\n");
        pclose(gnuplotOrd);
        printf(" -> Ok!\n");
    }

    // GNUPLOT: GRÁFICO DE BUSCA
    printf("Gerando 'grafico_buscas.png'...\n");
    FILE *gnuplotBusca = popen("gnuplot", "w");
    if (gnuplotBusca != NULL) {
        fprintf(gnuplotBusca, "set terminal pngcairo size 800,600 enhanced font 'Arial,12'\n");
        fprintf(gnuplotBusca, "set output 'grafico_buscas.png'\n");
        fprintf(gnuplotBusca, "set title 'Analise de Desempenho: Buscas (O(n) vs O(log n))'\n");
        fprintf(gnuplotBusca, "set xlabel 'Quantidade de Entradas (n)'\n");
        fprintf(gnuplotBusca, "set ylabel 'Tempo de Execucao (segundos)'\n");
        fprintf(gnuplotBusca, "set grid\n");
        fprintf(gnuplotBusca, "set datafile separator ','\n");
        // Coluna 4 (BuscaSeq) e Coluna 5 (BuscaBin)
        fprintf(gnuplotBusca, "plot 'resultados.csv' skip 1 using 1:4 with linespoints linewidth 2 title 'Busca Sequencial', \\\n");
        fprintf(gnuplotBusca, "     'resultados.csv' skip 1 using 1:5 with linespoints linewidth 2 title 'Busca Binaria'\n");
        pclose(gnuplotBusca);
        printf(" -> Ok!\n");
    }

    return 0;
}