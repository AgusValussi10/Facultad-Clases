/*
Agregar a la lista una función que permite eliminar un nodo con un valor específico 
(por ejemplo, 15) y luego mostrar la lista resultante.
*/

#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura Nodo
struct Nodo {
    int dato;                  // Dato que almacena el nodo
    struct Nodo* siguiente;    // Puntero al siguiente nodo en la lista
};
// Función para insertar un nuevo nodo al final de la lista
void insertarAlFinal(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}   
// Función para eliminar un nodo con un valor específico
void eliminarEspecifico(struct Nodo** cabeza, int valor) {
    if (*cabeza == NULL) {
        return;
    }
    struct Nodo* temp = *cabeza;
    struct Nodo* anterior = NULL;
    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        return;
    }
    if (anterior == NULL) {
        *cabeza = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }
    free(temp);
}
// Función para mostrar todos los elementos de la lista enlazada
void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}
// Función principal que gestiona la inserción de elementos en la lista y la eliminación
int main() {
    struct Nodo* cabeza = NULL;
    insertarAlFinal(&cabeza, 10);
    insertarAlFinal(&cabeza, 20);
    insertarAlFinal(&cabeza, 30);
    insertarAlFinal(&cabeza, 15);
    insertarAlFinal(&cabeza, 25);
    printf("Lista original: ");
    mostrarLista(cabeza);
    int valorAEliminar = 15;
    printf("Eliminando el valor %d de la lista...\n", valorAEliminar);
    eliminarEspecifico(&cabeza, valorAEliminar);
    printf("Lista después de eliminar %d: ", valorAEliminar);
    mostrarLista(cabeza);
    // Liberar la memoria de la lista
    struct Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    return 0;
}
