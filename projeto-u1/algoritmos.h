#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// FUNÇÕES DE BUSCA
int buscaSequencial(int arr[], int n, int alvo);
int buscaBinaria(int arr[], int n, int alvo);

//FUNÇÕES DE ORDENAÇÃO
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);

// FUNÇÃO AUXILIAR PARA O MERGE SORT
void merge(int arr[], int l, int m, int r);

// FUNÇÃO PARA GERAR DADOS ALEATÓRIOS E SALVAR EM UM ARQUIVO
int* gerarDados(int n);

#endif 