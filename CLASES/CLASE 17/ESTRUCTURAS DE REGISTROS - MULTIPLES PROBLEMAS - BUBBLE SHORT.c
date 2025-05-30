#include <stdio.h> // Inclusión de la biblioteca estándar para entrada/salida
#define ELEM 1     // Definimos una constante ELEM con valor 2 (cantidad de amigos a ingresar)

// Definición de la estructura que representa un amigo
struct estructura_amigo {
    char nombre[30];    // Nombre del amigo (máx. 29 caracteres + '\0')
    char apellido[40];  // Apellido del amigo (máx. 39 caracteres + '\0')
    char telefono[15];  // Teléfono como cadena de caracteres
    int edad;           // Edad del amigo
    int dni;            // DNI del amigo
};

int main() {
    struct estructura_amigo amigo[ELEM]; // Arreglo de estructuras para almacenar los datos
    int i, j, b;                          // Variables auxiliares para iteración y búsqueda
    int mayores = 0, menores = 0, iguales = 0; // Contadores para clasificar edades
    int edadReferencia;                  // Edad que servirá de referencia para comparación
    struct estructura_amigo aux;         // Variable auxiliar para el ordenamiento

    // Carga de datos de los amigos
    for (i = 0; i < ELEM; i++) {
        printf("Ingrese el nombre del amigo %d: ", i + 1);
        scanf("%s", amigo[i].nombre); // Se lee una palabra (sin espacios)

        printf("Ingrese el apellido del amigo %d: ", i + 1);
        scanf("%s", amigo[i].apellido); // También sin espacios

        printf("Ingrese el numero de telefono del amigo %d: ", i + 1);
        scanf("%s", amigo[i].telefono); // Teléfono como cadena (permite guiones o símbolos)

        printf("Ingrese el DNI del amigo %d: ", i + 1);
        scanf("%d", &amigo[i].dni); // Lectura de número entero

        printf("Ingrese la edad del amigo %d: ", i + 1);
        scanf("%d", &amigo[i].edad); // Lectura de número entero
    }
    // Ordenamiento de la lista con la funcion BUBBLE SORT
    // Ordenamiento de la lista de amigos por DNI en orden descendente (mayor a menor)
    for (i = 0; i < ELEM - 1; i++) {
        for (j = 0; j < ELEM - i - 1; j++) {
            if (amigo[j].dni < amigo[j + 1].dni) {
                // Intercambio usando variable auxiliar
                aux = amigo[j];
                amigo[j] = amigo[j + 1];
                amigo[j + 1] = aux;
            }
        }
    }

    // Impresión de la lista ordenada
    printf("\nLISTA DE AMIGOS ORDENADA POR DNI (MAYOR A MENOR):\n");
    printf("%-4s %-10s %-15s %-15s %-15s %-4s\n", "N°", "DNI", "NOMBRE", "APELLIDO", "TELEFONO", "EDAD");
    printf("-----------------------------------------------------------------------------\n");
    for (i = 0; i < ELEM; i++) {
        // Impresión formateada de cada amigo
        printf("%-4d %-10d %-15s %-15s %-15s %-4d\n",
            i + 1,
            amigo[i].dni,
            amigo[i].nombre,
            amigo[i].apellido,
            amigo[i].telefono,
            amigo[i].edad);
    }

    // Búsqueda de un amigo por su DNI
    printf("\nIngrese DNI para buscar: ");
    scanf("%d", &b); // Se ingresa el DNI a buscar

    i = 0;
    // Búsqueda lineal en el arreglo
    while (i < ELEM && amigo[i].dni != b) {
        i++;
    }

    // Validación del resultado de la búsqueda
    if (i == ELEM) {
        printf("No se encontro el DNI %d\n", b);
    } else {
        // Si se encuentra, se muestran todos los datos del amigo
        printf("DNI encontrado: %d\n", amigo[i].dni);
        printf("Nombre: %s %s | Telefono: %s | Edad: %d\n",
                amigo[i].nombre, amigo[i].apellido, amigo[i].telefono, amigo[i].edad);
    }

    // Comparación con una edad de referencia
    printf("\nIngrese una edad de referencia: ");
    scanf("%d", &edadReferencia);

    for (i = 0; i < ELEM; i++) {
        if (amigo[i].edad > edadReferencia) {
            mayores++; // Si la edad es mayor
        } else if (amigo[i].edad < edadReferencia) {
            menores++; // Si es menor
        } else {
            iguales++; // Si coincide con la edad ingresada
        }
    }

    // Resultados de la comparación por edad
    printf("\nNumero de amigos mayores a %d años: %d\n", edadReferencia, mayores);
    printf("Numero de amigos menores a %d años: %d\n", edadReferencia, menores);
    if (iguales > 0){
        printf("Numero de amigos con %d años: %d\n", edadReferencia, iguales);
    }
    

    return 0; // Fin del programa
}
