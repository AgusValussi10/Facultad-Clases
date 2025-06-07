/* Modificar el ejercicio anterior para que los elementos se agreguen al final de la lista. Luego, mostrar la lista completa. */

#include <stdio.h>
#include <stdlib.h>
// Definición de la estructura Nodo
struct Nodo {
    int dato;                  // Dato que almacena el nodo
    struct Nodo* siguiente;    // Puntero al siguiente nodo en la lista
};
// Función para insertar un nuevo nodo al final de la lista
void insertarAlFinal(struct Nodo** cabeza, int valor) {
    // Reserva de memoria para el nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;            // Asignar el valor al nuevo nodo
    nuevoNodo->siguiente = NULL;        // El nuevo nodo será el último, por lo que su siguiente es NULL

    if (*cabeza == NULL) {              // Si la lista está vacía
        *cabeza = nuevoNodo;             // El nuevo nodo se convierte en la cabeza de la lista
    } else {
        struct Nodo* temp = *cabeza;     // Usar un puntero temporal para recorrer la lista
        while (temp->siguiente != NULL) { // Avanzar hasta el último nodo
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;     // Enlazar el nuevo nodo al final de la lista
    }
}
// Función para mostrar todos los elementos de la lista enlazada
void mostrarLista(struct Nodo* nodo) {
    while (nodo != NULL) {
        printf("%d -> ", nodo->dato);   // Imprimir el dato del nodo actual
        nodo = nodo->siguiente;         // Avanzar al siguiente nodo
    }
    printf("NULL\n");                  // Fin de la lista
}
// Función principal que gestiona la inserción de elementos en la lista
void funcionPrincipal() {
    struct Nodo* lista = NULL;  // Inicialización de la lista como vacía
    int valor;
    char opcion;

    do {
        printf("Ingrese nuevo elemento: ");
        scanf("%d", &valor);               // Leer el valor ingresado por el usuario
        insertarAlFinal(&lista, valor);    // Insertar el valor al final de la lista

        printf("¿Otro elemento (s/n)? ");
        scanf(" %c", &opcion);             // Leer opción (espacio antes de %c para evitar problemas con saltos de línea)

    } while (opcion == 's' || opcion == 'S');  // Repetir si el usuario responde 's' o 'S'

    printf("Lista enlazada: ");
    mostrarLista(lista);   // Mostrar todos los elementos de la lista
}
int main() {
    funcionPrincipal();
    return 0;
}