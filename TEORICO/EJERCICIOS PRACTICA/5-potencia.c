// Escriba una función potencia que reciba dos enteros base y exponente.
// Y que devuelva base elevado a la exponente (sin usar pow()).

#include <stdio.h>

// Declaración de funciones
int potencia(int base, int exponente);  // Función que calcula la potencia de forma manual
void principal();                       // Declaración de la función principal personalizada

int main() {
    principal(); // Llamada a la función principal
    return 0;
}

void principal() {
    int base, exponente;  // Declaración de las variables que almacenarán los valores ingresados por el usuario

    printf("Ingrese la base: ");   // Solicita la base al usuario
    scanf("%d", &base);            // Guarda el valor ingresado en la variable 'base'

    // Solicita el exponente al usuario
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);       // Guarda el valor ingresado en la variable 'exponente'

    // Llama a la función potencia con base y exponente, luego imprime el resultado
    printf("%d elevado a %d es %d\n", base, exponente, potencia(base, exponente));
}

int potencia(int base, int exponente) {
    int resultado = 1;  // Variable para acumular el resultado. Se inicializa en 1 (identidad multiplicativa)

    // Bucle que multiplica 'base' por sí misma 'exponente' veces
    for (int i = 0; i < exponente; i++) {
        resultado *= base;  // Se acumula la multiplicación sucesiva
    }

    return resultado;  // Devuelve el resultado final
}

/*
-------------------------------------------------------
Resumen del programa:

Este programa solicita al usuario una base y un exponente, luego calcula
la potencia sin usar la función pow() de math.h. Utiliza una estructura simple con bucles.

Aprendizajes clave:
✔ Cómo implementar una función manual de potencia.
✔ Uso correcto de funciones para organizar el código.
✔ Buenas prácticas: no incluir funciones innecesarias ni llamadas redundantes.

Errores corregidos:
- Se eliminó una función `numero()` sin propósito claro.
- Se cambió el tipo de retorno de `principal()` a `void`.
- Se mejoraron los nombres, declaraciones y comentarios para mayor claridad.

Extras que podrías agregar:
✔ Validar que el exponente sea >= 0.
✔ Soporte para exponentes negativos (con resultados en coma flotante, si usás `float` o `double`).

-------------------------------------------------------
*/
