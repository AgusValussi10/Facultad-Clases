#include <stdio.h>  // Librería estándar para entrada/salida

// Declaración anticipada de la función que calcula el MCM
int lcmCalculate(int a, int b);

int main() {
    int n1, n2, lcmOf;

    // Solicita al usuario el primer número
    printf("Introduce el primer numero: ");
    scanf("%d", &n1);

    // Solicita el segundo número
    printf("Introduce el segundo numero: ");
    scanf("%d", &n2);

    // Llama a la función lcmCalculate con el menor primero
    // para asegurar el orden correcto
    if (n1 > n2)
        lcmOf =  lcmCalculate(n2, n1);
    else
        lcmOf =  lcmCalculate(n1, n2);

    // Muestra el resultado
    printf("El minimo comun multiplo de %d y %d es: %d\n", n1, n2, lcmOf);

    return 0;  // Fin del programa
}

// Función recursiva para calcular el MCM (mínimo común múltiplo)
int lcmCalculate(int a, int b) {
    static int m = 0;  // Variable estática que conserva su valor entre llamadas

    m += b;  // Se suma el valor mayor (b) en cada llamada recursiva

    // Si m es divisible por ambos números, es el MCM
    if ((m % a == 0) && (m % b == 0)) {
        return m;
    } else {
        // Llamada recursiva hasta encontrar el MCM
        lcmCalculate(a, b);
    }
}
