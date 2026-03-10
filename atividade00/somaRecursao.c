#include <stdio.h>

int soma(int n) {
    if (n == 1) {   // caso base
        return 1;
    } else {
        return n + soma(n - 1); // chamada recursiva
    }
}

int main() {
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    printf("A soma de 1 até %d é %d\n", n, soma(n));

    return 0;
}