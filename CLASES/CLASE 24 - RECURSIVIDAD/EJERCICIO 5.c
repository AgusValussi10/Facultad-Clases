// Programe un método recursivo que transforme un número entero positivo a notación binaria.

#include <stdio.h>

void decimalABinario(int n);
void funcionPrincipal();

int main() {
    funcionPrincipal();
    return 0;
}

void funcionPrincipal() {
    int numero;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Por favor, ingrese un numero entero positivo.\n");
    } else {
        printf("La representacion binaria de %d es: ", numero);
        decimalABinario(numero);
        printf("\n");
    }
}

void decimalABinario(int n) {
    if (n > 1) {
        decimalABinario(n / 2);
    }
    printf("%d", n % 2);
}


