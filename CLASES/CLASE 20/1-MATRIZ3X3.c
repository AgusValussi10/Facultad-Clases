// Escribir un programa que permita cargar como entrada una matriz 3x3 de numeros enteros por teclado.
// Mostrar la matriz usando un procdeimiento.
// Usar una sentencia switch switch para seleccionar el caluclo que desea realizar: 
// 1- Calcular la posicion de punto de silla si existe. Usar un procedimiento o funcion segun
// considere necesario, un punto de silla de una matriz es un elemento que es a la vez el elemento mas grande
// de su columna y el elemento mas pequeno de su fila.
// Determinar si la matriz es un cuadro magico o no (un cuadrado magico es una matriz de 3x3 formada por
// numeros del 1 al 9, donde la suma de sus filas, sus columnas y sus diagonales es la misma). Usar una funcion
// o un procedimiento segun considere necesario.
// 3- Sumar las filas o las columnas para calcular el cuadrado magico.

#include <stdio.h>

#define SIZE 3

// Procedimiento para mostrar la matriz por pantalla
void mostrarMatriz(int matriz[SIZE][SIZE]) {
    printf("\nMatriz actual:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", matriz[i][j]); // Mostrar cada elemento con formato
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }
}

// Función para buscar un punto de silla en la matriz
// Retorna 1 si se encuentra, 0 si no.
// Los parámetros fila y col devuelven la posición del punto de silla encontrado.
int puntoDeSilla(int matriz[SIZE][SIZE], int *fila, int *col) {
    // Recorrer cada fila para encontrar el mínimo elemento de la fila
    for (int i = 0; i < SIZE; i++) {
        int minFila = matriz[i][0];
        int colMin = 0;

        // Buscar mínimo en fila i
        for (int j = 1; j < SIZE; j++) {
            if (matriz[i][j] < minFila) {
                minFila = matriz[i][j];
                colMin = j;
            }
        }

        // Verificar si el mínimo de la fila es el máximo de su columna
        int esMaxCol = 1;
        for (int k = 0; k < SIZE; k++) {
            if (matriz[k][colMin] > minFila) {
                esMaxCol = 0; // No es punto de silla
                break;
            }
        }

        // Si se cumple la condición, guardar posición y retornar éxito
        if (esMaxCol) {
            *fila = i;
            *col = colMin;
            return 1;
        }
    }
    return 0; // No se encontró punto de silla
}

// Función para verificar si la matriz es un cuadrado mágico
// Retorna 1 si es cuadrado mágico, 0 si no
int esCuadradoMagico(int matriz[SIZE][SIZE]) {
    int sumaEsperada = 0;

    // Validar que los números estén entre 1 y 9 y no se repitan
    int contador[10] = {0}; // Índices del 1 al 9 usados para contar apariciones
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int val = matriz[i][j];
            if (val < 1 || val > 9) return 0;  // Número fuera del rango válido
            contador[val]++;
            if (contador[val] > 1) return 0;   // Número repetido
        }
    }

    // Calcular la suma que se espera en filas, columnas y diagonales
    for (int j = 0; j < SIZE; j++) {
        sumaEsperada += matriz[0][j];
    }

    // Verificar que cada fila sume igual a sumaEsperada
    for (int i = 1; i < SIZE; i++) {
        int sumaFila = 0;
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != sumaEsperada)
            return 0;
    }

    // Verificar que cada columna sume igual a sumaEsperada
    for (int j = 0; j < SIZE; j++) {
        int sumaCol = 0;
        for (int i = 0; i < SIZE; i++) {
            sumaCol += matriz[i][j];
        }
        if (sumaCol != sumaEsperada)
            return 0;
    }

    // Verificar que las diagonales sumen igual a sumaEsperada
    int sumaDiag1 = 0, sumaDiag2 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumaDiag1 += matriz[i][i];
        sumaDiag2 += matriz[i][SIZE - 1 - i];
    }
    if (sumaDiag1 != sumaEsperada || sumaDiag2 != sumaEsperada)
        return 0;

    // Si todas las condiciones se cumplen, es cuadrado mágico
    return 1;
}

// Procedimiento para mostrar la suma de cada fila y columna
void sumarFilasYColumnas(int matriz[SIZE][SIZE]) {
    printf("\nSuma de filas:\n");
    for (int i = 0; i < SIZE; i++) {
        int sumaFila = 0;
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matriz[i][j];
        }
        printf("Fila %d: %d\n", i + 1, sumaFila);
    }

    printf("\nSuma de columnas:\n");
    for (int j = 0; j < SIZE; j++) {
        int sumaCol = 0;
        for (int i = 0; i < SIZE; i++) {
            sumaCol += matriz[i][j];
        }
        printf("Columna %d: %d\n", j + 1, sumaCol);
    }
}

int main() {
    int matriz[SIZE][SIZE];
    int opcion;
    int repetir = 1;

    printf("=== Programa para Matriz 3x3 ===\n\n");

    // Entrada de datos: cargar matriz con validación para números enteros
    printf("Ingrese los elementos de la matriz 3x3 (enteros):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            while (scanf("%d", &matriz[i][j]) != 1) {
                printf("Entrada inválida. Ingrese un número entero para [%d][%d]: ", i, j);
                while(getchar() != '\n'); // limpiar buffer
            }
        }
    }

    // Menú interactivo, se repite hasta que el usuario decida salir
    while (repetir) {
        mostrarMatriz(matriz);

        // Mostrar opciones disponibles
        printf("\nSeleccione una opción:\n");
        printf("1. Buscar punto de silla\n");
        printf("2. Verificar si es un cuadrado mágico\n");
        printf("3. Sumar filas y columnas\n");
        printf("4. Salir\n");
        printf("Opción: ");

        // Validar entrada de opción
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada inválida. Intente nuevamente.\n");
            while(getchar() != '\n'); // limpiar buffer
            continue; // volver a pedir opción
        }

        switch (opcion) {
            case 1: {
                int fila, col;
                // Buscar punto de silla e informar resultado
                if (puntoDeSilla(matriz, &fila, &col)) {
                    printf("\nPunto de silla encontrado en la posición [%d][%d] con valor %d.\n", fila, col, matriz[fila][col]);
                } else {
                    printf("\nNo se encontró punto de silla en la matriz.\n");
                }
                break;
            }
            case 2:
                // Verificar si es cuadrado mágico
                if (esCuadradoMagico(matriz)) {
                    printf("\nLa matriz ES un cuadrado mágico.\n");
                } else {
                    printf("\nLa matriz NO es un cuadrado mágico.\n");
                }
                break;
            case 3:
                // Mostrar suma de filas y columnas
                sumarFilasYColumnas(matriz);
                break;
            case 4:
                // Salir del programa
                printf("\nGracias por usar el programa. ¡Hasta luego!\n");
                repetir = 0;
                break;
            default:
                printf("\nOpción no válida. Por favor, seleccione una opción del 1 al 4.\n");
        }

        if (repetir) {
            printf("\n------------------------------------\n");
        }
    }

    return 0;
}

/*
Resumen paso a paso del programa:

1. Se define una matriz 3x3 y se pide al usuario que ingrese sus elementos, validando que sean números enteros.
2. Se muestra un menú con opciones para:
   a) Buscar un punto de silla en la matriz (elemento que es el mínimo en su fila y máximo en su columna).
   b) Verificar si la matriz es un cuadrado mágico (números del 1 al 9 sin repetir, con filas, columnas y diagonales sumando igual).
   c) Sumar filas y columnas y mostrar los resultados.
   d) Salir del programa.
3. Según la opción elegida, se ejecuta el procedimiento o función correspondiente:
   - Para el punto de silla, se recorre la matriz y se verifica la condición.
   - Para el cuadrado mágico, se valida que los números estén en rango y sin repetición, y que todas las sumas coincidan.
   - Para sumas, simplemente se suman y muestran.
4. El menú se repite hasta que el usuario elija salir.
5. Cada paso tiene mensajes claros para guiar al usuario durante la interacción.

Este programa es útil para entender matrices, búsqueda de condiciones específicas (punto de silla), y propiedades matemáticas (cuadrado mágico).
*/
