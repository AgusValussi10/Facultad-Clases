/*
Crear un programa que pertita: 
A) Encolar una serie de numeros enteros que se ingresan por teclado. 
Ingresar la cantidad de elementos de la cola e indicar por pantalla si la cantida de elementos apilados coincide con el valor requerido.
B) Desencolar los elementos de la cola y cargarlos en un arreglo.
C) Mostrar los elementos del arreglo usando un procedimiento respetando el orden de los elementos desencolados.
D) Ordenar los elementos del arreglo de menor a mayor, usar una funcion.
E) Encolar los elementos del arreglo ordenado.f
F) Desencolar los elementos de la cola y mostrarlos en pantalla respetando el orden de los elementos desencolados.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = 0;
    cola->final = 0;
    return cola;
}
int estaVacia(Cola* cola) {
    return cola->frente == cola->final;
}
int estaLlena(Cola* cola) {
    return cola->final == MAX;
}
void encolar(Cola* cola, int dato) {
    if (!estaLlena(cola)) {
        cola->datos[cola->final++] = dato;
    } else {
        printf("La cola esta llena. No se puede encolar %d\n", dato);
    }
}
int desencolar(Cola* cola) {
    if (!estaVacia(cola)) {
        return cola->datos[cola->frente++];
    } else {
        printf("La cola esta vacia. No se puede desencolar.\n");
        return -1; // Valor de error
    }
}
void mostrarArreglo(int* arreglo, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
void ordenarArreglo(int* arreglo, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arreglo[i] > arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}
int main() {
    Cola* cola = crearCola();
    int cantidad, dato;

    // A) Ingresar la cantidad de elementos que tendrá la cola
    printf("Ingrese la cantidad de elementos que tendrá la cola: ");
    scanf("%d", &cantidad);

    // Ingresar los elementos en la cola
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &dato);
        encolar(cola, dato);
    }

    // Verificar si se pudo encolar la cantidad indicada
    if (cola->final - cola->frente == cantidad) {
        printf("Se pudo encolar la cantidad indicada.\n");
    } else {
        printf("No se pudo encolar la cantidad indicada.\n");
    }

    // B) Desencolar los elementos y cargarlos en un arreglo
    int arreglo[MAX];
    int tam = 0;
    while (!estaVacia(cola)) {
        arreglo[tam++] = desencolar(cola);
    }

    // C) Mostrar los elementos del arreglo
    printf("Elementos del arreglo desencolados: ");
    mostrarArreglo(arreglo, tam);

    // D) Ordenar el arreglo de menor a mayor
    ordenarArreglo(arreglo, tam);
    printf("Arreglo ordenado: ");
    mostrarArreglo(arreglo, tam);

    // E) Encolar los elementos del arreglo ordenado
    for (int i = 0; i < tam; i++) {
        encolar(cola, arreglo[i]);
    }

    // F) Desencolar y mostrar los elementos de la cola
    printf("Elementos desencolados de la cola ordenada: ");
    while (!estaVacia(cola)) {
        printf("%d ", desencolar(cola));
    }
    
    // Liberar memoria
    free(cola);
    
    return 0;
}
