#include <stdio.h>

int multiplicar(int a, int b) {
    if (b == 0) { // caso base
        return 0;
    } else {
        return a + multiplicar(a, b - 1); // chamada recursiva
    }
}

int main() {
    int a, b;

    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);

    int resultado = multiplicar(a, b);

    printf("Resultado da multiplicação: %d\n", resultado);

    return 0;
}