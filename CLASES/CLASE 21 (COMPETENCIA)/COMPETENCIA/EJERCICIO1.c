#include <stdio.h>

// Declaración de las funciones
int esPrimo(int n);
int contarPrimos(int arr[], int tam);

int main() {
    int numeros[10]; // Arreglo para guardar los 10 números ingresados por el usuario

    // Se pide al usuario ingresar 10 números
    printf("Ingresa 10 números enteros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]); // Se almacenan en el arreglo
    }

    // Se llama a la función contarPrimos y se guarda el resultado
    int cantidadPrimos = contarPrimos(numeros, 10);

    // Se muestra cuántos primos fueron encontrados
    printf("Cantidad de números primos: %d\n", cantidadPrimos);

    return 0;
}

// Definición de la función que cuenta y muestra los números primos del arreglo
int contarPrimos(int arr[], int tam) {
    int cantidad = 0;
    printf("Números primos encontrados:\n");

    // Recorre cada número del arreglo
    for (int i = 0; i < tam; i++) {
        if (esPrimo(arr[i])) { // Verifica si es primo
            printf("%d ", arr[i]); // Lo muestra en pantalla
            cantidad++; // Aumenta el contador de primos
        }
    }
    printf("\n");
    return cantidad; // Retorna la cantidad total de primos encontrados
}

// Definición de la función que determina si un número es primo
int esPrimo(int n) {
    if (n <= 1) return 0; // Los números menores o iguales a 1 no son primos

    // Se prueba dividir n por todos los números desde 2 hasta su raíz cuadrada
    for (int i = 2; i * i <= n; i++) { // i * i <= n es el condicional del bucle
        if (n % i == 0) return 0; // Si es divisible por algún número, no es primo
    }
    return 1; // Si no tuvo divisores, es primo
}

