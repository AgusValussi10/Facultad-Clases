// Implemente una función recursiva que nos diga si una cadena es palíndromo. Realizarlo solo con la liberria stdio.

#include <stdio.h>      // Librería estándar para entrada y salida
#include <string.h>     // Para funciones de manejo de cadenas como strlen y strcspn
#include <ctype.h>      // Para funciones como isalpha y tolower

// Función recursiva que verifica si una cadena es un palíndromo
int esPalindromo(char *cadena, int inicio, int fin) {
    // Caso base: si los índices se cruzan o son iguales, es un palíndromo
    if (inicio >= fin) return 1;

    // Si los caracteres en los extremos no coinciden, no es palíndromo
    if (cadena[inicio] != cadena[fin]) return 0;

    // Llamada recursiva avanzando desde ambos extremos hacia el centro
    return esPalindromo(cadena, inicio + 1, fin - 1);
}

// Función que limpia la cadena original
// Elimina espacios y convierte letras a minúsculas
void limpiarCadena(char *origen, char *limpia) {
    int j = 0;
    for (int i = 0; origen[i] != '\0'; i++) {
        // Solo se copian letras (ignora espacios, números, signos)
        if (isalpha(origen[i])) {
            // Se convierten a minúsculas para comparación uniforme
            limpia[j++] = tolower(origen[i]);
        }
    }
    // Se agrega el terminador nulo al final de la cadena limpia
    limpia[j] = '\0';
}

// Función principal del programa
void funcionPrincipal() {
    char cadena[100];  // Arreglo para almacenar la cadena ingresada por el usuario
    char limpia[100];  // Arreglo para almacenar la versión limpia de la cadena

    printf("Ingrese una cadena: ");
    // Se usa fgets para permitir el ingreso de cadenas con espacios
    fgets(cadena, sizeof(cadena), stdin);
    
    // Se elimina el salto de línea '\n' que agrega fgets
    cadena[strcspn(cadena, "\n")] = '\0';

    // Se limpia la cadena: solo letras, en minúsculas
    limpiarCadena(cadena, limpia);

    // Se calcula la longitud de la cadena limpia
    int longitud = strlen(limpia);

    // Se evalúa si la cadena limpia es un palíndromo
    if (esPalindromo(limpia, 0, longitud - 1)) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }
}

// Función principal del programa (punto de entrada)
int main() {
    funcionPrincipal();  // Llama a la función principal
    return 0;            // Fin del programa
}
