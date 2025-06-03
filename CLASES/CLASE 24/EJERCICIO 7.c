// Para el siguiente programa, elaborar el enunciado. 

#include <stdio.h>

void leerArreglo(int *arreglo, int indice, int n);

int main() {
    int n;
    scanf("%d", &n);

    int arreglo[n];  // Solo válido en C

    leerArreglo(arreglo, 0, n);
    putchar('\n');
    return 0;
}

void leerArreglo(int *arreglo, int indice, int n) {
    if (indice < n) {
        scanf("%d", &arreglo[indice]);
        leerArreglo(arreglo, indice + 1, n);
    }
}

// Enunciado
// Escribe un programa en C que lea un arreglo de n enteros utilizando una función recursiva.
// La función debe recibir el arreglo, el índice actual y el tamaño del arreglo como parámetros.
// El programa debe solicitar al usuario el tamaño del arreglo y luego leer los elementos uno por uno.
// Finalmente, el programa debe imprimir los elementos del arreglo en una línea separados por espacios.
// Asegúrate de que el programa maneje correctamente la entrada y salida, y que la función recursiva 
// lea todos los elementos del arreglo sin utilizar bucles iterativos.