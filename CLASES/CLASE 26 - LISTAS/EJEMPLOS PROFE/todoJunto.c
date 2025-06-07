#include <stdio.h>
#include <stdlib.h>

// Definición del nodo de la lista
struct Nodo {
    int dni;               // dni que se guarda
    char nombre[50]; // Nombre del usuario (opcional, no se usa en este ejemplo)
    char apellido[50]; // Apellido del usuario (opcional, no se usa en este ejemplo)
    struct Nodo* siguiente; // Puntero al siguiente nodo
};

struct Datos{
    int dni;         
    char nombre[50]; 
    char apellido[50];
};

// Función para insertar un nodo al inicio de la lista
#include <string.h>
void insertarAlInicio(struct Nodo** cabeza, int valor, char nombre[50], char apellido[50]) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo)); // Creamos un nuevo nodo
    nuevo->dni = valor; //asignamos el valor al nuevo nodo
    strcpy(nuevo->nombre, nombre); // Copiamos el nombre al nuevo nodo
    strcpy(nuevo->apellido, apellido); // Copiamos el apellido al nuevo nodo
    nuevo->siguiente = *cabeza; // El nuevo apunta al anterior primer nodo
    *cabeza = nuevo;// Ahora el nuevo nodo es la cabeza de la lista
}

// Función para insertar un nuevo nodo al final de la lista
void insertarAlFinal(struct Nodo** cabeza, int valor,  char nombre[50], char apellido[50]) {
    // Creamos un nuevo nodo y asignamos el valor
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dni = valor;
    strcpy(nuevo->nombre, nombre); // Copiamos el nombre al nuevo nodo
    strcpy(nuevo->apellido, apellido); // Copiamos el apellido al nuevo nodo
    nuevo->siguiente = NULL; // Este nuevo nodo será el último, así que apunta a NULL

    // Si la lista está vacía, el nuevo nodo será la cabeza
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        // Si la lista ya tiene elementos, recorremos hasta el último nodo
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente; // Avanzamos hasta llegar al final
        }
        actual->siguiente = nuevo; // El último nodo apunta al nuevo
    }
}

// Función para eliminar un nodo con un valor específico
void eliminarValor(struct Nodo** cabeza, int valor) {
    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->dni == valor) {
            if (anterior == NULL) {
                // El nodo a eliminar es el primero
                *cabeza = actual->siguiente;
            } else {
                // Saltamos el nodo actual (el que vamos a eliminar)
                anterior->siguiente = actual->siguiente;
            }

            // Liberamos el nodo eliminado
            free(actual);
            printf("Valor %d eliminado de la lista.\n", valor);
            return; // Salimos después de eliminar
        }

        // Avanzamos al siguiente nodo
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si llegamos aquí, no se encontró el valor
    printf("Valor %d no encontrado en la lista.\n", valor);
}

// Función para mostrar los elementos de la lista
void mostrarLista(struct Nodo* cabeza) { // Recibe la cabeza de la lista
    printf("Elementos de la lista:\n"); // Mensaje inicial
    while (cabeza != NULL) {
        printf("%d %s %s\n", cabeza->dni,  cabeza->nombre, cabeza->apellido); // Mostramos el dni del nodo actual
        cabeza = cabeza->siguiente; // Avanzamos al siguiente nodo
    }
}

// Función para buscar un número en la lista
void buscar(struct Nodo* cabeza, int valorBuscado) {
    struct Nodo* actual = cabeza;
    int encontrado = 0;

    // Recorremos la lista nodo por nodo
    while (actual != NULL) {
        if (actual->dni == valorBuscado) {
            encontrado = 1; // Lo encontramos
            break;          // Ya no hace falta seguir buscando
        }
        actual = actual->siguiente; // Avanzamos al siguiente nodo
    }

    // Mostramos el resultado
    if (encontrado) {
        printf("Número encontrado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void mostrarMenu() {
    printf("\nMENU DE OPCIONES:\n");
    printf("  'i' - Insertar al inicio\n");
    printf("  'f' - Insertar al final\n");
    printf("  'e' - Eliminar un valor\n");
    printf("  'm' - Mostrar la lista\n");
    printf("  'b' - Buscar un valor\n");
    printf("  'n' - Salir\n");
    printf("Seleccione una opción: ");
}

int pedirNumero(){
    int numero;
    printf("Ingrese dni a buscar: ");
    scanf("%d", &numero);
    return numero;
}

struct Datos pedirDatos(){
    int dni;
    char nombre[50];
    char apellido[50];
    printf("Ingrese el DNI: ");
    scanf("%d", &dni);
    printf("Ingrese el nombre: ");
    scanf("%s", nombre); 
    printf("Ingrese el apellido: ");
    scanf("%s", apellido); 
    struct Datos datos;
    datos.dni = dni;
    strcpy(datos.nombre, nombre);
    strcpy(datos.apellido, apellido);
    return datos;
}

int main() {
    struct Nodo* lista = NULL; // Inicialmente, el nodo cabeza es NULL (lista vacía)
    char seguir = 's'; //variable de control para seguir ingresando números
    char position = 'i'; // i= insertar al inicio, f= insertar al final
    while(seguir == 's' || seguir == 'S') {
        mostrarMenu(); // Mostramos el menú de opciones
        scanf(" %c", &position); // Espacio antes de %c para ignorar espacios en blanco
        if (position == 'i') {
            struct Datos datos = pedirDatos(); // Pedimos los datos al usuario
            insertarAlInicio(&lista, datos.dni, datos.nombre, datos.apellido); // Insertamos el número al inicio
        } else if (position == 'f') {
            struct Datos datos = pedirDatos();
            insertarAlFinal(&lista, datos.dni, datos.nombre, datos.apellido); // Insertamos el número al final
        }else if (position == 'e') {
            printf("Ingrese el número a eliminar: ");
            int dniEliminar;
            scanf("%d", &dniEliminar); // Pedimos el número a eliminar
            eliminarValor(&lista, dniEliminar); // Eliminamos el número especificado
        }else if (position == 'm') {
            mostrarLista(lista); // Mostramos la lista
        }else if (position == 'b') {
            buscar(lista, pedirNumero()); // Buscamos el número especificado
        }else{
            printf("Opción no válida. Por favor, intente de nuevo.\n");
            continue; // Volver al inicio del bucle si la opción no es válida
        }
        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &seguir); // Espacio antes de %c para ignorar espacios en blanco
    }

    // Mostramos la lista resultante
    mostrarLista(lista);

    return 0;
}
