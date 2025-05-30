// 1) Numeros naturales
// Crear una función recursiva que reciba un número entero positivo n y retorne la suma 
// de todos los números naturales desde 1 hasta n
// Ejemplo: suma(5) = 1 + 2 + 3 + 4 + 5 = 15

#include <stdio.h>

int sumaNaturales(int n);   // Declaración de la función recursiva
void imprimirSuma(int n);   // Nueva función para imprimir la serie
void principal();           // Declaración de la función principal

int main() {
    principal(); // Llamada correcta a la función principal (sin "void")
    return 0;
}

// Función recursiva que calcula la suma
int sumaNaturales(int n) {
    if (n == 1) return 1;
    return n + sumaNaturales(n - 1); 
}

// Imprime la suma como: 1 + 2 + 3 + ... + n
void imprimirSuma(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n)
            printf(" + ");
    }
}

// Función principal
void principal() {
    int n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);

    printf("La suma es: ");
    imprimirSuma(n);
    printf(" = %d\n", sumaNaturales(n));
}
