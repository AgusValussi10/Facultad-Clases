/* 
Escribir una función que permita buscar si un número dado está en una lista enlazada. 
Si está, mostrar un mensaje "Número encontrado", si no, "No encontrado".
*/

#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura Nodo
struct Nodo {
    int dato;                  // Dato que almacena el nodo
    struct Nodo* siguiente;    // Puntero al siguiente nodo en la lista
};
// Función para insertar un nuevo nodo al final de la lista
void insertarAlFinal(struct Nodo** cabeza, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
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
// Función para buscar un valor en la lista enlazada
void buscarValor(struct Nodo* cabeza, int valor) {
    struct Nodo* temp = cabeza;
    int encontrado = 0;
    while (temp != NULL) {
        if (temp->dato == valor) {
            encontrado =
            1;
            break;
        }
        temp = temp->siguiente;
    }
    if (encontrado) {
        printf("Número encontrado\n");
    } else {
        printf("No encontrado\n");
    }
}
// Función principal que gestiona la inserción de elementos en la lista y la búsqueda
void funcionPrincipal() {
    struct Nodo* cabeza = NULL;
    int opcion, valor;
    do {
        printf("1. Insertar al final\n");
        printf("2. Buscar valor\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%d", &valor);
                insertarAlFinal(&cabeza, valor);
                break;
            case 2:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                buscarValor(cabeza, valor);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);
}
int main() {
    funcionPrincipal();
    return 0;
}   
