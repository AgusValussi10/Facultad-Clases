// Dado un arreglo de 10 elementos positivos diferentes, sin elementos repetidos se pide
// a) Cargar el arreglo en etapa de declaracion
// b) Generar un nuevo vector con aquellos numeros que son multiplos de 3 y otro con el 
// resto de los numeros del vector original
// c) Mostrar los 3 vectores usar procedimientos
// d) Si el arreglo que almacena los numeros multiplos de 3 tiene elementos, se pide:
// 1) Ordenar los elementos de menor a mayor, usar funcion para ordenar
// 2) Completar el arreglo ordenado con multiplos de 3 de tal forma que mantenga la condicion 
// de ordenado (Usar funcion o procedimientos para completar)
// 3) Indicar cuantos elementos fueron agregados

#include <stdio.h>

#define TAM 10

// Procedimiento para mostrar un arreglo
void mostrarArreglo(int arr[], int n, const char* nombre) {
    printf("%s: ", nombre);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para ordenar un arreglo de menor a mayor (método burbuja simple)
void ordenar(int arr[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// Procedimiento para completar el arreglo con múltiplos de 3 manteniendo orden ascendente
// Se agregan múltiplos de 3 mayores que el último elemento actual, hasta completar tamaño total dado
// Retorna la cantidad de elementos agregados
int completarMultiplesDe3(int arr[], int nActual, int nTotal) {
    int agregados = 0;
    int valor = arr[nActual - 1] + 3;  // Siguiente múltiplo de 3 mayor que el último

    while (nActual + agregados < nTotal) {
        arr[nActual + agregados] = valor;
        valor += 3;
        agregados++;
    }

    return agregados;
}

int main() {
    // a) Cargar arreglo en declaración (10 números positivos, diferentes y sin repetidos)
    int original[TAM] = {5, 9, 12, 7, 18, 2, 25, 30, 11, 21};

    int multiplos3[TAM];    // Arreglo para múltiplos de 3 (puede tener menos elementos)
    int resto[TAM];         // Arreglo para resto de números
    int contMult3 = 0;      // Contador de múltiplos de 3
    int contResto = 0;      // Contador de resto

    // b) Generar dos arreglos: múltiplos de 3 y resto
    for (int i = 0; i < TAM; i++) {
        if (original[i] % 3 == 0) {
            multiplos3[contMult3++] = original[i];
        } else {
            resto[contResto++] = original[i];
        }
    }

    // c) Mostrar los 3 vectores
    mostrarArreglo(original, TAM, "Vector original");
    mostrarArreglo(multiplos3, contMult3, "Multiplos de 3");
    mostrarArreglo(resto, contResto, "Resto");

    // d) Si el arreglo de múltiplos de 3 tiene elementos
    if (contMult3 > 0) {
        // 1) Ordenar los múltiplos de 3 de menor a mayor
        ordenar(multiplos3, contMult3);
        printf("\nMultiplos de 3 ordenados:\n");
        mostrarArreglo(multiplos3, contMult3, "Multiplos de 3");

        // 2) Completar el arreglo manteniendo el orden (hasta TAM elementos)
        int agregados = completarMultiplesDe3(multiplos3, contMult3, TAM);
        contMult3 += agregados;

        // Mostrar arreglo completado
        printf("\nMultiplos de 3 completados hasta %d elementos:\n", TAM);
        mostrarArreglo(multiplos3, contMult3, "Multiplos de 3");

        // 3) Indicar cuantos elementos fueron agregados
        printf("Elementos agregados para completar: %d\n", agregados);
    } else {
        printf("\nNo hay múltiplos de 3 en el vector original.\n");
    }

    return 0;
}

/*
Resumen paso a paso del programa:

1. Se declara y carga un arreglo original con 10 números enteros positivos, distintos y sin repetidos.
2. Se recorren los elementos del arreglo original para separar los múltiplos de 3 y el resto en dos arreglos diferentes.
3. Se muestran los tres arreglos: el original, los múltiplos de 3 y el resto.
4. Si hay múltiplos de 3, se ordenan de menor a mayor.
5. Se completa el arreglo de múltiplos de 3 agregando nuevos múltiplos de 3 mayores que el último elemento para llegar a 10 elementos.
6. Se muestra el arreglo completado y se indica la cantidad de elementos agregados.

El programa utiliza procedimientos para mostrar arreglos, ordenar y completar el arreglo de múltiplos de 3.
*/
