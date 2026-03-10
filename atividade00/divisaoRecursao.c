#include <stdio.h>

int divisao(int a, int b) {
    if (a < b) { // caso base
        return 0;
    } else {
        return 1 + divisao(a - b, b); // chamada recursiva
    }
}

int main() {
    int a, b;

    printf("Dividendo: ");
    scanf("%d", &a);

    printf("Divisor: ");
    scanf("%d", &b);

    int resultado = divisao(a, b);

    printf("Resultado: %d\n", resultado);

    return 0;
}