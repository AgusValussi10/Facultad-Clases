/*
Dada una lista doblemente encadenada
A) Ingresar por teclado la cantidad de elementos que tendra la lista.
B) Cargar la lista e indicar si se pude cargar la cantidad indicada.
C) Mostrar la lista, el contenido de la lista de adelante hacia atras y viceversa.
D) Ingresar un elemento por teclado, si es menor que el primero de la lista instertarlo adelante,
si es mayor que el ultimo de la lista insertarlo al final, en cualquier otro caso no hacer nada y emitir un mensaje por pantalla.
E) Mostrar el nuevo contenido de la lista en el sentido que corresponde con la inserccion que se hizo.
*/
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo para representar cada elemento de la lista
typedef struct Nodo {
	int dato;
	struct Nodo* siguiente;
	struct Nodo* anterior;
} Nodo;

// Definición de la estructura Lista para representar la lista doblemente enlazada
typedef struct Lista {
	Nodo* cabeza;   // Apunta al primer nodo
	Nodo* cola;     // Apunta al último nodo
	int longitud;   // Cuenta la cantidad de nodos
} Lista;

// Función para crear una nueva lista vacía
Lista* crearLista() {
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->cabeza = NULL;
	lista->cola = NULL;
	lista->longitud = 0;
	return lista;
}

// Inserta un nuevo nodo al final de la lista
void insertarAlFinal(Lista* lista, int dato) {
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	nuevoNodo->anterior = lista->cola;  // El nuevo nodo apunta hacia atrás al antiguo último

	if (lista->cola != NULL) {
		lista->cola->siguiente = nuevoNodo; // Enlaza el antiguo último al nuevo nodo
	} else {
		lista->cabeza = nuevoNodo; // Si estaba vacía, el nuevo nodo también es cabeza
	}
	lista->cola = nuevoNodo;  // El nuevo nodo ahora es la cola
	lista->longitud++;
}

// Muestra la lista desde el principio hasta el final
void mostrarListaAdelante(Lista* lista) {
	Nodo* actual = lista->cabeza;
	while (actual != NULL) {
		printf("%d ", actual->dato);
		actual = actual->siguiente;
	}
	printf("\n");
}

// Muestra la lista desde el final hacia el principio
void mostrarListaAtras(Lista* lista) {
	Nodo* actual = lista->cola;
	while (actual != NULL) {
		printf("%d ", actual->dato);
		actual = actual->anterior;
	}
	printf("\n");
}

// Inserta un nuevo nodo solo si cumple ciertas condiciones:
// al principio si es menor que el primero, o al final si es mayor que el último
void insertarSiNecesario(Lista* lista, int dato) {
	if (lista->longitud == 0 || dato < lista->cabeza->dato) {
		// Caso: insertar al principio
		Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
		nuevoNodo->dato = dato;
		nuevoNodo->siguiente = lista->cabeza;
		nuevoNodo->anterior = NULL;

		if (lista->cabeza != NULL) {
			lista->cabeza->anterior = nuevoNodo;
		} else {
			lista->cola = nuevoNodo; // Lista estaba vacía
		}
		lista->cabeza = nuevoNodo;
		lista->longitud++;
	} else if (dato > lista->cola->dato) {
		// Caso: insertar al final
		insertarAlFinal(lista, dato);
	} else {
		// No cumple ninguna condición
		printf("El elemento no se insertó porque no cumple las condiciones.\n");
	}
}

// Función principal del programa
int main() {
	Lista* lista = crearLista(); // Inicializo la lista vacía
	int cantidad, dato;
	
	// Ingreso de elementos iniciales
	printf("Ingrese la cantidad de elementos que tendrá la lista: ");
	scanf("%d", &cantidad);
	
	for (int i = 0; i < cantidad; i++) {
		printf("Ingrese el elemento %d: ", i + 1);
		scanf("%d", &dato);
		insertarAlFinal(lista, dato);  // Cargo los datos al final
	}
	
	// Verifico que se hayan cargado correctamente
	if (lista->longitud == cantidad) {
		printf("Se pudo cargar la cantidad indicada.\n");
	} else {
		printf("No se pudo cargar la cantidad indicada.\n");
	}
	
	// Mostrar el contenido en ambos sentidos
	printf("Contenido de la lista de adelante hacia atrás: ");
	mostrarListaAdelante(lista);
	
	printf("Contenido de la lista de atrás hacia adelante: ");
	mostrarListaAtras(lista);
	
	// Explico las condiciones de inserción antes de pedir un nuevo dato
	printf("\nPara insertar un nuevo elemento, debe cumplir alguna de las siguientes condiciones:\n");
	printf("- Ser menor que el primer elemento (%d), para insertarse al principio.\n", lista->cabeza->dato);
	printf("- Ser mayor que el último elemento (%d), para insertarse al final.\n", lista->cola->dato);
	
	// Intento insertar un nuevo dato si cumple las condiciones
	printf("Ingrese un elemento para insertar: ");
	scanf("%d", &dato);
	insertarSiNecesario(lista, dato);
	
	// Muestro cómo quedó la lista luego del intento de inserción
	printf("Nuevo contenido de la lista: ");
	mostrarListaAdelante(lista);
	
	// Libero toda la memoria utilizada
	Nodo* actual = lista->cabeza;
	while (actual != NULL) {
		Nodo* siguiente = actual->siguiente;
		free(actual);
		actual = siguiente;
	}
	free(lista);
	
	return 0;
}

// Use una lista doblemente enlazada para poder recorrer en ambos sentidos.
// Agregue validaciones y mensajes para que se entienda por qué un valor no se inserta.
// Limpio la memoria al final para evitar fugas
