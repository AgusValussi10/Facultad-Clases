// Cree una función llamada factorial que calcule el factorial de un número entero positivo.
// Muestre el resultado en el main.

#include <stdio.h>  

// Declaración de funciones
int pedirNumero();          // Pide un número al usuario y lo devuelve
int factorial(int numero);  // Calcula el factorial de un número de forma recursiva
void principal();           // Función que contiene la lógica principal del programa

int main(){
    printf("\n");         // Salto de línea para estética
    principal();          // Llama a la función principal
    return 0;             // Fin del programa
}

void principal(){
    int numero = pedirNumero();          // Se guarda el número ingresado por el usuario
    int resultado = factorial(numero);   // Se calcula el factorial del número ingresado
    printf("El factorial de %d es %d\n", numero, resultado);  // Se muestra el resultado
}

int pedirNumero(){
    int num;
    printf("Ingrese un numero: ");   // Solicita al usuario que ingrese un número
    scanf("%d", &num);               // Guarda el número ingresado
    return num;                      // Retorna el número
}

int factorial(int numero){
    if (numero == 0 || numero == 1) {        // Caso base: el factorial de 0 y 1 es 1
        return 1;
    } else {
        return numero * factorial(numero - 1); // Llamada recursiva
    }
}

/*
-------------------------------------------------------
Resumen del programa:

Este programa calcula el factorial de un número ingresado por el usuario.
El factorial de un número (n!) es el producto de todos los enteros positivos desde 1 hasta n.

Funciones utilizadas:
1. pedirNumero(): solicita al usuario un número entero positivo.
2. factorial(int): calcula recursivamente el factorial del número.
3. principal(): organiza la ejecución del programa llamando a pedirNumero() y factorial().

Errores corregidos:
- En el código original se llamaba dos veces a pedirNumero(), lo que hacía que el usuario ingresara dos veces un número innecesariamente.
- No se mostraba el resultado del factorial por consola.
- Se mejoró la legibilidad al guardar los resultados en variables y luego usarlas en el `printf`.

Aprendizajes clave:
✔ Cómo usar funciones para separar lógica.
✔ Cómo implementar recursividad para cálculos matemáticos.
✔ Buenas prácticas: evitar repetir llamadas innecesarias (como pedir dos veces el mismo número).
✔ Mostrar siempre el resultado final al usuario.

-------------------------------------------------------
*/
