/* 
Crear un programa que permita al usuario insertar números enteros en una lista enlazada, al inicio de la lista. 
Luego, mostrar todos los elementos. El usuario puede agregar elementos mientras lo necesite. 
EJEMPLO:
Ingrese nuevo elemento: 20
Otro elemento (s/n)? s
Ingrese nuevo elemento: 50
Otro elemento (s/n)? n
20 -> 50
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
struct Nodo {
	int dato;                  // Dato que almacena el nodo
	struct Nodo* siguiente;    // Puntero al siguiente nodo en la lista
};

// Función para insertar un nuevo nodo al inicio de la lista
void insertarAlInicio(struct Nodo** cabeza, int valor) {
	// Reserva de memoria para el nuevo nodo
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;            // Asignar el valor al nuevo nodo
	nuevoNodo->siguiente = *cabeza;     // El nuevo nodo apunta al nodo actual cabeza
	*cabeza = nuevoNodo;                // Actualizar la cabeza para que sea el nuevo nodo
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
void funcionPrincipal(){
    struct Nodo* lista = NULL;  // Inicialización de la lista como vacía
	int valor;
	char opcion;

	do {
		printf("Ingrese nuevo elemento: ");
		scanf("%d", &valor);               // Leer el valor ingresado por el usuario
		insertarAlInicio(&lista, valor);   // Insertar el valor al inicio de la lista

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



